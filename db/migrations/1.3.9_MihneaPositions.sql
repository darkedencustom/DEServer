-- 1.3.9_MihneaPositions.sql
--
-- Dracula Castle 1F: move Mihnea's Storage to 107/132 and the Mihnea Altar to 207/45 (user placement after
-- seeing 1.3.8's 103/134 and 204/47 in game). Only the AtFirst SetPosition triggers change; the NPC rows,
-- dialogue triggers and Script rows from 1.3.8 stay as they are.

SET NAMES utf8mb4;

UPDATE `Triggers`
   SET `Actions` = 'ActionType : SetPosition\n\t\tZoneID : 6051\n\t\tX : 107\n\t\tY : 132\n\t\tDir : 2'
 WHERE `NPC` = 'Mihnea Storage' AND `Conditions` = 'ConditionType : AtFirst';

UPDATE `Triggers`
   SET `Actions` = 'ActionType : SetPosition\n\t\tZoneID : 6051\n\t\tX : 207\n\t\tY : 45\n\t\tDir : 2'
 WHERE `NPC` = 'Mihnea Altar' AND `Conditions` = 'ConditionType : AtFirst';
