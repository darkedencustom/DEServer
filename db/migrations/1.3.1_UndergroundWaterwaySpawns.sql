-- 1.3.1_UndergroundWaterwaySpawns.sql
--
-- The Underground Waterway (zone 1001, slayers_training.smp) becomes a level 35-45 hunting ground.
--
-- Before: 423 level 1-14 monsters (Kid 171, Turning Soul 114, Soldier 81, Alcan 57) plus 21 chiefs
-- (10 Chief Kid, 10 Chief Turning Soul, 1 Chief Alcan) - starter monsters packed one per 72 walkable
-- tiles, far denser than any field zone. New slayers start in Eslania NW (zone 12), not here, and no
-- quest or script names this zone's monsters, so the starter mobs are not needed here.
--
-- After, in ZoneInfo.MonsterList (refills by sprite; each sprite below has only these ten identical
-- NormalRegen rows, so the refill cannot pick anything else):
--
--   monster          level  types                 count
--   Hoble [4]        35     165, 167-175          70
--   Big Fang [3]     38     240-249               80
--   Blood Warlock [4] 40    28, 83-91             70
--   Golemer [4]      45     104, 111-119          60
--
-- 280 monsters on the zone's 30,421 walkable tiles is one per 109 tiles: a bit denser than the
-- level 35-45 field zones (Eslania NE/SE, Limbo Lair NW, Drobeta NE: one per 120-180), since this is
-- meant as a levelling spot.
--
-- EventMonsterList: the red chief of each monster, two apiece on the usual 1800-second regen
-- (579 Chief Hoble, 580 Chief Big Fang, 581 Chief Warlock, 582 Chief Golemer; Exp 200 since 1.3.0),
-- the same chiefs Eslania, Limbo Lair and Drobeta pair with these monsters. The zone's Ore node
-- (660, ten of them) stays.
--
-- Comments inside the lists have no '(' or ',': the parsers read everything between '(' and ')' as an
-- entry.
--
-- Ships with a client change that is not part of this file: the zone's minimap file
-- (Release\Data\map\slayers_training.mip) rebuilt from the server .smp/.ssi so the three guild portals
-- (Soldier 2000, Cleric 2010, Warrior 2020) and the real slayer safe zones show.
--
-- The game server reads ZoneInfo at startup: restart it after this runs.
-- Safe to run twice: each UPDATE only matches the row while it still holds the old list.
-- Rollback: db/rollback/1.3.1_UndergroundWaterwaySpawns_rollback.sql.

SET NAMES utf8mb4;

UPDATE `ZoneInfo`
   SET `MonsterList` = CONCAT(
         '#Hoble lv35 ',         '(165,7)(167,7)(168,7)(169,7)(170,7)(171,7)(172,7)(173,7)(174,7)(175,7)', CHAR(10),
         '#Big Fang lv38 ',      '(240,8)(241,8)(242,8)(243,8)(244,8)(245,8)(246,8)(247,8)(248,8)(249,8)', CHAR(10),
         '#Blood Warlock lv40 ', '(28,7)(83,7)(84,7)(85,7)(86,7)(87,7)(88,7)(89,7)(90,7)(91,7)', CHAR(10),
         '#Golemer lv45 ',       '(104,6)(111,6)(112,6)(113,6)(114,6)(115,6)(116,6)(117,6)(118,6)(119,6)', CHAR(10))
 WHERE `ZoneID` = 1001
   AND `MonsterList` LIKE '%( 6,9)( 47,9)( 48,90)%';

UPDATE `ZoneInfo`
   SET `EventMonsterList` = CONCAT(
         '#Ore ',                 '(660,10,1)', CHAR(10),
         '#Chief Hoble ',         '(579,2,1800)', CHAR(10),
         '#Chief Big Fang ',      '(580,2,1800)', CHAR(10),
         '#Chief Warlock ',       '(581,2,1800)', CHAR(10),
         '#Chief Golemer ',       '(582,2,1800)', CHAR(10))
 WHERE `ZoneID` = 1001
   AND `EventMonsterList` LIKE '%( 567,10,1800)%';
