#!/usr/bin/env python3
"""Generate schema 1.2.6: the second retune of the 150+ trash monsters, and its rollback.

    ./tools/gen_high_level_retune.py        writes db/migrations/1.2.6_HighLevelMonsterRetune2.sql
                                            and    db/rollback/1.2.6_HighLevelMonsterRetune2_rollback.sql

Reads the current MonsterInfo rows (SELECT only) with the credentials in conf/gameserver.local.conf, so the
migration is guarded on each row's current Enhance string and the rollback restores exactly those strings.

Why. 1.2.0 aimed each generic monster at a night vampire (Defense x1.5 at night) and at 35 melee hits per
kill, 15% DECREASEDAMAGE on top. Against a slayer or ousters of the content's level every one of these
monsters still hits at the 95% cap at night (hit chance is 50 + (ToHit - Defense)/3), a landed hit is 25-50%
of the character's HP, they swing every 0.75-1.3 s, and a trash kill takes 25-50 hits once Protection
(up to 49%) and DECREASEDAMAGE have taken their cut. That is the "too tanky, hit too hard, too often" feel.

Model. The reference character is a slayer of the content's level with 3 attribute points per level split
STR/DEX (340/340 at 150, +2 per level to 200, +2.5 after), no gear: HP = 3*STR + 5*Level (Blade/Sword
domain 150 plus advancement levels), Defense = DEX/2, Protection = STR (up to 640 caps the cut at 80%).
Per generic monster, at night (monster ToHit and damage at 100%; by day they are halved):

    ToHit            reference Defense + 50                 -> lands about 67% at night, 30% by day
    max hit          6% of the reference HP after Protection, with MONSTER_DAMAGE_RATIO 120% included
    min hit          the same enhance as max (the base formulas keep their ratio)
    HP               15 everyday hits: (0.42*STR_ref + 30) after a 22% Protection cut, times 15,
                     with MONSTER_HP_RATIO 90% included
    Protection       capped at 180 (a 22% cut) - only lowered, never raised
    DECREASEDAMAGE   0 (was 15)
    attack delay     at least 1200 ms (ADelay column; MonsterAI adds 0-200 ms on top)
    DEFENSE, NEXTRATIO and everything else in the string are carried over verbatim.

EXP does not move: kill EXP is (STR+DEX+INT) x level factor x (1 + Exp/100) and Enhance never enters it.
Only the curve's kills-per-minute assumption changes (tools/gen_exp_curve.py bands after 150).

Untouched: Hell Garden 5F, the floor bosses and minibosses (Master rows), the key monsters 917-921, the
[14]/Chief wave rows, Tiffauges bosses and clones, Ruper's Gentis dungeon, Vlad II Dracul, and the 130-149
tier (IK Labs, Hillanom, Adam's Holy Land 2), which is already in range.
"""
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "db"))
import dbconn  # noqa: E402

MIGRATION = os.path.join(ROOT, "db", "migrations", "1.2.6_HighLevelMonsterRetune2.sql")
ROLLBACK = os.path.join(ROOT, "db", "rollback", "1.2.6_HighLevelMonsterRetune2_rollback.sql")

# ---------------------------------------------------------------- targets
HIT_CHANCE_MARGIN = 50        # monster ToHit = reference Defense + this  (67% at night)
HIT_SHARE = 0.06              # a landed max hit takes this share of the reference HP
HITS_TO_KILL = 15             # everyday player hits per trash monster
PLAYER_PROT_CUT = 0.22        # the Protection cut the reference player suffers after this retune
PROTECTION_CAP = 180          # monster Protection is lowered to this where it is higher
DECREASE_DAMAGE = 0
ADELAY_FLOOR = 1200
MONSTER_DAMAGE_RATIO = 1.20   # AttrInfo 108
MONSTER_HP_RATIO = 0.90       # AttrInfo 104

# (zone label, reference level, MTypes).  Chiefs/masters are skipped even if listed.
GROUPS = [
    ("Hell Garden 1F", 150, [821, 822, 823, 826, 827, 828, 829, 830, 831, 832, 833, 834, 835]),
    ("Hell Garden 2F", 170, [842, 843, 844, 846, 847, 848, 849, 851, 852]),
    ("Hell Garden 3F", 190, list(range(853, 869))),
    ("Hell Garden 4F", 210, [869, 870, 871, 874, 875, 877] + list(range(882, 890))),
    ("Tiffauges 1F", 165, [1032, 1033, 1034, 1039]),
    ("Junje Tunnel 1F", 170, [774, 775]),
    ("Junje Tunnel 2F", 190, [771, 772]),
    ("Ruper Island", 190, [1152, 1153, 1154, 1155, 1156]),
    ("Dracula Castle", 240, [1195, 1197, 1198, 1199, 1200, 1201]),
]

