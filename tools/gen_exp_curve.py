#!/usr/bin/env python3
"""Generate the schema 1.3.0 EXP curve migration and its rollback.

    ./tools/gen_exp_curve.py            writes db/migrations/1.3.0_ExpCurve.sql
                                        and    db/rollback/1.3.0_ExpCurve_rollback.sql

Needs no database access: everything the migration writes is computed here, and the rollback restores
from the backup tables the migration itself creates (ExpCurve130_Backup_*), so it puts back whatever
THAT database had, not what this generator assumed.

What the curve is
-----------------
The tables set a *time per level* and turn it into EXP with the EXP a character of that level earns per
kill at the zones it normally farms, so the pace is the same wherever the player is on the curve:

    goal(L) = minutes(L) * kills_per_minute(L) * exp_per_kill(L)

Targets agreed on 2026-09-27: roughly 50 hours solo, daytime, no party, from 1 to 150, and about 120
hours from 151 to 250 (the advancement cap) - approximations, erring on the generous side -
levelling 150-160 in IK Labs / Hillanom Shrine / Adam's Holy Land 2, then Tiffauges 1F, Ruper Island
and Dracula's Castle, with Hell Garden as the faster paid route.

  * levels 1-35 keep the original GoalExp rows (one kill is several levels until about 20, level 30
    is about 7 kills), levels 36-45 blend geometrically from those into the model, 46+ is the model:
  * minutes(L), 1..149:  0.25 + k * ((L-1)/148)^1.4, k chosen so the sum is 50 h (level 100 about 27
    minutes, level 149 about 48 minutes).
  * minutes(L), 151..249: a linear ramp from about 43 to 103 minutes whose sum is 120 h.
  * kills per minute: 4.0 (1-19), 3.0 (20-49), 2.5 (50-99), 2.0 (100-149), 1.5 (150-169), 1.3 (170-199),
    1.0 (200+).  Guesses; they scale the hours, not the shape.
  * the Rodin Intensification family gets Exp 400 (x5) and the red Chiefs Exp 200 (x3); neither is in
    the reference curve (Rodin is a notch above it on purpose, chiefs are rare timed spawns).
  * exp_per_kill: E_PROP[L] below is the reference monster base EXP,
        (STR+DEX+INT) * (0.75 + Level/200) * (1 + Exp/100)          -- computeMonsterExp()
    the spawn-weighted median of the field/dungeon monsters at that level (ZoneInfo x MonsterInfo), with
    the Exp 300 boost this migration gives the level 130-149 tier, then Hell Garden 2F-4F / Dracula
    Castle from 161.  A vampire or ousters kill is worth E * 130% (MONSTER_EXP_RATIO) * 100 (EXP_RATIO
    10000 with EVENT_ACTIVE 1, applied as a percentage); advancement EXP is 1% of that, then x100 again,
    so E * 1.3 per kill.
  * slayers level per skill cast (SkillBalance.Point, x100): the domain table uses
        (15 casts/min * SKILL_PTS[L] + 30 melee hits) * 100
    where SKILL_PTS is the median Point of the three newest everyday attack skills at that domain level,
    averaged over Blade/Sword/Gun.  At 130-149 the target monsters carry Exp 300, and increaseDomainExp()
    multiplies the points by (1 + Exp/100 * 0.5) = 2.5 for them, so those rows are 2.5x.

Rows kept as they are: level 0 of every skill domain (new characters start with the column defaults
50/40/30 that match it), the 2,000,000,000 sentinel at vampire/ousters level 150, and the AccumExp
convention (domain and advancement tables end at exactly 2,000,000,000 so nothing overflows the 32-bit
Exp_t the server loads them into; today's advancement rows 79-100 do overflow).
"""
import math
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
MIGRATION = os.path.join(ROOT, "db", "migrations", "1.3.0_ExpCurve.sql")
ROLLBACK = os.path.join(ROOT, "db", "rollback", "1.3.0_ExpCurve_rollback.sql")

# ---------------------------------------------------------------- parameters
HOURS_TO_150 = 50.0
T_MIN = 0.25
SHAPE = 1.4
POST_HOURS = 120.0
POST_RATIO = 2.4
BANDS = [(1, 19, 4.0), (20, 49, 3.0), (50, 99, 2.5), (100, 149, 2.0), (150, 169, 1.5), (170, 199, 1.3), (200, 250, 1.0)]
CASTS_PER_MIN = 15.0
MELEE_PER_MIN = 30.0
WEAPON_FACTOR = 1.0
MONSTER_EXP_RATIO = 1.30
EVENT_MULT = 100
TIER_LO, TIER_HI = 130, 149
TIER_SLAYER_FACTOR = 2.5          # increaseDomainExp(): 1 + 300/100 * 0.5 while the target carries Exp 300
SENTINEL = 2_000_000_000

