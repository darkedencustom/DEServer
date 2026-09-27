-- 1.2.5_PermanentQuestRewards.sql
--
-- Quest reward items no longer expire.
--
-- The NPC mission quests (InitSimpleQuest / InitEventQuest triggers - Chris, Amata, Kaiser, Rebecca,
-- Lavia, ...) build their reward lists in SimpleQuestRewardManager::load() from ItemRewardInfo and
-- SlayerWeaponRewardInfo, and ItemRewardInfo::giveReward() calls addTimeLimitItem() with TimeLimitSec
-- whenever it is non-zero. Every reward row carried 2-4 hours, so the item vanished shortly after the
-- quest paid out. TimeLimitSec = 0 hands the item over with no expiry.
--
-- ItemRewardInfo.TimeLimit (read by RewardClassInfoManager) is already 0 everywhere; it is zeroed here
-- too so neither column can bring a limit back.
--
-- Ships with the SimpleGQuest.xml change (every GiveItem limitedtime removed) and the gameserver change
-- that drops the hard-coded 7-day limit on the event-quest lottery prize (CGLotterySelectHandler.cpp,
-- ActionRewardEventQuest.cpp). Reward lists are read when NPCs are initialised at boot: restart the
-- gameserver after running this. Items already handed out keep their existing expiry.
--
-- The same gameserver change flags every quest reward CREATE_TYPE_GAME, so shops pay 1 gold for it.
-- Timed items always sold for 50; once permanent, the ItemLevel-255 top rewards (placeholder Price
-- 999999 / 9999999) would sell for 250K-2.5M each from a repeatable quest.
--
-- Guarded on the current value, so the file is safe to run twice.
--
-- Rollback (the original limits follow RewardClass exactly):
--   UPDATE ItemRewardInfo SET TimeLimitSec = 7200  WHERE RewardClass IN (2,3,22,23,24,89,90);
--   UPDATE ItemRewardInfo SET TimeLimitSec = 9600  WHERE RewardClass IN (5,6,8,9,11,12,14,15,17,18,25,26,27,28,
--          29,30,31,32,33,34,35,36,37,38,39,92,93,95,96,98,99,101,102,104,105);
--   UPDATE ItemRewardInfo SET TimeLimitSec = 14400 WHERE RewardClass IN (20,21,40,41,42,107,108);
--   UPDATE SlayerWeaponRewardInfo SET TimeLimitSec = 7200  WHERE RewardClass IN (1,88);
--   UPDATE SlayerWeaponRewardInfo SET TimeLimitSec = 9600  WHERE RewardClass IN (4,7,10,13,16,91,94,97,100,103);
--   UPDATE SlayerWeaponRewardInfo SET TimeLimitSec = 14400 WHERE RewardClass IN (19,106);

SET NAMES utf8mb4;

-- 170 rows: 31 x 7200, 118 x 9600, 21 x 14400
UPDATE ItemRewardInfo SET TimeLimitSec = 0, TimeLimit = 0 WHERE TimeLimitSec <> 0 OR TimeLimit <> 0;

-- 63 rows: 9 x 7200, 45 x 9600, 9 x 14400
UPDATE SlayerWeaponRewardInfo SET TimeLimitSec = 0 WHERE TimeLimitSec <> 0;
