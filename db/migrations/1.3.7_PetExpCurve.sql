-- 1.3.7_PetExpCurve.sql
--
-- Full rebuild of PetExpInfo levels 0-60 on a clean exponential (log-scale)
-- cumulative curve. Levels 0-59 grow at ratio 1.10 and land on exactly
-- 30,000,000 AccumExp at level 59. Level 60 GoalExp is twice level 59's
-- GoalExp (cap step), so AccumExp at 60 is 30,000,000 + 2*GoalExp(59).
--
-- Formula (0-59): Accum(L) = 3e7 * (1.10^(L+1) - 1) / (1.10^60 - 1)
--                 Goal = delta Accum
--         (60):   Goal(60) = 2 * Goal(59)
--
-- Needs a gameserver restart (pet tables load at boot).
-- Safe to run twice: every statement sets absolute values.
--
SET NAMES utf8mb4;

-- 0. Backup (first run only).
CREATE TABLE IF NOT EXISTS `PetExpCurve137_Backup` (
  `PetLevel` tinyint NOT NULL,
  `PetGoalExp` int NOT NULL,
  `PetAccumExp` int NOT NULL,
  PRIMARY KEY (`PetLevel`)
) ENGINE=InnoDB COMMENT='pre-1.3.7 PetExpInfo for rollback';
INSERT IGNORE INTO `PetExpCurve137_Backup` (`PetLevel`, `PetGoalExp`, `PetAccumExp`)
  SELECT `PetLevel`, `PetGoalExp`, `PetAccumExp` FROM `PetExpInfo`;