# The early game keeps the tables it had: the original GoalExp values are used through KEEP_OLD_UPTO and
# blend geometrically into the time model over the next BLEND_LEVELS levels (old and new cross at about
# level 40 anyway). One kill is several levels until about 20 and level 30 is about 7 kills, as before.
KEEP_OLD_UPTO = 35
BLEND_LEVELS = 10
OLD_VAMP_GOALS = {1: 125, 2: 163, 3: 211, 4: 274, 5: 357, 6: 465, 7: 603, 8: 784, 9: 1020, 10: 1325, 11: 1724, 12: 2240, 13: 2912, 14: 3786, 15: 4922, 16: 6398, 17: 8318, 18: 10813, 19: 14057, 20: 18274, 21: 22842, 22: 28553, 23: 35692, 24: 44614, 25: 55768, 26: 63000, 27: 73000, 28: 85000, 29: 96000, 30: 116000, 31: 139000, 32: 156000, 33: 186000, 34: 212000, 35: 242000, 36: 279000, 37: 322000, 38: 375000, 39: 428000, 40: 488000, 41: 551000, 42: 611000, 43: 680000, 44: 756000, 45: 826000}
OLD_DOMAIN_GOALS = {
    0: {1: 60, 2: 90, 3: 150, 4: 250, 5: 400, 6: 610, 7: 890, 8: 1250, 9: 1700, 10: 2250, 11: 2910, 12: 3690, 13: 4600, 14: 5650, 15: 6850, 16: 8210, 17: 9740, 18: 11450, 19: 13350, 20: 15450, 21: 17760, 22: 20290, 23: 23050, 24: 26050, 25: 29300, 26: 32810, 27: 36590, 28: 40650, 29: 45000, 30: 49650, 31: 54610, 32: 59890, 33: 65500, 34: 71450, 35: 77750, 36: 84410, 37: 91440, 38: 98850, 39: 106650, 40: 114850, 41: 123460, 42: 132490, 43: 141950, 44: 151850, 45: 162200},
    1: {1: 60, 2: 90, 3: 150, 4: 250, 5: 400, 6: 610, 7: 890, 8: 1250, 9: 1700, 10: 2250, 11: 2910, 12: 3690, 13: 4600, 14: 5650, 15: 6850, 16: 8210, 17: 9740, 18: 11450, 19: 13350, 20: 15450, 21: 17760, 22: 20290, 23: 23050, 24: 26050, 25: 29300, 26: 32810, 27: 36590, 28: 40650, 29: 45000, 30: 49650, 31: 54610, 32: 59890, 33: 65500, 34: 71450, 35: 77750, 36: 84410, 37: 91440, 38: 98850, 39: 106650, 40: 114850, 41: 123460, 42: 132490, 43: 141950, 44: 151850, 45: 162200},
    2: {1: 50, 2: 80, 3: 140, 4: 240, 5: 390, 6: 600, 7: 880, 8: 1240, 9: 1690, 10: 2240, 11: 2900, 12: 3680, 13: 4590, 14: 5640, 15: 6840, 16: 8200, 17: 9730, 18: 11440, 19: 13340, 20: 15440, 21: 17750, 22: 20280, 23: 23040, 24: 26040, 25: 29290, 26: 32800, 27: 36580, 28: 40640, 29: 44990, 30: 49640, 31: 54600, 32: 59880, 33: 65490, 34: 71440, 35: 77740, 36: 84400, 37: 91430, 38: 98840, 39: 106640, 40: 114840, 41: 123450, 42: 132480, 43: 141940, 44: 151840, 45: 162190},
    3: {1: 40, 2: 70, 3: 130, 4: 230, 5: 380, 6: 590, 7: 870, 8: 1230, 9: 1680, 10: 2230, 11: 2890, 12: 3670, 13: 4580, 14: 5630, 15: 6830, 16: 8190, 17: 9720, 18: 11430, 19: 13330, 20: 15430, 21: 17740, 22: 20270, 23: 23030, 24: 26030, 25: 29280, 26: 32790, 27: 36570, 28: 40630, 29: 44980, 30: 49630, 31: 54590, 32: 59870, 33: 65480, 34: 71430, 35: 77730, 36: 84390, 37: 91420, 38: 98830, 39: 106630, 40: 114830, 41: 123440, 42: 132470, 43: 141930, 44: 151830, 45: 162180},
    4: {1: 40, 2: 70, 3: 130, 4: 230, 5: 380, 6: 590, 7: 870, 8: 1230, 9: 1680, 10: 2230, 11: 2890, 12: 3670, 13: 4580, 14: 5630, 15: 6830, 16: 8190, 17: 9720, 18: 11430, 19: 13330, 20: 15430, 21: 17740, 22: 20270, 23: 23030, 24: 26030, 25: 29280, 26: 32790, 27: 36570, 28: 40630, 29: 44980, 30: 49630, 31: 54590, 32: 59870, 33: 65480, 34: 71430, 35: 77730, 36: 84390, 37: 91420, 38: 98830, 39: 106630, 40: 114830, 41: 123440, 42: 132470, 43: 141930, 44: 151830, 45: 162180},
}

