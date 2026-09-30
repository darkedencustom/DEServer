-- 1.3.9_PetAttrInfoHPStealAllRes.sql
--
-- Add PetAttr 5 (HP Steal) and PetAttr 22 (All Registance — spelling matches
-- OptionClassInfo) to PetAttrInfo, then set EnchantRatio so the table sums
-- to 100 (the gameserver walks rand()%100 subtracting each ratio).
--
--   7 : HP Steal (5), Luck (21), All Registance (22), All Attributes (23)
--   6 : every other option
--   4*7 + 12*6 = 28 + 72 = 100
--
-- Needs a gameserver restart (pet tables load at boot).
-- Safe to run twice: every statement sets absolute values.
--
SET NAMES utf8mb4;

CREATE TABLE IF NOT EXISTS `PetAttrInfo139_Backup` (
  `PetAttr` tinyint NOT NULL,
  `EnchantRatio` tinyint NOT NULL,
  PRIMARY KEY (`PetAttr`)
) ENGINE=InnoDB COMMENT='pre-1.3.9 PetAttrInfo snapshot for rollback';
INSERT IGNORE INTO `PetAttrInfo139_Backup` (`PetAttr`, `EnchantRatio`)
  SELECT `PetAttr`, `EnchantRatio` FROM `PetAttrInfo`;

-- New options
DELETE FROM `PetAttrInfo` WHERE `PetAttr` IN (5, 22);
INSERT INTO `PetAttrInfo` (`PetAttr`, `EnchantRatio`) VALUES (5, 7);   -- HP Steal
INSERT INTO `PetAttrInfo` (`PetAttr`, `EnchantRatio`) VALUES (22, 7);  -- All Registance

-- Base rate for every option
UPDATE `PetAttrInfo` SET `EnchantRatio` = 6;

-- Slightly higher rate for the four featured options
UPDATE `PetAttrInfo` SET `EnchantRatio` = 7 WHERE `PetAttr` IN (5, 21, 22, 23);
-- 5 = HP Steal, 21 = Luck, 22 = All Registance, 23 = All Attributes
