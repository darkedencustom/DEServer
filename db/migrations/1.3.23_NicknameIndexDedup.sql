-- 1.3.23 NicknameIndex held every row twice, the skeleton's copy too. The game
-- server builds each character's level nicknames from it at login
-- (LevelNickInfoManager), so every level nickname reached the client's
-- nickname list twice. Keep one row per nickname and give the table a primary
-- key so a second copy can't be inserted again. Safe to rerun.
SET NAMES utf8mb4;

-- one row per (NickType, Race, Level10, NickIndex)
DROP TEMPORARY TABLE IF EXISTS `NicknameIndex_one`;
CREATE TEMPORARY TABLE `NicknameIndex_one` AS
	SELECT `NickIndex`, MIN(`Nickname`) AS `Nickname`, `NickType`, `Race`, `Level10`
	FROM `NicknameIndex`
	GROUP BY `NickType`, `Race`, `Level10`, `NickIndex`;

START TRANSACTION;
DELETE FROM `NicknameIndex`;
INSERT INTO `NicknameIndex` (`NickIndex`, `Nickname`, `NickType`, `Race`, `Level10`)
	SELECT `NickIndex`, `Nickname`, `NickType`, `Race`, `Level10` FROM `NicknameIndex_one`;
COMMIT;

DROP TEMPORARY TABLE `NicknameIndex_one`;

-- the key, unless an earlier run added it
SET @mig_has_pk := (SELECT COUNT(*) FROM information_schema.TABLE_CONSTRAINTS
	WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'NicknameIndex' AND CONSTRAINT_TYPE = 'PRIMARY KEY');
SET @mig_sql := IF(@mig_has_pk = 0,
	'ALTER TABLE `NicknameIndex` ADD PRIMARY KEY (`NickType`, `Race`, `Level10`, `NickIndex`)',
	'DO 0');
PREPARE mig_stmt FROM @mig_sql;
EXECUTE mig_stmt;
DEALLOCATE PREPARE mig_stmt;