# Reference monster base EXP per character level 1..250 (index 0 = level 1); see the module docstring.
E_PROP = [22, 22, 27, 34, 41, 48, 58, 64, 68, 73, 78, 80, 82, 82, 82, 84, 88, 92, 96, 100, 102, 103, 104, 106, 112,
          119, 124, 130, 135, 135, 135, 138, 142, 145, 152, 159, 163, 166, 170, 174, 179, 182, 186, 190, 190, 190,
          193, 196, 199, 206, 214, 218, 223, 227, 231, 235, 240, 244, 248, 248, 248, 251, 253, 256, 266, 275, 283,
          290, 297, 297, 297, 299, 301, 303, 305, 307, 307, 352, 397, 441, 486, 531, 531, 531, 531, 531, 531, 539,
          547, 555, 555, 555, 555, 555, 555, 555, 555, 555, 555, 555, 555, 607, 665, 728, 793, 799, 805, 811, 812,
          825, 838, 858, 879, 900, 909, 917, 920, 923, 937, 954, 970, 985, 1000, 1003, 1003, 1008, 1019, 1030, 1040,
          4216, 4250, 4294, 4337, 4399, 4450, 4502, 4591, 4681, 4751, 4866, 4980, 5024, 5073, 5117, 5180, 5243,
          5329, 5377, 5465, 4957, 4981, 5006, 5031, 5056, 5081, 5105, 5130, 5155, 5180, 5205, 15000, 15119, 15237,
          15356, 15475, 15593, 15712, 15831, 15950, 16068, 16187, 16306, 16424, 16543, 16662, 16780, 16899, 17018,
          17137, 17255, 17413, 17570, 17728, 17885, 18043, 18200, 18357, 18515, 18672, 18830, 18966, 19101, 19237,
          19373, 19508, 19644, 19780, 19916, 20051, 20187, 20331, 20474, 20618, 20761, 20905, 21048, 21192, 21335,
          21479, 21622, 21823, 22023, 22223, 22424, 22624, 22824, 23024, 23224, 23425, 23625, 23845, 24065, 24284,
          24504, 24724, 24944, 25163, 25383, 25603, 25823, 25721, 25620, 25518, 25417, 25315, 25214, 25112, 25011,
          24909, 24808, 25280, 25751, 26223, 26695, 27167, 27638, 28110, 28582, 29053, 29525]

# Median Point of the three newest everyday attack skills at domain level 1..149, Blade/Sword/Gun averaged.
SKILL_PTS = [6] * 34 + [6.3] * 5 + [7.3] * 5 + [8.7] * 2 + [9.3] * 3 + [10.3] * 3 + [13.7] * 2 + [15] * 6 + [16] * 9 + \
            [17.3] * 30 + [19.3] * 10 + [21] * 10 + [31] * 10 + [32.7] * 19 + [36.3]

# Regular level 130-149 monsters (plus the whole Rodin "Intensification" family, levels 120-165, so that zone
# stays consistent) that get Exp 300.  Chiefs, masters, siege objects and the Hell Garden tower fodder are not in.
TIER_MONSTERS = (list(range(493, 503))        # Lich Jel [14]
                 + list(range(624, 634))      # Ash Balog [14]
                 + [718]                      # Blunt Crag [14]
                 + [754]                      # Rum Guarder [14]
                 + list(range(755, 764))      # Icy Ruffian [14]
                 + [778, 779, 786])           # Tug Legger, Roi Cadavru, Oberst [14]
RODIN_MONSTERS = list(range(894, 908))        # Intensification family (levels 120-165): Exp 400, x5, a notch above the tier
RUPER_MONSTERS = [1152, 1153, 1154, 1155, 1156]   # Bifronze, Palus, Garum, Clavie, Lycan Wolfarch
# The red Chief set (and the three older chiefs left out of the Superior rename) never had an EXP bonus; they
# get Exp 200 (x3) like the Superiors, so a 30-minute chief spawn is worth chasing. The curve ignores them.
RED_CHIEFS = [461, 463, 477] + list(range(564, 604))

assert len(E_PROP) == 250 and len(SKILL_PTS) == 149


# ---------------------------------------------------------------- the curve
def rate(L):
    for a, b, r in BANDS:
        if a <= L <= b:
            return r
    return BANDS[-1][2]


def minutes_pre(L):
    s = sum(((l - 1) / 148) ** SHAPE for l in range(1, 150))
    k = (HOURS_TO_150 * 60 - T_MIN * 149) / s
    return T_MIN + k * ((L - 1) / 148) ** SHAPE


