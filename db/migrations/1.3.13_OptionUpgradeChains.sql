-- 1.3.13_OptionUpgradeChains.sql
--
-- Fix UpgradeOptionType so each option points at the next tier in its class.
-- PreviousOptionType was already set for regen; UpgradeOptionType was 0.
--
-- Not changed (intentional):
--   STR/DEX/INT +18 and TOHIT/DEF +30  -- unique extras, not part of +1..+10
--   Stat-convert +5 -> +10             -- separate items, not upgrade chain
--   Uniques (Armega, Mihole, ...)
--   HP Steal / MP Steal already chain +1..+6
--
-- No backup. Safe to run twice. Restart gameserver after apply.
--
SET NAMES utf8mb4;

-- HP Regen by nickname tier: +1 -> +2 -> +3 -> +4 -> +5 -> +6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 33  WHERE `OptionType` = 174; -- HPRGN+1 -> +2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 34  WHERE `OptionType` = 33;  -- HPRGN+2 -> +3
UPDATE `OptionInfo` SET `UpgradeOptionType` = 118 WHERE `OptionType` = 34;  -- HPRGN+3 -> +4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 119 WHERE `OptionType` = 118; -- HPRGN+4 -> +5
UPDATE `OptionInfo` SET `UpgradeOptionType` = 120 WHERE `OptionType` = 119; -- HPRGN+5 -> +6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0   WHERE `OptionType` = 120; -- HPRGN+6 end

-- MP Regen by nickname tier
UPDATE `OptionInfo` SET `UpgradeOptionType` = 36  WHERE `OptionType` = 35;  -- MPRGN+1 -> +2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 37  WHERE `OptionType` = 36;  -- MPRGN+2 -> +3
UPDATE `OptionInfo` SET `UpgradeOptionType` = 121 WHERE `OptionType` = 37;  -- MPRGN+3 -> +4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 122 WHERE `OptionType` = 121; -- MPRGN+4 -> +5
UPDATE `OptionInfo` SET `UpgradeOptionType` = 123 WHERE `OptionType` = 122; -- MPRGN+5 -> +6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0   WHERE `OptionType` = 123; -- MPRGN+6 end

-- All Resistance: +6 was a dead end; +7..+10 already chained
UPDATE `OptionInfo` SET `UpgradeOptionType` = 209 WHERE `OptionType` = 208; -- RES+6 -> +7

-- All Attributes: +6 stopped; +7..+15 only had PreviousOptionType
UPDATE `OptionInfo` SET `UpgradeOptionType` = 217 WHERE `OptionType` = 207; -- ATTR+6  -> +7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 218 WHERE `OptionType` = 217; -- ATTR+7  -> +8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 219 WHERE `OptionType` = 218; -- ATTR+8  -> +9
UPDATE `OptionInfo` SET `UpgradeOptionType` = 220 WHERE `OptionType` = 219; -- ATTR+9  -> +10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 229 WHERE `OptionType` = 220; -- ATTR+10 -> +11
UPDATE `OptionInfo` SET `UpgradeOptionType` = 230 WHERE `OptionType` = 229; -- ATTR+11 -> +12
UPDATE `OptionInfo` SET `UpgradeOptionType` = 231 WHERE `OptionType` = 230; -- ATTR+12 -> +13
UPDATE `OptionInfo` SET `UpgradeOptionType` = 232 WHERE `OptionType` = 231; -- ATTR+13 -> +14
UPDATE `OptionInfo` SET `UpgradeOptionType` = 233 WHERE `OptionType` = 232; -- ATTR+14 -> +15
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0   WHERE `OptionType` = 233; -- ATTR+15 end