ENH = re.compile(r"\(\s*([A-Z_]+)\s*,\s*\+?(-?\d+)\s*\)")


def read_conf():
    conf = {}
    with open(os.path.join(ROOT, "conf", "gameserver.local.conf"), "rb") as f:
        for raw in f:
            line = raw.decode("latin1").strip()
            if line and not line.startswith("#") and ":" in line:
                k, v = line.split(":", 1)
                conf[k.strip()] = v.strip()
    return conf


def db_rows():
    conf = read_conf()

    class Args:
        host = conf.get("DB_HOST", "127.0.0.1"); port = int(conf.get("DB_PORT", "3306"))
        user = conf.get("DB_USER", "elcastle"); password = conf.get("DB_PASSWORD"); db = conf.get("DB_DB", "DARKEDEN")
    my = dbconn.MySQL(Args)
    types = sorted({m for _, _, ms in GROUPS for m in ms})
    rows = my.query("SELECT MType, EName, Level, STR, DEX, INTE, ADelay, IFNULL(Enhance,''), Master, Chief "
                    "FROM MonsterInfo WHERE MType IN (%s)" % ",".join(str(t) for t in types))
    out = {}
    for r in rows:
        out[int(r[0])] = dict(name=r[1], lvl=int(r[2]), str=int(r[3]), dex=int(r[4]), int=int(r[5]),
                              adelay=int(r[6]), enh=r[7], master=int(r[8]), chief=int(r[9]))
    return out


def parse(enh):
    d, order = {}, []
    for k, v in ENH.findall(enh):
        if k == "DEFENCE":            # misspelling the parser ignores; treat as DEFENSE
            k = "DEFENSE"
        d[k] = int(v); order.append(k)
    return d


def fmt(d):
    keys = ["HP", "TOHIT", "DEFENSE", "PROTECTION", "MINDAMAGE", "MAXDAMAGE", "DECREASEDAMAGE"]
    rest = [k for k in d if k not in keys]
    return "".join("(%s,%d)" % (k, d[k]) for k in keys + rest if k in d)


def reference(L):
    stat = 340 + 2 * min(max(L - 150, 0), 50) + 2.5 * max(L - 200, 0)
    hp = 3 * stat + 5 * L
    prot_cut = min(stat, 640) / 8 / 100
    return dict(stat=stat, hp=hp, defense=stat / 2, prot_cut=prot_cut, hit=(0.42 * stat + 30) * (1 - PLAYER_PROT_CUT))


def retune(row, L):
    ref = reference(L)
    e = parse(row["enh"])
    lvl, STR, DEX = row["lvl"], row["str"], row["dex"]
    new = dict(e)
    # ToHit
    base_tohit = (DEX / 2.0) * (1 + lvl / 100.0)
    new["TOHIT"] = round((ref["defense"] + HIT_CHANCE_MARGIN) / base_tohit * 100 - 100)
    # damage
    base_max = STR / (4.0 - lvl / 100.0)
    raw_max = HIT_SHARE * ref["hp"] / (1 - ref["prot_cut"]) / MONSTER_DAMAGE_RATIO
    dmg = round(raw_max / base_max * 100 - 100)
    new["MAXDAMAGE"] = dmg
    new["MINDAMAGE"] = dmg
    new.pop("DAMAGE", None)
    # HP
    base_hp = STR * (2.0 + lvl / 100.0) * MONSTER_HP_RATIO
    new["HP"] = round(HITS_TO_KILL * ref["hit"] / base_hp * 100 - 100)
    # protection
    base_prot = STR / (5.0 - lvl / 100.0)
    cur_prot = base_prot * (1 + e.get("PROTECTION", 0) / 100.0)
    if cur_prot > PROTECTION_CAP:
        new["PROTECTION"] = round(PROTECTION_CAP / base_prot * 100 - 100)
    new["DECREASEDAMAGE"] = DECREASE_DAMAGE
    adelay = max(row["adelay"], ADELAY_FLOOR)
    # the resulting numbers, for the comment
    hp = int(base_hp * (1 + new["HP"] / 100.0))
    tohit = int(base_tohit * (1 + new["TOHIT"] / 100.0))
    mx = int(base_max * (1 + dmg / 100.0) * MONSTER_DAMAGE_RATIO)
    prot = int(base_prot * (1 + new.get("PROTECTION", 0) / 100.0))
    chance = max(5, min(95, int(50 + (tohit - ref["defense"]) / 3)))
    landed = int(mx * (1 - ref["prot_cut"]))
    return fmt(new), adelay, dict(hp=hp, tohit=tohit, mx=mx, prot=prot, chance=chance, landed=landed,
                                   share=landed / ref["hp"] * 100, hits=hp / ref["hit"])