def minutes_post(L):
    n = L - 150
    if n < 1 or n > 99:
        return None
    avg = POST_HOURS * 60 / 99
    s = 2 * avg / (1 + POST_RATIO)
    e = POST_RATIO * s
    return s + (e - s) * (n - 1) / 98


def e_vamp(L):
    return E_PROP[L - 1] * MONSTER_EXP_RATIO * EVENT_MULT


def e_adv(L):
    return E_PROP[L - 1] * MONSTER_EXP_RATIO


def slayer_pts_per_min(L):
    return (CASTS_PER_MIN * SKILL_PTS[L - 1] + MELEE_PER_MIN) * WEAPON_FACTOR


def blend(old, new, L):
    """old through KEEP_OLD_UPTO, geometric blend over the next BLEND_LEVELS, new after."""
    if L <= KEEP_OLD_UPTO:
        return old
    if L > KEEP_OLD_UPTO + BLEND_LEVELS:
        return new
    f = (L - KEEP_OLD_UPTO) / BLEND_LEVELS
    return math.exp(math.log(old) * (1 - f) + math.log(new) * f)


def vamp_goals():
    """{level: goal} for 1..149; 150 keeps the sentinel."""
    g = {}
    for L in range(1, 150):
        model = minutes_pre(L) * rate(L) * e_vamp(L)
        g[L] = round(blend(OLD_VAMP_GOALS[L], model, L) if L in OLD_VAMP_GOALS else model)
    g[150] = SENTINEL
    return g


def domain_goals(d=0):
    """{level: goal} for 1..149 of skill domain d (the model is the same; only the kept early rows differ)."""
    g = {}
    for L in range(1, 150):
        v = minutes_pre(L) * slayer_pts_per_min(L) * EVENT_MULT
        if TIER_LO <= L <= TIER_HI:
            v *= TIER_SLAYER_FACTOR
        g[L] = round(blend(OLD_DOMAIN_GOALS[d][L], v, L) if L in OLD_DOMAIN_GOALS[d] else v)
    return g


def adv_goals():
    """{advancement level: goal} for 1..99; 100 is the cap."""
    return {L - 150: round(minutes_post(L) * rate(L) * e_adv(L)) for L in range(151, 250)}


def accumulate(goals, start_accum, levels):
    acc, out = start_accum, {}
    for L in levels:
        acc += goals[L]
        out[L] = acc
    return out


# ---------------------------------------------------------------- SQL
def header_migration():
    return """-- 1.3.0_ExpCurve.sql
--
-- New EXP curve: roughly 50 hours from level 1 to 150 and about 120 hours from 151 to 250, for every race.
--
-- Why. The level tables grew about a million times from level 1 to 149 while monster EXP grows about
-- 60x, so levels 140-149 alone were 700 M of the 1.34 B a vampire needed, and the advancement table
-- (fed with 1% of the kill EXP) asked 15 M for its first level and 19.5 B for its last - rows 79-100
-- even overflow the 32-bit Exp_t the server loads them into. Slayers, who level per skill cast, needed
-- about 270 M domain EXP. Every race now follows one time-per-level profile; the numbers and how they
-- were derived are in tools/gen_exp_curve.py, which wrote this file.
--
-- What changes.
--   1. VampEXPBalanceInfo / OustersEXPBalanceInfo levels 36-149 (150 keeps the 2,000,000,000 sentinel);
--      levels 1-35 keep their original values so the early game plays as before, 36-45 blend into the curve.
--   2. SkillDomainInfo domains 0-4 (Blade, Sword, Gun, Heal, Enchant) levels 36-150 (1-35 original, 36-45 blend); level 0 is untouched
--      because new characters start with the matching column defaults. Domains 5-7 are not touched.
--   3. AdvancementClassEXPInfo levels 1-100 (character levels 151-250).
--   4. Characters keep their levels; their remaining GoalExp columns are clamped to the new goal for
--      their level (Vampire.GoalExp, Ousters.GoalExp, Slayer.*GoalExp, *.AdvancementGoalExp), so nobody
--      is left needing more than the new table asks.
--   5. MonsterInfo.Exp = 300 (a x4 EXP bonus) on the regular level 130-149 monsters: Lich Jel, Ash
--      Balog, Blunt Crag, Rum Guarder, Icy Ruffian, Tug Legger, Roi Cadavru, Oberst. That makes IK Labs,
--      Hillanom Shrine and Adam's Holy Land 2 the 150-160 zones; Hell Garden 1F (Exp 800) stays about
--      2.3x faster. The 130-149 rows of the tables above are built on the boosted values. Rodin's
--      Intensification family (894-907) gets Exp 400 (x5), a notch above the tier. Ruper Island trash
--      (1152-1156) goes from Exp 100 to 400 so it sits on the curve next to Hell Garden 3F. Dracula's
--      Castle is already on it.
--   6. The red Chief set (564-603) and chiefs 461, 463, 477 get Exp 200 (x3), the bonus the Superior
--      chiefs already have; until now they paid only what their base stats were worth.
--
-- Ships with script/zone/Tiffauges/Tiffauges1F_R_MonsterInfo.lua giving the present-world 1F spawns
-- (EXP,200); the past-world script keeps its (EXP,400), so the past stays about 1.7x the present as it
-- does on 2F. No gameserver code change. The tables are read at boot: restart the gameserver after
-- running this.
--
-- Rollback: db/rollback/1.3.0_ExpCurve_rollback.sql. It restores every table and every character's
-- goal columns from the ExpCurve130_Backup_* tables this file creates first, so keep those tables until
-- the curve has been live for a while. Safe to run twice: the backups only fill in on the first run
-- (INSERT IGNORE on a primary key), every UPDATE sets an absolute value, and the Exp changes are guarded.

SET NAMES utf8mb4;
"""


