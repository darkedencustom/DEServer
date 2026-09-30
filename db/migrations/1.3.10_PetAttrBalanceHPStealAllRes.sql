-- 1.3.10_PetAttrBalanceHPStealAllRes.sql
--
-- Level scaling (0-60) for the two options added in 1.3.9:
--   PetAttr 5  = HP Steal       (30 +1s spread 10-60, AccumAttr 30 at 60)
--   PetAttr 22 = All Registance (strong curve like attr 19, AccumAttr 80 at 60)
--
-- HP Steal: no grants before level 10; 30 ones and 21 zeros spaced evenly
-- across 10-60 so the cap is hit at 60, not earlier.
--
-- Needs a gameserver restart (pet tables load at boot).
-- Safe to run twice: every statement sets absolute values.
--
SET NAMES utf8mb4;

CREATE TABLE IF NOT EXISTS `PetAttrBalance1310_Backup` (
  `PetAttr` tinyint NOT NULL,
  `Level` int NOT NULL,
  `AddAttr` int NOT NULL,
  `AccumAttr` int NOT NULL,
  PRIMARY KEY (`PetAttr`, `Level`)
) ENGINE=InnoDB COMMENT='pre-1.3.10 rows for attrs 5/22 for rollback';
INSERT IGNORE INTO `PetAttrBalance1310_Backup` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`)
  SELECT `PetAttr`, `Level`, `AddAttr`, `AccumAttr` FROM `PetAttrBalanceInfo` WHERE `PetAttr` IN (5, 22);

DELETE FROM `PetAttrBalanceInfo` WHERE `PetAttr` IN (5, 22);

-- PetAttr 5 = HP Steal (max AccumAttr 30 at level 60)
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 0, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 1, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 2, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 3, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 4, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 5, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 6, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 7, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 8, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 9, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 10, 1, 1);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 11, 0, 1);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 12, 1, 2);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 13, 0, 2);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 14, 1, 3);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 15, 1, 4);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 16, 0, 4);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 17, 1, 5);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 18, 0, 5);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 19, 1, 6);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 20, 0, 6);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 21, 1, 7);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 22, 1, 8);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 23, 0, 8);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 24, 1, 9);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 25, 0, 9);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 26, 1, 10);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 27, 1, 11);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 28, 0, 11);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 29, 1, 12);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 30, 0, 12);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 31, 1, 13);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 32, 1, 14);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 33, 0, 14);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 34, 1, 15);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 35, 0, 15);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 36, 1, 16);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 37, 0, 16);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 38, 1, 17);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 39, 1, 18);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 40, 0, 18);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 41, 1, 19);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 42, 0, 19);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 43, 1, 20);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 44, 1, 21);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 45, 0, 21);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 46, 1, 22);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 47, 0, 22);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 48, 1, 23);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 49, 1, 24);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 50, 0, 24);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 51, 1, 25);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 52, 0, 25);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 53, 1, 26);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 54, 0, 26);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 55, 1, 27);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 56, 1, 28);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 57, 0, 28);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 58, 1, 29);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 59, 0, 29);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (5, 60, 1, 30);

-- PetAttr 22 = All Registance
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 0, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 1, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 2, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 3, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 4, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 5, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 6, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 7, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 8, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 9, 0, 0);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 10, 1, 1);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 11, 1, 2);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 12, 1, 3);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 13, 1, 4);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 14, 1, 5);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 15, 1, 6);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 16, 1, 7);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 17, 1, 8);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 18, 1, 9);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 19, 1, 10);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 20, 1, 11);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 21, 1, 12);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 22, 1, 13);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 23, 1, 14);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 24, 1, 15);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 25, 1, 16);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 26, 1, 17);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 27, 1, 18);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 28, 1, 19);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 29, 1, 20);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 30, 1, 21);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 31, 1, 22);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 32, 1, 23);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 33, 1, 24);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 34, 1, 25);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 35, 1, 26);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 36, 1, 27);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 37, 1, 28);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 38, 1, 29);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 39, 1, 30);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 40, 1, 31);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 41, 1, 32);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 42, 2, 34);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 43, 2, 36);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 44, 2, 38);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 45, 2, 40);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 46, 2, 42);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 47, 2, 44);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 48, 2, 46);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 49, 2, 48);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 50, 2, 50);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 51, 3, 53);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 52, 3, 56);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 53, 3, 59);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 54, 3, 62);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 55, 3, 65);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 56, 3, 68);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 57, 3, 71);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 58, 3, 74);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 59, 3, 77);
INSERT INTO `PetAttrBalanceInfo` (`PetAttr`, `Level`, `AddAttr`, `AccumAttr`) VALUES (22, 60, 3, 80);
