-- 1.3.6_ShineEdgeFullLadder.sql
--
-- Restores the original v664 Blue Drop Shine / Blue Drop Edge ladder (EventStar 78/79) on every option.
-- 1.3.5 only reconnected the Luck / All Resist / All Attributes high tiers; in the v664 dump
-- (db/DARKEDEN.sql in the old D:\GitHub\DEServer_v664 checkout) every option family has one, and the
-- live table had lost almost all of it:
--
--   * UpgradeThirdRatio was 0 on every row, so Shine/Edge refused even an ATTR+1 (99% in the dump).
--   * The +5 tiers (and the 3-tier families' +3) had no UpgradeOptionType into the +6..+10 rows.
--   * The +6..+10 rows had neither an upward nor a downward (PreviousOptionType) link.
--
-- Shine/Edge odds after this, before the item's UpgradeRatio multiplier:
--   5-tier families (STR DEX INT HP MP ToHit DEF DAM PRO DUR ASPD Critical):
--     +1 99  +2 90  +3 80  +4 70  +5 60  +6 50  +7 35  +8 25  +9 15   (+10 is the top)
--   All Resist: +1 99  +2 90  +3 80  +4 70  +5 60  +6 50  +7 50  +8 30  +9 15   (+10 is the top)
--   3-tier families (HP/MP Steal, the four resists, Vision, Luck, All Attributes):
--     +1 99  +2 70  +3 50  +4 30  +5 15   (+6 is the top)
--   HP/MP Regeneration have third ratios but no upward links in the dump either, so they stay
--   non-upgradeable; Vision +6 links to +7 but has no third ratio, as in the dump.
--
-- Only UpgradeOptionType, UpgradeThirdRatio and PreviousOptionType change, and only where they differ
-- from the dump (RES+6 keeps 1.3.5's link to RES+7). UpgradeRatio / UpgradeSecondRatio already match
-- the dump and are untouched, so the normal Blue Drop, Blue Drop 2, Blue Bird and the drop-time luck
-- upgrade (all gated on OptionInfo::isUpgradePossible) keep their current behaviour. Two things do
-- change, both back to the original game:
--   * a failed Shine, a Blue Bird failure roll and a drop-time luck downgrade now take a +6..+10 option
--     down one tier instead of removing it (they fall back to removal when PreviousOptionType is 0);
--   * a Blue Bird on a two-option item now also gives its failure roll to a +6..+10 option, as it
--     already does for a maxed +5.
--
-- Needs a gameserver restart (OptionInfo loads at boot). Ships with the client change that gives
-- Shine/Edge their own "can be enchanted" rule (VS_UI_Description.cpp / VS_UI_GameCommon.cpp);
-- without it the client still shows and sends Shine/Edge by the Blue Drop ladder.
--
-- Rollback: db/rollback/1.3.6_ShineEdgeFullLadder_rollback.sql

SET NAMES utf8mb4;

UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 1;  -- STR+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 2;  -- STR+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 3;  -- STR+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 4;  -- STR+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 88, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 5;  -- STR+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 6;  -- DEX+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 7;  -- DEX+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 8;  -- DEX+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 9;  -- DEX+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 93, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 10;  -- DEX+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 11;  -- INT+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 12;  -- INT+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 13;  -- INT+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 14;  -- INT+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 98, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 15;  -- INT+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 16;  -- HP+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 17;  -- HP+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 18;  -- HP+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 19;  -- HP+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 103, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 20;  -- HP+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 21;  -- MP+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 22;  -- MP+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 23;  -- MP+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 24;  -- MP+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 108, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 25;  -- MP+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 26;  -- HPSTL+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 27;  -- HPSTL+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 112, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 28;  -- HPSTL+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 29;  -- MPSTL+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 30;  -- MPSTL+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 115, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 31;  -- MPSTL+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70, `PreviousOptionType` = 174 WHERE `OptionType` = 33;  -- HPRGN+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 50, `PreviousOptionType` = 33 WHERE `OptionType` = 34;  -- HPRGN+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 35;  -- MPRGN+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70, `PreviousOptionType` = 35 WHERE `OptionType` = 36;  -- MPRGN+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 50, `PreviousOptionType` = 36 WHERE `OptionType` = 37;  -- MPRGN+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 38;  -- TOHIT+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 39;  -- TOHIT+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 40;  -- TOHIT+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 41;  -- TOHIT+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 124, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 42;  -- TOHIT+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 43;  -- DEF+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 44;  -- DEF+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 45;  -- DEF+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 46;  -- DEF+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 129, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 47;  -- DEF+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 48;  -- DAM+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 49;  -- DAM+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 50;  -- DAM+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 51;  -- DAM+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 134, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 52;  -- DAM+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 53;  -- PRO+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 54;  -- PRO+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 55;  -- PRO+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 56;  -- PRO+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 139, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 57;  -- PRO+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 58;  -- DUR+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 59;  -- DUR+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 60;  -- DUR+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 61;  -- DUR+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 144, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 62;  -- DUR+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 63;  -- PORES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 64;  -- PORES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 149, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 65;  -- PORES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 66;  -- ACRES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 67;  -- ACRES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 152, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 68;  -- ACRES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 69;  -- CURES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 70;  -- CURES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 155, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 71;  -- CURES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 72;  -- BLRES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 73;  -- BLRES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 158, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 74;  -- BLRES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 75;  -- VIS+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 76;  -- VIS+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 161, `UpgradeThirdRatio` = 50 WHERE `OptionType` = 77;  -- VIS+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 78;  -- ASPD+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 79;  -- ASPD+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 80;  -- ASPD+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 81;  -- ASPD+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 164, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 82;  -- ASPD+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 83;  -- CRI+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 84;  -- CRI+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 85;  -- CRI+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 70 WHERE `OptionType` = 86;  -- CRI+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 169, `UpgradeThirdRatio` = 60 WHERE `OptionType` = 87;  -- CRI+5
UPDATE `OptionInfo` SET `UpgradeOptionType` = 89, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 5 WHERE `OptionType` = 88;  -- STR+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 90, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 88 WHERE `OptionType` = 89;  -- STR+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 91, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 89 WHERE `OptionType` = 90;  -- STR+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 92, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 90 WHERE `OptionType` = 91;  -- STR+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 91 WHERE `OptionType` = 92;  -- STR+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 94, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 10 WHERE `OptionType` = 93;  -- DEX+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 95, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 93 WHERE `OptionType` = 94;  -- DEX+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 96, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 94 WHERE `OptionType` = 95;  -- DEX+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 97, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 95 WHERE `OptionType` = 96;  -- DEX+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 96 WHERE `OptionType` = 97;  -- DEX+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 99, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 15 WHERE `OptionType` = 98;  -- INT+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 100, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 98 WHERE `OptionType` = 99;  -- INT+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 101, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 99 WHERE `OptionType` = 100;  -- INT+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 102, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 100 WHERE `OptionType` = 101;  -- INT+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 101 WHERE `OptionType` = 102;  -- INT+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 104, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 20 WHERE `OptionType` = 103;  -- HP+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 105, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 103 WHERE `OptionType` = 104;  -- HP+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 106, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 104 WHERE `OptionType` = 105;  -- HP+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 107, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 105 WHERE `OptionType` = 106;  -- HP+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 106 WHERE `OptionType` = 107;  -- HP+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 109, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 25 WHERE `OptionType` = 108;  -- MP+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 110, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 108 WHERE `OptionType` = 109;  -- MP+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 111, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 109 WHERE `OptionType` = 110;  -- MP+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 216, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 110 WHERE `OptionType` = 111;  -- MP+9
UPDATE `OptionInfo` SET `UpgradeOptionType` = 113, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 28 WHERE `OptionType` = 112;  -- HPSTL+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 114, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 112 WHERE `OptionType` = 113;  -- HPSTL+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 113 WHERE `OptionType` = 114;  -- HPSTL+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 116, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 31 WHERE `OptionType` = 115;  -- MPSTL+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 117, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 115 WHERE `OptionType` = 116;  -- MPSTL+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 116 WHERE `OptionType` = 117;  -- MPSTL+6
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 30, `PreviousOptionType` = 34 WHERE `OptionType` = 118;  -- HPRGN+4
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 15, `PreviousOptionType` = 118 WHERE `OptionType` = 119;  -- HPRGN+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 119 WHERE `OptionType` = 120;  -- HPRGN+6
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 30, `PreviousOptionType` = 37 WHERE `OptionType` = 121;  -- MPRGN+4
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 15, `PreviousOptionType` = 121 WHERE `OptionType` = 122;  -- MPRGN+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 122 WHERE `OptionType` = 123;  -- MPRGN+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 125, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 42 WHERE `OptionType` = 124;  -- TOHIT+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 126, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 124 WHERE `OptionType` = 125;  -- TOHIT+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 127, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 125 WHERE `OptionType` = 126;  -- TOHIT+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 128, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 126 WHERE `OptionType` = 127;  -- TOHIT+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 127 WHERE `OptionType` = 128;  -- TOHIT+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 130, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 47 WHERE `OptionType` = 129;  -- DEF+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 131, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 129 WHERE `OptionType` = 130;  -- DEF+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 132, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 130 WHERE `OptionType` = 131;  -- DEF+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 133, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 131 WHERE `OptionType` = 132;  -- DEF+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 132 WHERE `OptionType` = 133;  -- DEF+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 135, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 52 WHERE `OptionType` = 134;  -- DAM+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 136, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 134 WHERE `OptionType` = 135;  -- DAM+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 137, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 135 WHERE `OptionType` = 136;  -- DAM+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 138, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 136 WHERE `OptionType` = 137;  -- DAM+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 137 WHERE `OptionType` = 138;  -- DAM+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 140, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 57 WHERE `OptionType` = 139;  -- PRO+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 141, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 139 WHERE `OptionType` = 140;  -- PRO+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 142, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 140 WHERE `OptionType` = 141;  -- PRO+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 143, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 141 WHERE `OptionType` = 142;  -- PRO+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 142 WHERE `OptionType` = 143;  -- PRO+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 145, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 62 WHERE `OptionType` = 144;  -- DUR+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 146, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 144 WHERE `OptionType` = 145;  -- DUR+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 147, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 145 WHERE `OptionType` = 146;  -- DUR+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 148, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 146 WHERE `OptionType` = 147;  -- DUR+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 147 WHERE `OptionType` = 148;  -- DUR+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 150, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 65 WHERE `OptionType` = 149;  -- PORES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 151, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 149 WHERE `OptionType` = 150;  -- PORES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 150 WHERE `OptionType` = 151;  -- PORES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 153, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 68 WHERE `OptionType` = 152;  -- ACRES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 154, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 152 WHERE `OptionType` = 153;  -- ACRES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 153 WHERE `OptionType` = 154;  -- ACRES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 156, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 71 WHERE `OptionType` = 155;  -- CURES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 157, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 155 WHERE `OptionType` = 156;  -- CURES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 156 WHERE `OptionType` = 157;  -- CURES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 159, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 74 WHERE `OptionType` = 158;  -- BLRES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 160, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 158 WHERE `OptionType` = 159;  -- BLRES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 159 WHERE `OptionType` = 160;  -- BLRES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 162, `UpgradeThirdRatio` = 30, `PreviousOptionType` = 77 WHERE `OptionType` = 161;  -- VIS+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 163, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 161 WHERE `OptionType` = 162;  -- VIS+5
UPDATE `OptionInfo` SET `UpgradeOptionType` = 225, `PreviousOptionType` = 162 WHERE `OptionType` = 163;  -- VIS+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 165, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 82 WHERE `OptionType` = 164;  -- ASPD+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 166, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 164 WHERE `OptionType` = 165;  -- ASPD+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 167, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 165 WHERE `OptionType` = 166;  -- ASPD+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 168, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 166 WHERE `OptionType` = 167;  -- ASPD+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 167 WHERE `OptionType` = 168;  -- ASPD+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 170, `UpgradeThirdRatio` = 50, `PreviousOptionType` = 87 WHERE `OptionType` = 169;  -- CRI+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 171, `UpgradeThirdRatio` = 35, `PreviousOptionType` = 169 WHERE `OptionType` = 170;  -- CRI+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 172, `UpgradeThirdRatio` = 25, `PreviousOptionType` = 170 WHERE `OptionType` = 171;  -- CRI+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 173, `UpgradeThirdRatio` = 15, `PreviousOptionType` = 171 WHERE `OptionType` = 172;  -- CRI+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 172 WHERE `OptionType` = 173;  -- CRI+10
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 174;  -- HPRGN+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 175;  -- LUCK+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 178;  -- RES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 90 WHERE `OptionType` = 179;  -- RES+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 80 WHERE `OptionType` = 180;  -- RES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 99 WHERE `OptionType` = 183;  -- ATTR+1