def sql_backups():
    out = ["-- 0. Backups for the rollback (first run only; INSERT IGNORE leaves existing rows alone)."]
    out.append("""CREATE TABLE IF NOT EXISTS `ExpCurve130_Backup_VampEXPBalanceInfo` (
  `Level` int NOT NULL, `GoalExp` int NOT NULL, `AccumExp` bigint NOT NULL, PRIMARY KEY (`Level`)
) ENGINE=InnoDB COMMENT='pre-1.3.0 VampEXPBalanceInfo, for db/rollback/1.3.0_ExpCurve_rollback.sql';
INSERT IGNORE INTO `ExpCurve130_Backup_VampEXPBalanceInfo` (`Level`, `GoalExp`, `AccumExp`)
  SELECT `Level`, `GoalExp`, `AccumExp` FROM `VampEXPBalanceInfo`;

CREATE TABLE IF NOT EXISTS `ExpCurve130_Backup_OustersEXPBalanceInfo` (
  `Level` int NOT NULL, `GoalExp` int NOT NULL, `AccumExp` bigint NOT NULL, PRIMARY KEY (`Level`)
) ENGINE=InnoDB COMMENT='pre-1.3.0 OustersEXPBalanceInfo, for db/rollback/1.3.0_ExpCurve_rollback.sql';
INSERT IGNORE INTO `ExpCurve130_Backup_OustersEXPBalanceInfo` (`Level`, `GoalExp`, `AccumExp`)
  SELECT `Level`, `GoalExp`, `AccumExp` FROM `OustersEXPBalanceInfo`;

CREATE TABLE IF NOT EXISTS `ExpCurve130_Backup_SkillDomainInfo` (
  `DomainType` int NOT NULL, `Level` int NOT NULL, `GoalExp` int NOT NULL, `AccumExp` int NOT NULL,
  PRIMARY KEY (`DomainType`, `Level`)
) ENGINE=InnoDB COMMENT='pre-1.3.0 SkillDomainInfo, for db/rollback/1.3.0_ExpCurve_rollback.sql';
INSERT IGNORE INTO `ExpCurve130_Backup_SkillDomainInfo` (`DomainType`, `Level`, `GoalExp`, `AccumExp`)
  SELECT `DomainType`, `Level`, `GoalExp`, `AccumExp` FROM `SkillDomainInfo`;

CREATE TABLE IF NOT EXISTS `ExpCurve130_Backup_AdvancementClassEXPInfo` (
  `Level` int NOT NULL, `GoalExp` bigint NOT NULL, `AccumExp` bigint NOT NULL, PRIMARY KEY (`Level`)
) ENGINE=InnoDB COMMENT='pre-1.3.0 AdvancementClassEXPInfo, for db/rollback/1.3.0_ExpCurve_rollback.sql';
INSERT IGNORE INTO `ExpCurve130_Backup_AdvancementClassEXPInfo` (`Level`, `GoalExp`, `AccumExp`)
  SELECT `Level`, `GoalExp`, `AccumExp` FROM `AdvancementClassEXPInfo`;

CREATE TABLE IF NOT EXISTS `ExpCurve130_Backup_CharGoals` (
  `Race` enum('SLAYER','VAMPIRE','OUSTERS') NOT NULL, `CharID` int unsigned NOT NULL,
  `GoalExp` bigint NOT NULL DEFAULT 0, `AdvancementGoalExp` bigint NOT NULL DEFAULT 0,
  `BladeGoalExp` bigint NOT NULL DEFAULT 0, `SwordGoalExp` bigint NOT NULL DEFAULT 0,
  `GunGoalExp` bigint NOT NULL DEFAULT 0, `HealGoalExp` bigint NOT NULL DEFAULT 0,
  `EnchantGoalExp` bigint NOT NULL DEFAULT 0,
  PRIMARY KEY (`Race`, `CharID`)
) ENGINE=InnoDB COMMENT='pre-1.3.0 remaining GoalExp per character, for db/rollback/1.3.0_ExpCurve_rollback.sql';
INSERT IGNORE INTO `ExpCurve130_Backup_CharGoals`
  (`Race`, `CharID`, `GoalExp`, `AdvancementGoalExp`, `BladeGoalExp`, `SwordGoalExp`, `GunGoalExp`, `HealGoalExp`, `EnchantGoalExp`)
  SELECT 'SLAYER', `CharID`, 0, `AdvancementGoalExp`, `BladeGoalExp`, `SwordGoalExp`, `GunGoalExp`, `HealGoalExp`, `EnchantGoalExp`
  FROM `Slayer` WHERE `Race` = 'SLAYER';
INSERT IGNORE INTO `ExpCurve130_Backup_CharGoals` (`Race`, `CharID`, `GoalExp`, `AdvancementGoalExp`)
  SELECT 'VAMPIRE', `CharID`, `GoalExp`, `AdvancementGoalExp` FROM `Vampire`;
INSERT IGNORE INTO `ExpCurve130_Backup_CharGoals` (`Race`, `CharID`, `GoalExp`, `AdvancementGoalExp`)
  SELECT 'OUSTERS', `CharID`, `GoalExp`, `AdvancementGoalExp` FROM `Ousters`;
""")
    return "\n".join(out)


