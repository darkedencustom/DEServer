-- 1.3.18 Vlad II Dracul (1196) retune for the 2F lair
-- v9's row was a raw import: DEX 2000 gave him to-hit/defense 3550 (both over their caps), (TOHIT,800) and
-- (DEFENSE,100) on top, (PROTECTION,1500) = the 80% cut cap, (DECREASEDAMAGE,99) = players deal 1%, and his three
-- skills scale with DEX (Talon 0.2x, Bloody Scarify 2 0.8x = 1600 raw, Bloody Carpe 0.6x). A level-183 vampire
-- died in three hits and could not land one.
-- Reference character for THIS server (the user's, 2026-09-30): vampire, level 183, STR 444, DEX 104, HP 3423,
-- at night -> to-hit 221, defense 111, protection 601 (75% cut).
-- Targets (formulas in AbilityBalance.cpp, Level 255 -> x3.55 on DEX/2, MONSTER ratios 90% HP / 120% damage;
-- Enhance percentages may be negative: x += getPercentValue(x, enhance)):
--   to-hit 200  (~80% on that character), defense 226 (that character hits ~48%), protection 204 (25% cut),
--   melee 348-827 raw x1.2 -> 87-207 taken = 2.5-6% of its HP per hit, skills 150/600/450 raw (Scarify ~150 taken),
--   HP 51,187 (STR 2500 x 4.55 x 5 x 0.9), players' damage cut by 55%.
--   Five such characters kill him in about 4-5 minutes; alone it takes ~20 minutes and he kills one in ~25 s.
-- was: DEX 2000, Enhance (HP,400)(TOHIT,800)(DEFENSE,100)(PROTECTION,1500)(DECREASEDAMAGE,99)(NEXTRATIO,0)
-- (the first draft of this file set DEX 800 / (TOHIT,-70)(DEFENSE,-55)(PROTECTION,-70)(DAMAGE,-40)(DECREASEDAMAGE,50),
--  tuned to a 450 STR/DEX character; the WHERE accepts that state too)
UPDATE MonsterInfo
   SET DEX = 750,
       Enhance = '(HP,400)(TOHIT,-85)(DEFENSE,-83)(PROTECTION,-80)(DAMAGE,-60)(DECREASEDAMAGE,55)(NEXTRATIO,0)'
 WHERE MType = 1196
   AND ( (DEX = 2000 AND Enhance = '(HP,400)(TOHIT,800)(DEFENSE,100)(PROTECTION,1500)(DECREASEDAMAGE,99)(NEXTRATIO,0)')
      OR (DEX = 800  AND Enhance = '(HP,400)(TOHIT,-70)(DEFENSE,-55)(PROTECTION,-70)(DAMAGE,-40)(DECREASEDAMAGE,50)(NEXTRATIO,0)') );
