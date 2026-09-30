-- 1.3.10_MihneaClickToUse.sql
--
-- Dracula Castle: Mihnea's Storage and the Mihnea Altar are objects, not talking NPCs (user, 2026-09-30: "they
-- work like the Blood Bible altars"). Clicking them now acts at once - TakeMihnea on the storage, PlaceMihnea on
-- the altar - with no dialogue window: the TalkedBy trigger runs the action directly and the Ask / AnsweredBy
-- rows from 1.3.8 go away. The actions answer with a system message (the seal still holds / you take the
-- Mihnea / you are not carrying it / you place it) and close any dialogue the client may have opened.
-- Script rows 20301/20302 stay in the table but are no longer referenced.

SET NAMES utf8mb4;

DELETE FROM `Triggers`
 WHERE `NPC` IN ('Mihnea Storage', 'Mihnea Altar')
   AND (`Conditions` LIKE 'ConditionType : TalkedBy%' OR `Conditions` LIKE 'ConditionType : AnsweredBy%');

INSERT INTO `Triggers` (`TriggerType`, `NPC`, `QuestID`, `Conditions`, `Actions`)
VALUES
    ('NPC', 'Mihnea Storage', 0, 'ConditionType : TalkedBy', 'ActionType : TakeMihnea'),
    ('NPC', 'Mihnea Altar',   0, 'ConditionType : TalkedBy', 'ActionType : PlaceMihnea');