def sql_tables():
    out = []
    vg = vamp_goals()
    va = accumulate(vg, 0, range(1, 151))
    out.append("-- 1. Vampire and Ousters level tables (levels 1-149 new, 150 keeps the sentinel; AccumExp = running sum).")
    for L in range(1, 151):
        out.append("UPDATE `VampEXPBalanceInfo` SET `GoalExp` = %d, `AccumExp` = %d WHERE `Level` = %d;" % (vg[L], va[L], L))
    out.append("")
    for L in range(1, 151):
        out.append("UPDATE `OustersEXPBalanceInfo` SET `GoalExp` = %d, `AccumExp` = %d WHERE `Level` = %d;" % (vg[L], va[L], L))
    out.append("")

    out.append("-- 2. Slayer skill-domain tables, domains 0-4, levels 1-150. Level 0 is left as it is (its GoalExp is the")
    out.append("--    column default new characters start with); AccumExp restarts from that row's value. Level 150 is")
    out.append("--    the max domain level: its GoalExp tops the running sum up to exactly 2,000,000,000 as before.")
    level0 = {0: 50, 1: 50, 2: 40, 3: 30, 4: 30}     # today's level-0 GoalExp (= AccumExp) per domain; untouched
    for d in range(5):
        dg = domain_goals(d)
        acc = level0[d]
        for L in range(1, 150):
            acc += dg[L]
            out.append("UPDATE `SkillDomainInfo` SET `GoalExp` = %d, `AccumExp` = %d WHERE `DomainType` = %d AND `Level` = %d;" % (dg[L], acc, d, L))
        top = SENTINEL - acc
        out.append("UPDATE `SkillDomainInfo` SET `GoalExp` = %d, `AccumExp` = %d WHERE `DomainType` = %d AND `Level` = 150;" % (top, SENTINEL, d))
        out.append("")

    ag = adv_goals()
    out.append("-- 3. Advancement table (advancement level n = character level 150+n; 100 is the cap, its GoalExp tops the")
    out.append("--    running sum up to exactly 2,000,000,000 so nothing exceeds 32 bits). Level 0 stays 0/0.")
    acc = 0
    for n in range(1, 100):
        acc += ag[n]
        out.append("UPDATE `AdvancementClassEXPInfo` SET `GoalExp` = %d, `AccumExp` = %d WHERE `Level` = %d;" % (ag[n], acc, n))
    out.append("UPDATE `AdvancementClassEXPInfo` SET `GoalExp` = %d, `AccumExp` = %d WHERE `Level` = 100;" % (SENTINEL - acc, SENTINEL))
    out.append("")
    return "\n".join(out)


