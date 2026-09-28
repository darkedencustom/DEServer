-- 1.3.4_BurnedOriginalBook_rollback.sql
--
-- Undo db/migrations/1.3.4_BurnedOriginalBook.sql: CommonQuestItem 53 goes away again.
-- NOT a migration - run by hand, then restart the gameserver:
--     mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.3.4_BurnedOriginalBook_rollback.sql
-- Books players already hold would lose their info row, so delete those objects first (below).
-- The gameserver's level 150+ roll checks for the row and stops dropping once it is gone.
-- Removes the 1.3.4 SchemaVersion row; deploy_db.py would re-apply it unless the file is removed first.

SET NAMES utf8mb4;

DELETE FROM `CommonQuestItemObject` WHERE `ItemType` = 53;
DELETE FROM `CommonQuestItemInfo`   WHERE `ItemType` = 53;
DELETE FROM `SchemaVersion`         WHERE `Major` = 1 AND `Minor` = 3 AND `Bug` = 4;
