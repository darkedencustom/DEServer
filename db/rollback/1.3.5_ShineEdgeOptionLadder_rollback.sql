-- 1.3.5_ShineEdgeOptionLadder_rollback.sql
--
-- Undo db/migrations/1.3.5_ShineEdgeOptionLadder.sql: the seven OptionInfo rows go back to their
-- pre-1.3.5 values, so Shine/Edge again stop at LUCK+3, RES+5 and ATTR+3 and RES+6 is a dead end.
-- NOT a migration - run by hand, then restart the gameserver:
--     mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.3.5_ShineEdgeOptionLadder_rollback.sql
-- Options players already upgraded along the restored ladder keep their new tier.
-- Removes the 1.3.5 SchemaVersion row; deploy_db.py would re-apply it unless the file is removed first.

SET NAMES utf8mb4;

UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0                            WHERE `OptionType` = 176;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0   WHERE `OptionType` = 177;
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0                            WHERE `OptionType` = 181;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0   WHERE `OptionType` = 182;
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0                            WHERE `OptionType` = 184;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0   WHERE `OptionType` = 185;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0                            WHERE `OptionType` = 208;
DELETE FROM `SchemaVersion` WHERE `Major` = 1 AND `Minor` = 3 AND `Bug` = 5;
