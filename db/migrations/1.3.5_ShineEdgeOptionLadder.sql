-- 1.3.5_ShineEdgeOptionLadder.sql
--
-- Blue Drop Shine and Blue Drop Edge (EventStar 78/79) upgrade an item's single option using
-- OptionInfo.UpgradeThirdRatio, and only when the option also has an UpgradeOptionType
-- (OptionInfo::isUpgradeThirdPossible). They are the ladder into the high Luck, All Resist and All
-- Attributes tiers (LUCK+4.., RES+6.., ATTR+4..).
--
-- The rows that lead into those tiers are the older OptionTypes 176-185. When 198-238 were imported
-- beside them, these rows kept their live values, which have no third-tier ratio and no link upward.
-- Shine/Edge could therefore never take an option past LUCK+3, RES+5 or ATTR+3. This restores the
-- v664 dump's values (db/DARKEDEN.sql in the old D:\GitHub\DEServer_v664 checkout) on those six rows:
--
--   176 LUCK+2 -> LUCK+3   70%        181 RES+4 -> RES+5   70%        184 ATTR+2 -> ATTR+3   70%
--   177 LUCK+3 -> LUCK+4   50%        182 RES+5 -> RES+6   60%        185 ATTR+3 -> ATTR+4   50%
--
-- and links 208 RES+6 -> 209 RES+7. RES+6 already has a 50% third ratio but no target, even in the
-- dump, so it was a dead end in the middle of the ladder; the v9 data links it to 209.
-- (Chance = ratio x the item's UpgradeRatio / EVENT_BLUE_DROP_ENCHANT_RATIO, 10000 by default.)
--
-- UpgradeRatio stays 0 on 177/182/185/208, so the normal Blue Drop, Blue Bird and the drop-time option
-- upgrade in MonsterManager (all gated on isUpgradePossible) behave exactly as before. The
-- PreviousOptionType links on 205/208/209/213 already point back down these rows, so a Shine failure
-- downgrades along the same ladder.
--
-- Needs a gameserver restart: OptionInfo is read at boot.
-- The client also gates these items: it only sends the enchant when its own itemoption.inf gives the
-- option a non-zero UpgradeOptionType, and every high-tier row there is 0. Shine/Edge stay unusable
-- in game until the client data is patched to match.
--
-- Rollback: db/rollback/1.3.5_ShineEdgeOptionLadder_rollback.sql

SET NAMES utf8mb4;

UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70                             WHERE `OptionType` = 176;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 213, `UpgradeThirdRatio` = 50  WHERE `OptionType` = 177;
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70                             WHERE `OptionType` = 181;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 208, `UpgradeThirdRatio` = 60  WHERE `OptionType` = 182;
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70                             WHERE `OptionType` = 184;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 205, `UpgradeThirdRatio` = 50  WHERE `OptionType` = 185;
UPDATE `OptionInfo` SET `UpgradeOptionType` = 209                            WHERE `OptionType` = 208;