-- 1. Full curve levels 0-60.
UPDATE `PetExpInfo` SET `PetGoalExp` = 9885, `PetAccumExp` = 9885 WHERE `PetLevel` = 0;
UPDATE `PetExpInfo` SET `PetGoalExp` = 10874, `PetAccumExp` = 20759 WHERE `PetLevel` = 1;
UPDATE `PetExpInfo` SET `PetGoalExp` = 11961, `PetAccumExp` = 32720 WHERE `PetLevel` = 2;
UPDATE `PetExpInfo` SET `PetGoalExp` = 13158, `PetAccumExp` = 45878 WHERE `PetLevel` = 3;
UPDATE `PetExpInfo` SET `PetGoalExp` = 14473, `PetAccumExp` = 60351 WHERE `PetLevel` = 4;
UPDATE `PetExpInfo` SET `PetGoalExp` = 15920, `PetAccumExp` = 76271 WHERE `PetLevel` = 5;
UPDATE `PetExpInfo` SET `PetGoalExp` = 17512, `PetAccumExp` = 93783 WHERE `PetLevel` = 6;
UPDATE `PetExpInfo` SET `PetGoalExp` = 19264, `PetAccumExp` = 113047 WHERE `PetLevel` = 7;
UPDATE `PetExpInfo` SET `PetGoalExp` = 21190, `PetAccumExp` = 134237 WHERE `PetLevel` = 8;
UPDATE `PetExpInfo` SET `PetGoalExp` = 23309, `PetAccumExp` = 157546 WHERE `PetLevel` = 9;
UPDATE `PetExpInfo` SET `PetGoalExp` = 25640, `PetAccumExp` = 183186 WHERE `PetLevel` = 10;
UPDATE `PetExpInfo` SET `PetGoalExp` = 28204, `PetAccumExp` = 211390 WHERE `PetLevel` = 11;
UPDATE `PetExpInfo` SET `PetGoalExp` = 31024, `PetAccumExp` = 242414 WHERE `PetLevel` = 12;
UPDATE `PetExpInfo` SET `PetGoalExp` = 34126, `PetAccumExp` = 276540 WHERE `PetLevel` = 13;
UPDATE `PetExpInfo` SET `PetGoalExp` = 37540, `PetAccumExp` = 314080 WHERE `PetLevel` = 14;
UPDATE `PetExpInfo` SET `PetGoalExp` = 41293, `PetAccumExp` = 355373 WHERE `PetLevel` = 15;
UPDATE `PetExpInfo` SET `PetGoalExp` = 45423, `PetAccumExp` = 400796 WHERE `PetLevel` = 16;
UPDATE `PetExpInfo` SET `PetGoalExp` = 49964, `PetAccumExp` = 450760 WHERE `PetLevel` = 17;
UPDATE `PetExpInfo` SET `PetGoalExp` = 54962, `PetAccumExp` = 505722 WHERE `PetLevel` = 18;
UPDATE `PetExpInfo` SET `PetGoalExp` = 60457, `PetAccumExp` = 566179 WHERE `PetLevel` = 19;
UPDATE `PetExpInfo` SET `PetGoalExp` = 66503, `PetAccumExp` = 632682 WHERE `PetLevel` = 20;
UPDATE `PetExpInfo` SET `PetGoalExp` = 73154, `PetAccumExp` = 705836 WHERE `PetLevel` = 21;
UPDATE `PetExpInfo` SET `PetGoalExp` = 80469, `PetAccumExp` = 786305 WHERE `PetLevel` = 22;
UPDATE `PetExpInfo` SET `PetGoalExp` = 88516, `PetAccumExp` = 874821 WHERE `PetLevel` = 23;
UPDATE `PetExpInfo` SET `PetGoalExp` = 97367, `PetAccumExp` = 972188 WHERE `PetLevel` = 24;
UPDATE `PetExpInfo` SET `PetGoalExp` = 107104, `PetAccumExp` = 1079292 WHERE `PetLevel` = 25;
UPDATE `PetExpInfo` SET `PetGoalExp` = 117814, `PetAccumExp` = 1197106 WHERE `PetLevel` = 26;
UPDATE `PetExpInfo` SET `PetGoalExp` = 129596, `PetAccumExp` = 1326702 WHERE `PetLevel` = 27;
UPDATE `PetExpInfo` SET `PetGoalExp` = 142556, `PetAccumExp` = 1469258 WHERE `PetLevel` = 28;
UPDATE `PetExpInfo` SET `PetGoalExp` = 156811, `PetAccumExp` = 1626069 WHERE `PetLevel` = 29;
UPDATE `PetExpInfo` SET `PetGoalExp` = 172492, `PetAccumExp` = 1798561 WHERE `PetLevel` = 30;
UPDATE `PetExpInfo` SET `PetGoalExp` = 189741, `PetAccumExp` = 1988302 WHERE `PetLevel` = 31;
UPDATE `PetExpInfo` SET `PetGoalExp` = 208716, `PetAccumExp` = 2197018 WHERE `PetLevel` = 32;
UPDATE `PetExpInfo` SET `PetGoalExp` = 229587, `PetAccumExp` = 2426605 WHERE `PetLevel` = 33;
UPDATE `PetExpInfo` SET `PetGoalExp` = 252546, `PetAccumExp` = 2679151 WHERE `PetLevel` = 34;
UPDATE `PetExpInfo` SET `PetGoalExp` = 277800, `PetAccumExp` = 2956951 WHERE `PetLevel` = 35;
UPDATE `PetExpInfo` SET `PetGoalExp` = 305581, `PetAccumExp` = 3262532 WHERE `PetLevel` = 36;
UPDATE `PetExpInfo` SET `PetGoalExp` = 336138, `PetAccumExp` = 3598670 WHERE `PetLevel` = 37;
UPDATE `PetExpInfo` SET `PetGoalExp` = 369752, `PetAccumExp` = 3968422 WHERE `PetLevel` = 38;
UPDATE `PetExpInfo` SET `PetGoalExp` = 406728, `PetAccumExp` = 4375150 WHERE `PetLevel` = 39;
UPDATE `PetExpInfo` SET `PetGoalExp` = 447400, `PetAccumExp` = 4822550 WHERE `PetLevel` = 40;
UPDATE `PetExpInfo` SET `PetGoalExp` = 492140, `PetAccumExp` = 5314690 WHERE `PetLevel` = 41;
UPDATE `PetExpInfo` SET `PetGoalExp` = 541355, `PetAccumExp` = 5856045 WHERE `PetLevel` = 42;
UPDATE `PetExpInfo` SET `PetGoalExp` = 595490, `PetAccumExp` = 6451535 WHERE `PetLevel` = 43;
UPDATE `PetExpInfo` SET `PetGoalExp` = 655038, `PetAccumExp` = 7106573 WHERE `PetLevel` = 44;
UPDATE `PetExpInfo` SET `PetGoalExp` = 720543, `PetAccumExp` = 7827116 WHERE `PetLevel` = 45;
UPDATE `PetExpInfo` SET `PetGoalExp` = 792597, `PetAccumExp` = 8619713 WHERE `PetLevel` = 46;
UPDATE `PetExpInfo` SET `PetGoalExp` = 871856, `PetAccumExp` = 9491569 WHERE `PetLevel` = 47;
UPDATE `PetExpInfo` SET `PetGoalExp` = 959043, `PetAccumExp` = 10450612 WHERE `PetLevel` = 48;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1054946, `PetAccumExp` = 11505558 WHERE `PetLevel` = 49;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1160441, `PetAccumExp` = 12665999 WHERE `PetLevel` = 50;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1276485, `PetAccumExp` = 13942484 WHERE `PetLevel` = 51;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1404134, `PetAccumExp` = 15346618 WHERE `PetLevel` = 52;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1544547, `PetAccumExp` = 16891165 WHERE `PetLevel` = 53;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1699002, `PetAccumExp` = 18590167 WHERE `PetLevel` = 54;
UPDATE `PetExpInfo` SET `PetGoalExp` = 1868902, `PetAccumExp` = 20459069 WHERE `PetLevel` = 55;
UPDATE `PetExpInfo` SET `PetGoalExp` = 2055792, `PetAccumExp` = 22514861 WHERE `PetLevel` = 56;
UPDATE `PetExpInfo` SET `PetGoalExp` = 2261371, `PetAccumExp` = 24776232 WHERE `PetLevel` = 57;
UPDATE `PetExpInfo` SET `PetGoalExp` = 2487509, `PetAccumExp` = 27263741 WHERE `PetLevel` = 58;
UPDATE `PetExpInfo` SET `PetGoalExp` = 2736259, `PetAccumExp` = 30000000 WHERE `PetLevel` = 59;
UPDATE `PetExpInfo` SET `PetGoalExp` = 5472518, `PetAccumExp` = 35472518 WHERE `PetLevel` = 60;

