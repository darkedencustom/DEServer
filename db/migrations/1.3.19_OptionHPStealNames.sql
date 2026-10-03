-- 1.3.19_OptionHPStealNames.sql
--
-- HP Steal prefix ladder (list 1):
--   +1 Leech, +2 Stirge, +3 Strigoi, +4 Nosferatu, +5 Dracula, +6 Varcolac
-- HName matches Name (English), same rule as 1.3.11 / 1.3.12.
-- No backup table.
--
-- Needs a gameserver restart. Safe to run twice.
--
SET NAMES utf8mb4;

UPDATE `OptionInfo` SET `Name` = 'Leech',     `HName` = 'Leech'     WHERE `OptionType` = 26;  -- HPSTL+1
UPDATE `OptionInfo` SET `Name` = 'Stirge',    `HName` = 'Stirge'    WHERE `OptionType` = 27;  -- HPSTL+2
UPDATE `OptionInfo` SET `Name` = 'Strigoi',   `HName` = 'Strigoi'   WHERE `OptionType` = 28;  -- HPSTL+3
UPDATE `OptionInfo` SET `Name` = 'Nosferatu', `HName` = 'Nosferatu' WHERE `OptionType` = 112; -- HPSTL+4
UPDATE `OptionInfo` SET `Name` = 'Dracula',   `HName` = 'Dracula'   WHERE `OptionType` = 113; -- HPSTL+5
UPDATE `OptionInfo` SET `Name` = 'Varcolac',  `HName` = 'Varcolac'  WHERE `OptionType` = 114; -- HPSTL+6