def q(s):
    return "'" + s.replace("\\", "\\\\").replace("'", "''") + "'"


def main():
    rows = db_rows()
    mig = ["""-- 1.2.6_HighLevelMonsterRetune2.sql
--
-- Second retune of the generic 150+ monsters (Hell Garden 1F-4F, Tiffauges 1F, Junje Tunnel, Ruper Island,
-- Dracula Castle): they hit at the 95% cap, took a quarter to half of a level-appropriate character's HP
-- per hit, swung every 0.75-1.3 s and needed 25-50 hits to kill. Now, against a slayer of the content's
-- level at night: about 67% to hit (30% by day), a max hit of about 6% of HP, a swing every 1.2 s or
-- slower, and about 15 everyday hits per kill. Protection is capped at 180 and DECREASEDAMAGE goes from
-- 15 to 0. EXP per kill does not change (Enhance is not part of the EXP formula).
--
-- Written by tools/gen_high_level_retune.py, which holds the reference model and the targets; the numbers
-- in each comment are what the row produces (HP, ToHit / hit chance, max hit landed on the reference
-- character and its share of that character's HP, hits to kill).
--
-- Ships with script/zone/Tiffauges/Tiffauges1F_O_MonsterInfo.lua (past-world 1F HP enhance +100 -> +10).
-- No gameserver code change. MonsterInfo is read at boot: restart the gameserver after running this.
-- Every UPDATE is guarded on the current or the new values, so the file is safe to run twice.
-- Rollback: db/rollback/1.2.6_HighLevelMonsterRetune2_rollback.sql (the "was" values below).

SET NAMES utf8mb4;
"""]
    rb = ["""-- 1.2.6_HighLevelMonsterRetune2_rollback.sql
--
-- Undo db/migrations/1.2.6_HighLevelMonsterRetune2.sql: every row gets its previous Enhance string and
-- ADelay back. NOT a migration - run by hand, then restart the gameserver:
--     mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.2.6_HighLevelMonsterRetune2_rollback.sql
-- Also put (HP,100) back in script/zone/Tiffauges/Tiffauges1F_O_MonsterInfo.lua (git checkout).
-- Removes the 1.2.6 SchemaVersion row; deploy_db.py would re-apply it unless the file is removed first.

SET NAMES utf8mb4;
"""]
    summary = []
    for label, L, types in GROUPS:
        mig.append("-- %s (reference level %d)" % (label, L))
        for m in types:
            row = rows.get(m)
            if row is None or row["master"] or row["chief"]:
                continue
            new, adelay, r = retune(row, L)
            if new == row["enh"] and adelay == row["adelay"]:
                continue
            mig.append("-- %d %s: HP %d, ToHit %d (%d%%), max hit %d landed = %d%% of HP, %.0f hits to kill, ADelay %d"
                       % (m, row["name"], r["hp"], r["tohit"], r["chance"], r["landed"], r["share"], r["hits"], adelay))
            mig.append("--   was %s ADelay %d" % (row["enh"] or "(none)", row["adelay"]))
            mig.append("UPDATE `MonsterInfo` SET `Enhance` = %s, `ADelay` = %d WHERE `MType` = %d AND `Enhance` IN (%s, %s) AND `ADelay` IN (%d, %d);"
                       % (q(new), adelay, m, q(row["enh"]), q(new), row["adelay"], adelay))
            rb.append("UPDATE `MonsterInfo` SET `Enhance` = %s, `ADelay` = %d WHERE `MType` = %d AND `Enhance` = %s;"
                      % (q(row["enh"]), row["adelay"], m, q(new)))
            summary.append((label, m, row["name"], r))
        mig.append("")
    rb.append("\nDELETE FROM `SchemaVersion` WHERE `Major` = 1 AND `Minor` = 2 AND `Bug` = 6;")
    os.makedirs(os.path.dirname(ROLLBACK), exist_ok=True)
    open(MIGRATION, "w", encoding="utf-8", newline="\n").write("\n".join(mig))
    open(ROLLBACK, "w", encoding="utf-8", newline="\n").write("\n".join(rb) + "\n")
    print("wrote", os.path.relpath(MIGRATION, ROOT), "(%d rows)" % len(summary))
    print("wrote", os.path.relpath(ROLLBACK, ROOT))
    print("%-16s %5s %-26s %6s %6s %5s %6s %5s %5s" % ("zone", "type", "name", "HP", "ToHit", "hit%", "maxHit", "%HP", "hits"))
    for label, m, name, r in summary:
        print("%-16s %5d %-26s %6d %6d %5d %6d %5.0f %5.0f" % (label, m, name[:26], r["hp"], r["tohit"], r["chance"], r["landed"], r["share"], r["hits"]))


if __name__ == "__main__":
    main()