-- 2. Ensure every level row exists if a lean DB was missing some.
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 0, 9885, 9885 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 0);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 1, 10874, 20759 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 1);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 2, 11961, 32720 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 2);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 3, 13158, 45878 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 3);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 4, 14473, 60351 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 4);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 5, 15920, 76271 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 5);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 6, 17512, 93783 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 6);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 7, 19264, 113047 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 7);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 8, 21190, 134237 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 8);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 9, 23309, 157546 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 9);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 10, 25640, 183186 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 10);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 11, 28204, 211390 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 11);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 12, 31024, 242414 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 12);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 13, 34126, 276540 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 13);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 14, 37540, 314080 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 14);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 15, 41293, 355373 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 15);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 16, 45423, 400796 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 16);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 17, 49964, 450760 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 17);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 18, 54962, 505722 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 18);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 19, 60457, 566179 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 19);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 20, 66503, 632682 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 20);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 21, 73154, 705836 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 21);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 22, 80469, 786305 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 22);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 23, 88516, 874821 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 23);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 24, 97367, 972188 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 24);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 25, 107104, 1079292 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 25);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 26, 117814, 1197106 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 26);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 27, 129596, 1326702 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 27);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 28, 142556, 1469258 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 28);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 29, 156811, 1626069 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 29);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 30, 172492, 1798561 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 30);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 31, 189741, 1988302 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 31);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 32, 208716, 2197018 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 32);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 33, 229587, 2426605 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 33);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 34, 252546, 2679151 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 34);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 35, 277800, 2956951 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 35);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 36, 305581, 3262532 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 36);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 37, 336138, 3598670 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 37);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 38, 369752, 3968422 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 38);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 39, 406728, 4375150 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 39);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 40, 447400, 4822550 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 40);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 41, 492140, 5314690 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 41);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 42, 541355, 5856045 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 42);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 43, 595490, 6451535 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 43);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 44, 655038, 7106573 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 44);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 45, 720543, 7827116 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 45);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 46, 792597, 8619713 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 46);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 47, 871856, 9491569 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 47);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 48, 959043, 10450612 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 48);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 49, 1054946, 11505558 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 49);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 50, 1160441, 12665999 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 50);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 51, 1276485, 13942484 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 51);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 52, 1404134, 15346618 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 52);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 53, 1544547, 16891165 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 53);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 54, 1699002, 18590167 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 54);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 55, 1868902, 20459069 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 55);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 56, 2055792, 22514861 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 56);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 57, 2261371, 24776232 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 57);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 58, 2487509, 27263741 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 58);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 59, 2736259, 30000000 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 59);
INSERT INTO `PetExpInfo` (`PetLevel`, `PetGoalExp`, `PetAccumExp`) SELECT 60, 5472518, 35472518 FROM DUAL WHERE NOT EXISTS (SELECT 1 FROM `PetExpInfo` WHERE `PetLevel` = 60);
