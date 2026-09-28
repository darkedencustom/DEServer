-- 1.3.3_GQuestMissionSave.sql
--
-- KAN-13: active quests are retained on logout.
--
-- Until now GQuestSave only ever held COMPLETE / FAIL / CAN_REPLAY rows: a quest in progress
-- (DOING, or SUCCESS with its reward still pending) lived in gameserver memory and vanished
-- with the PlayerCreature at logout. Worse, quests whose Happen block is a level window
-- (101: offered at level <= 3, done at level 6; 102, 104, 202, 203, 204, 303, 304...) were
-- lost for good if the player logged out inside the window and came back above it.
--
-- From this schema on the gameserver
--   * writes the DOING / SUCCESS status to GQuestSave when a quest is accepted, on every
--     mission update, and at logout;
--   * writes one row per mission to this new table (kill counters and the monsters picked
--     for the quest, NPC-met / pet-tamed / waypoint flags, travel route, death counter...),
--     and reloads them at login (GQuestManager::load -> GQuestStatus::restoreMission);
--   * clears the rows when the quest completes, fails, or is cancelled.
--
-- Columns
--   Cond      which section of the quest XML the mission belongs to
--             (0 Happen, 1 Complete, 2 Fail, 3 Reward = GQuestInfo::ElementType)
--   Position  0-based index of the element inside that section
--   Status    MissionInfo::Status (1 CURRENT, 2 SUCCESS, 3 FAIL)
--   NumArg / StrArg   the two values the client is shown (kill count, travel list...)
--   State     element-specific progress, see GQuestMissionState.h
--
-- The same change removes every <Time> element from data/SimpleGQuest.xml (21 fail conditions
-- across the level-up, blood-drain, skill, pet, hunting and waypoint quests), so no quest has
-- a time limit any more; the job advancement quests never had one.
--
-- latin1 on purpose: StrArg carries CP949 zone names, byte for byte like every other Name column.
--
-- Rollback: DROP TABLE GQuestMissionSave;
--           DELETE FROM GQuestSave WHERE Status IN (2, 3);   -- a pre-1.3.3 gameserver mishandles DOING rows

SET NAMES utf8mb4;

CREATE TABLE IF NOT EXISTS `GQuestMissionSave` (
  `OwnerID`  varchar(32)       NOT NULL DEFAULT '',
  `QuestID`  smallint unsigned NOT NULL DEFAULT '0',
  `Cond`     tinyint unsigned  NOT NULL DEFAULT '0',
  `Position` smallint unsigned NOT NULL DEFAULT '0',
  `Status`   tinyint unsigned  NOT NULL DEFAULT '0',
  `NumArg`   int unsigned      NOT NULL DEFAULT '0',
  `StrArg`   varchar(255)      NOT NULL DEFAULT '',
  `State`    varchar(255)      NOT NULL DEFAULT '',
  PRIMARY KEY (`OwnerID`, `QuestID`, `Cond`, `Position`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1
  COMMENT='missions of quests in progress, one row each; written by the gameserver (KAN-13)';
