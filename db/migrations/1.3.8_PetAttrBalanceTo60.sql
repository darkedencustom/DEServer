-- 1.3.8_PetAttrBalanceTo60.sql
--
-- Ensure every existing PetAttr has PetAttrBalanceInfo rows through level 60.
-- The 1.3.x dump already included 0-60 for attrs 0,1,2,3,4,9,10,11,12,18,19,20,21,23;
-- this re-applies the 51-60 tails for databases that stopped at 50.
--
-- PetAttrBalanceInfo has no unique key in the stock schema, so each level is
-- deleted then inserted (idempotent).
--
-- Needs a gameserver restart (pet tables load at boot).
-- Safe to run twice: every statement sets absolute values.
--
SET NAMES utf8mb4;

CREATE TABLE IF NOT EXISTS `PetAttrBalance138_Backup` (
  `PetAttr` tinyint NOT NULL,
  `Level` int NOT NULL,
  `AddAttr` int NOT NULL,
  `AccumAttr` int NOT NULL,
  PRIMARY KEY (`PetAttr`, `Level`)
) ENGINE=InnoDB COMMENT='pre-1.3.8 PetAttrBalanceInfo level 51-60 for rollback';
INSERT IGNORE INTO `PetAttrBalance138_Backup` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`)
  SELECT `PetAttr`, `Level`, `AddAttr`, `AccumAttr` FROM `PetAttrBalanceInfo` WHERE `Level` >= 51;

-- PetAttr 0 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 51, 1, 22);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 52, 1, 23);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 53, 1, 24);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 54, 1, 25);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 55, 1, 26);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 56, 1, 27);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 57, 1, 28);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 58, 1, 29);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 59, 1, 30);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 0 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (0, 60, 1, 31);

-- PetAttr 1 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 51, 1, 22);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 52, 1, 23);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 53, 1, 24);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 54, 1, 25);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 55, 1, 26);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 56, 1, 27);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 57, 1, 28);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 58, 1, 29);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 59, 1, 30);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 1 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (1, 60, 1, 31);

-- PetAttr 2 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 51, 1, 22);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 52, 1, 23);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 53, 1, 24);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 54, 1, 25);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 55, 1, 26);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 56, 1, 27);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 57, 1, 28);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 58, 1, 29);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 59, 1, 30);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 2 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (2, 60, 1, 31);

-- PetAttr 3 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 51, 5, 55);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 52, 5, 60);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 53, 5, 65);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 54, 5, 70);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 55, 5, 75);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 56, 5, 80);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 57, 5, 85);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 58, 5, 90);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 59, 5, 95);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 3 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (3, 60, 5, 100);

-- PetAttr 4 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 51, 5, 55);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 52, 5, 60);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 53, 5, 65);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 54, 5, 70);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 55, 5, 75);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 56, 5, 80);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 57, 5, 85);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 58, 5, 90);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 59, 5, 95);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 4 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (4, 60, 5, 100);

-- PetAttr 9 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 51, 2, 32);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 52, 2, 34);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 53, 2, 36);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 54, 2, 38);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 55, 2, 40);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 56, 2, 42);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 57, 2, 44);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 58, 2, 46);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 59, 2, 48);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 9 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (9, 60, 2, 50);

-- PetAttr 10 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 51, 2, 32);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 52, 2, 34);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 53, 2, 36);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 54, 2, 38);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 55, 2, 40);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 56, 2, 42);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 57, 2, 44);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 58, 2, 46);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 59, 2, 48);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 10 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (10, 60, 2, 50);

-- PetAttr 11 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 51, 0, 11);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 52, 1, 12);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 53, 0, 12);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 54, 1, 13);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 55, 0, 13);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 56, 1, 14);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 57, 0, 14);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 58, 1, 15);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 59, 0, 15);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 11 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (11, 60, 1, 16);

-- PetAttr 12 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 51, 2, 32);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 52, 2, 34);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 53, 2, 36);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 54, 2, 38);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 55, 2, 40);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 56, 2, 42);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 57, 2, 44);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 58, 2, 46);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 59, 2, 48);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 12 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (12, 60, 2, 50);

-- PetAttr 18 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 51, 0, 11);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 52, 1, 12);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 53, 0, 12);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 54, 1, 13);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 55, 0, 13);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 56, 1, 14);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 57, 0, 14);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 58, 1, 15);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 59, 0, 15);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 18 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (18, 60, 1, 16);

-- PetAttr 19 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 51, 3, 53);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 52, 3, 56);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 53, 3, 59);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 54, 3, 62);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 55, 3, 65);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 56, 3, 68);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 57, 3, 71);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 58, 3, 74);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 59, 3, 77);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 19 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (19, 60, 3, 80);

-- PetAttr 20 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 51, 3, 53);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 52, 3, 56);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 53, 3, 59);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 54, 3, 62);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 55, 3, 65);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 56, 3, 68);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 57, 3, 71);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 58, 3, 74);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 59, 3, 77);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 20 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (20, 60, 3, 80);

-- PetAttr 21 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 51, 1, 16);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 52, 1, 17);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 53, 2, 19);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 54, 2, 21);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 55, 2, 23);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 56, 2, 25);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 57, 2, 27);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 58, 2, 29);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 59, 2, 31);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 21 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (21, 60, 2, 33);

-- PetAttr 23 levels 51-60
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 51;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 51, 0, 11);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 52;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 52, 1, 12);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 53;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 53, 0, 12);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 54;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 54, 1, 13);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 55;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 55, 0, 13);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 56;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 56, 1, 14);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 57;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 57, 0, 14);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 58;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 58, 1, 15);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 59;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 59, 0, 15);
DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` = 23 AND `Level` = 60;
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (23, 60, 1, 16);