def sql_characters():
    return """-- 4. Characters keep their level; the remaining EXP to the next level can only shrink.
UPDATE `Vampire` v JOIN `VampEXPBalanceInfo` e ON e.`Level` = v.`Level`
  SET v.`GoalExp` = LEAST(v.`GoalExp`, e.`GoalExp`);
UPDATE `Ousters` o JOIN `OustersEXPBalanceInfo` e ON e.`Level` = o.`Level`
  SET o.`GoalExp` = LEAST(o.`GoalExp`, e.`GoalExp`);
UPDATE `Slayer` s JOIN `SkillDomainInfo` d ON d.`DomainType` = 0 AND d.`Level` = s.`BladeLevel`
  SET s.`BladeGoalExp` = LEAST(s.`BladeGoalExp`, d.`GoalExp`) WHERE s.`Race` = 'SLAYER';
UPDATE `Slayer` s JOIN `SkillDomainInfo` d ON d.`DomainType` = 1 AND d.`Level` = s.`SwordLevel`
  SET s.`SwordGoalExp` = LEAST(s.`SwordGoalExp`, d.`GoalExp`) WHERE s.`Race` = 'SLAYER';
UPDATE `Slayer` s JOIN `SkillDomainInfo` d ON d.`DomainType` = 2 AND d.`Level` = s.`GunLevel`
  SET s.`GunGoalExp` = LEAST(s.`GunGoalExp`, d.`GoalExp`) WHERE s.`Race` = 'SLAYER';
UPDATE `Slayer` s JOIN `SkillDomainInfo` d ON d.`DomainType` = 3 AND d.`Level` = s.`HealLevel`
  SET s.`HealGoalExp` = LEAST(s.`HealGoalExp`, d.`GoalExp`) WHERE s.`Race` = 'SLAYER';
UPDATE `Slayer` s JOIN `SkillDomainInfo` d ON d.`DomainType` = 4 AND d.`Level` = s.`EnchantLevel`
  SET s.`EnchantGoalExp` = LEAST(s.`EnchantGoalExp`, d.`GoalExp`) WHERE s.`Race` = 'SLAYER';
UPDATE `Slayer` s JOIN `AdvancementClassEXPInfo` a ON a.`Level` = s.`AdvancementClass`
  SET s.`AdvancementGoalExp` = LEAST(s.`AdvancementGoalExp`, a.`GoalExp`) WHERE s.`Race` = 'SLAYER';
UPDATE `Vampire` v JOIN `AdvancementClassEXPInfo` a ON a.`Level` = v.`AdvancementClass`
  SET v.`AdvancementGoalExp` = LEAST(v.`AdvancementGoalExp`, a.`GoalExp`);
UPDATE `Ousters` o JOIN `AdvancementClassEXPInfo` a ON a.`Level` = o.`AdvancementClass`
  SET o.`AdvancementGoalExp` = LEAST(o.`AdvancementGoalExp`, a.`GoalExp`);
"""


def sql_monsters():
    tier = ",".join(str(m) for m in TIER_MONSTERS)
    rodin = ",".join(str(m) for m in RODIN_MONSTERS)
    ruper = ",".join(str(m) for m in RUPER_MONSTERS)
    chiefs = ",".join(str(m) for m in RED_CHIEFS)
    return """-- 5. Monster EXP bonuses (MonsterInfo.Exp is a percentage: 300 = x4). Guarded on the old or new value.
UPDATE `MonsterInfo` SET `Exp` = 300 WHERE `MType` IN (%s) AND `Exp` IN (0, 300);
UPDATE `MonsterInfo` SET `Exp` = 400 WHERE `MType` IN (%s) AND `Exp` IN (0, 400);
UPDATE `MonsterInfo` SET `Exp` = 400 WHERE `MType` IN (%s) AND `Exp` IN (100, 400);
UPDATE `MonsterInfo` SET `Exp` = 200 WHERE `MType` IN (%s) AND `Exp` IN (0, 200);
""" % (tier, rodin, ruper, chiefs)


