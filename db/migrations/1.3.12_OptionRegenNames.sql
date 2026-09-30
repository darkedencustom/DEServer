-- 1.3.12_OptionRegenNames.sql
--
-- Set OptionInfo Name/HName for HP Regen and MP Regen to the client prefix
-- names used in itemoption.en.inf / itemoption.inf:
--   HP Regen +6..+1 = Jupiter, Saturn, Uranus, Neptune, Earth, Venus
--   MP Regen +6..+1 = Pluto, Eris, Haumea, Makemake, Gonggong, Ceres
-- HName matches Name (English), same rule as 1.3.11.
-- No backup table.
--
-- Needs a gameserver restart (option tables load at boot).
-- Safe to run twice: every statement sets absolute values.
--
SET NAMES utf8mb4;

-- HP Regen (Class 7)
UPDATE `OptionInfo` SET `Name` = 'Venus',   `HName` = 'Venus'   WHERE `OptionType` = 174; -- HPRGN+1
UPDATE `OptionInfo` SET `Name` = 'Earth',   `HName` = 'Earth'   WHERE `OptionType` = 33;  -- HPRGN+2
UPDATE `OptionInfo` SET `Name` = 'Neptune', `HName` = 'Neptune' WHERE `OptionType` = 34;  -- HPRGN+3
UPDATE `OptionInfo` SET `Name` = 'Uranus',  `HName` = 'Uranus'  WHERE `OptionType` = 118; -- HPRGN+4
UPDATE `OptionInfo` SET `Name` = 'Saturn',  `HName` = 'Saturn'  WHERE `OptionType` = 119; -- HPRGN+5
UPDATE `OptionInfo` SET `Name` = 'Jupiter', `HName` = 'Jupiter' WHERE `OptionType` = 120; -- HPRGN+6

-- MP Regen (Class 8)
UPDATE `OptionInfo` SET `Name` = 'Ceres',    `HName` = 'Ceres'    WHERE `OptionType` = 35;  -- MPRGN+1
UPDATE `OptionInfo` SET `Name` = 'Gonggong', `HName` = 'Gonggong' WHERE `OptionType` = 36;  -- MPRGN+2
UPDATE `OptionInfo` SET `Name` = 'Makemake', `HName` = 'Makemake' WHERE `OptionType` = 37;  -- MPRGN+3
UPDATE `OptionInfo` SET `Name` = 'Haumea',   `HName` = 'Haumea'   WHERE `OptionType` = 121; -- MPRGN+4
UPDATE `OptionInfo` SET `Name` = 'Eris',     `HName` = 'Eris'     WHERE `OptionType` = 122; -- MPRGN+5
UPDATE `OptionInfo` SET `Name` = 'Pluto',    `HName` = 'Pluto'    WHERE `OptionType` = 123; -- MPRGN+6
