-- 1.3.2_PetExpRate.sql
--
-- Pets level 100 times faster.
--
-- AttrInfo 81 is VariableManager PET_EXP_RATIO, a percentage (its `comm` text, "Event Lucky Bag", is wrong).
-- It scales both ways a pet earns EXP:
--   * EffectHasPet: every minute a summoned, fed pet gets 12 EXP (20 for premium players);
--   * CGDissectionCorpseHandler: each corpse the pet loots gives computePetExp(), 7-13 halved to 3-6 for
--     non-paying players, x10/7 on monsters 20+ levels above the owner, /10 on monsters 20+ levels below.
-- The pet's own attacks add a flat 1-2 EXP per hit, which this ratio does not touch.
--
-- At 100% a pet earned roughly 2,000 EXP an hour (700 passive + looting), so level 10 (71,880 total) took
-- about 35 hours and level 49 (13.9 M) thousands. At 10000% the passive part alone is 72,000 an hour:
-- level 10 in about an hour, 30 in about 35 hours, 49 in about 190 hours, and looting with the pet out
-- shortens those a good deal. Unchanged: a pet without an attribute still stops at level 10 (the EXP past
-- that is dropped until it gets one), and level 50 is still the cap.
--
-- Read at gameserver boot (VariableManager::load replays AttrInfo over the code defaults): restart the
-- gameserver after running this. A GOD-level GM can also change it live with `*set PET_EXP_RATIO <percent>`,
-- which writes this same row.
--
-- Rollback: UPDATE AttrInfo SET attr1 = 100 WHERE attrID = 81;

SET NAMES utf8mb4;

UPDATE AttrInfo SET attr1 = 10000 WHERE attrID = 81 AND attr1 IN (100, 10000);