def rollback_sql():
    tier = ",".join(str(m) for m in TIER_MONSTERS)
    rodin = ",".join(str(m) for m in RODIN_MONSTERS)
    ruper = ",".join(str(m) for m in RUPER_MONSTERS)
    chiefs = ",".join(str(m) for m in RED_CHIEFS)
    return """-- 1.3.0_ExpCurve_rollback.sql
--
-- Undo db/migrations/1.3.0_ExpCurve.sql. NOT a migration: deploy_db.py never runs this. Run it by hand
-- against the same database, then restart the gameserver:
--
--     mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.3.0_ExpCurve_rollback.sql
--
-- It restores the four EXP tables and every character's remaining-GoalExp columns from the
-- ExpCurve130_Backup_* tables the migration created, puts the monster Exp bonuses back, and removes the
-- 1.3.0 row from SchemaVersion so the database reports 1.2.5 again. (deploy_db.py would then re-apply
-- 1.3.0 on the next deploy: delete or rename the migration file too if the rollback is meant to stick.)
--
-- Characters get back exactly the remaining EXP they had when the migration ran, so progress made under
-- the new curve is lost, not converted. Characters created after the migration are not in the backup and
-- keep their current GoalExp; with the old tables that is less than a level's worth, so they simply
-- level up on their next kill.
--
-- Safe to run twice. Fails with "table doesn't exist" if the backup tables were dropped; there is no
-- other copy of the old values.

SET NAMES utf8mb4;

UPDATE `VampEXPBalanceInfo` e JOIN `ExpCurve130_Backup_VampEXPBalanceInfo` b ON b.`Level` = e.`Level`
  SET e.`GoalExp` = b.`GoalExp`, e.`AccumExp` = b.`AccumExp`;
UPDATE `OustersEXPBalanceInfo` e JOIN `ExpCurve130_Backup_OustersEXPBalanceInfo` b ON b.`Level` = e.`Level`
  SET e.`GoalExp` = b.`GoalExp`, e.`AccumExp` = b.`AccumExp`;
UPDATE `SkillDomainInfo` d JOIN `ExpCurve130_Backup_SkillDomainInfo` b ON b.`DomainType` = d.`DomainType` AND b.`Level` = d.`Level`
  SET d.`GoalExp` = b.`GoalExp`, d.`AccumExp` = b.`AccumExp`;
UPDATE `AdvancementClassEXPInfo` a JOIN `ExpCurve130_Backup_AdvancementClassEXPInfo` b ON b.`Level` = a.`Level`
  SET a.`GoalExp` = b.`GoalExp`, a.`AccumExp` = b.`AccumExp`;

UPDATE `Vampire` v JOIN `ExpCurve130_Backup_CharGoals` b ON b.`Race` = 'VAMPIRE' AND b.`CharID` = v.`CharID`
  SET v.`GoalExp` = b.`GoalExp`, v.`AdvancementGoalExp` = b.`AdvancementGoalExp`;
UPDATE `Ousters` o JOIN `ExpCurve130_Backup_CharGoals` b ON b.`Race` = 'OUSTERS' AND b.`CharID` = o.`CharID`
  SET o.`GoalExp` = b.`GoalExp`, o.`AdvancementGoalExp` = b.`AdvancementGoalExp`;
UPDATE `Slayer` s JOIN `ExpCurve130_Backup_CharGoals` b ON b.`Race` = 'SLAYER' AND b.`CharID` = s.`CharID`
  SET s.`BladeGoalExp` = b.`BladeGoalExp`, s.`SwordGoalExp` = b.`SwordGoalExp`, s.`GunGoalExp` = b.`GunGoalExp`,
      s.`HealGoalExp` = b.`HealGoalExp`, s.`EnchantGoalExp` = b.`EnchantGoalExp`,
      s.`AdvancementGoalExp` = b.`AdvancementGoalExp`;

UPDATE `MonsterInfo` SET `Exp` = 0   WHERE `MType` IN (%s) AND `Exp` = 300;
UPDATE `MonsterInfo` SET `Exp` = 0   WHERE `MType` IN (%s) AND `Exp` = 400;
UPDATE `MonsterInfo` SET `Exp` = 100 WHERE `MType` IN (%s) AND `Exp` = 400;
UPDATE `MonsterInfo` SET `Exp` = 0   WHERE `MType` IN (%s) AND `Exp` = 200;

DELETE FROM `SchemaVersion` WHERE `Major` = 1 AND `Minor` = 3 AND `Bug` = 0;

-- Once the rollback is confirmed and the backups are no longer wanted:
-- DROP TABLE `ExpCurve130_Backup_VampEXPBalanceInfo`, `ExpCurve130_Backup_OustersEXPBalanceInfo`,
--            `ExpCurve130_Backup_SkillDomainInfo`, `ExpCurve130_Backup_AdvancementClassEXPInfo`,
--            `ExpCurve130_Backup_CharGoals`;
""" % (tier, rodin, ruper, chiefs)


def summary():
    vg, dg, ag = vamp_goals(), domain_goals(), adv_goals()
    pre_min = sum(minutes_pre(L) for L in range(1, 150))
    post_min = sum(minutes_post(L) for L in range(151, 250))
    lines = ["level  vamp/ousters goal   slayer domain goal   minutes",
             *("%5d %18s %20s %9.1f" % (L, format(vg[L], ","), format(dg[L], ","), minutes_pre(L))
               for L in (1, 10, 30, 50, 75, 100, 125, 140, 149)),
             "adv    goal (character level 150+n)   minutes",
             *("%5d %18s %9.1f" % (n, format(ag[n], ","), minutes_post(150 + n)) for n in (1, 10, 30, 50, 75, 99)),
             "total 1->150: %s EXP, %.1f h; slayer %s domain EXP; 151->250: %s EXP, %.1f h" % (
                 format(sum(vg[L] for L in range(1, 150)), ","), pre_min / 60,
                 format(sum(dg.values()), ","), format(sum(ag.values()), ","), post_min / 60)]
    return "\n".join(lines)


def main():
    os.makedirs(os.path.dirname(ROLLBACK), exist_ok=True)
    with open(MIGRATION, "w", encoding="utf-8", newline="\n") as f:
        f.write(header_migration() + "\n" + sql_backups() + "\n" + sql_tables() + "\n" + sql_characters() + "\n" + sql_monsters())
    with open(ROLLBACK, "w", encoding="utf-8", newline="\n") as f:
        f.write(rollback_sql())
    print("wrote", os.path.relpath(MIGRATION, ROOT))
    print("wrote", os.path.relpath(ROLLBACK, ROOT))
    print(summary())


if __name__ == "__main__":
    main()
