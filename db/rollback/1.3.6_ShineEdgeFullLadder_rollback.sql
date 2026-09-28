-- 1.3.6_ShineEdgeFullLadder_rollback.sql
--
-- Undo db/migrations/1.3.6_ShineEdgeFullLadder.sql: every row it touched gets its pre-1.3.6 values back.
-- NOT a migration - run by hand, then restart the gameserver:
--     mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.3.6_ShineEdgeFullLadder_rollback.sql
-- Options players already upgraded along the ladder keep their new tier.
-- Removes the 1.3.6 SchemaVersion row; deploy_db.py would re-apply it unless the file is removed first.

SET NAMES utf8mb4;

UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 1;  -- STR+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 2;  -- STR+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 3;  -- STR+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 4;  -- STR+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 5;  -- STR+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 6;  -- DEX+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 7;  -- DEX+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 8;  -- DEX+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 9;  -- DEX+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 10;  -- DEX+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 11;  -- INT+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 12;  -- INT+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 13;  -- INT+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 14;  -- INT+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 15;  -- INT+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 16;  -- HP+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 17;  -- HP+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 18;  -- HP+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 19;  -- HP+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 20;  -- HP+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 21;  -- MP+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 22;  -- MP+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 23;  -- MP+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 24;  -- MP+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 25;  -- MP+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 26;  -- HPSTL+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 27;  -- HPSTL+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 28;  -- HPSTL+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 29;  -- MPSTL+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 30;  -- MPSTL+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 31;  -- MPSTL+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 33;  -- HPRGN+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 34;  -- HPRGN+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 35;  -- MPRGN+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 36;  -- MPRGN+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 37;  -- MPRGN+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 38;  -- TOHIT+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 39;  -- TOHIT+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 40;  -- TOHIT+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 41;  -- TOHIT+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 42;  -- TOHIT+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 43;  -- DEF+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 44;  -- DEF+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 45;  -- DEF+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 46;  -- DEF+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 47;  -- DEF+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 48;  -- DAM+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 49;  -- DAM+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 50;  -- DAM+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 51;  -- DAM+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 52;  -- DAM+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 53;  -- PRO+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 54;  -- PRO+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 55;  -- PRO+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 56;  -- PRO+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 57;  -- PRO+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 58;  -- DUR+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 59;  -- DUR+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 60;  -- DUR+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 61;  -- DUR+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 62;  -- DUR+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 63;  -- PORES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 64;  -- PORES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 65;  -- PORES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 66;  -- ACRES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 67;  -- ACRES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 68;  -- ACRES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 69;  -- CURES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 70;  -- CURES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 71;  -- CURES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 72;  -- BLRES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 73;  -- BLRES+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 74;  -- BLRES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 75;  -- VIS+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 76;  -- VIS+2
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 77;  -- VIS+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 78;  -- ASPD+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 79;  -- ASPD+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 80;  -- ASPD+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 81;  -- ASPD+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 82;  -- ASPD+5
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 83;  -- CRI+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 84;  -- CRI+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 85;  -- CRI+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 86;  -- CRI+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0 WHERE `OptionType` = 87;  -- CRI+5
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 88;  -- STR+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 89;  -- STR+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 90;  -- STR+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 91;  -- STR+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 92;  -- STR+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 93;  -- DEX+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 94;  -- DEX+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 95;  -- DEX+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 96;  -- DEX+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 97;  -- DEX+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 98;  -- INT+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 99;  -- INT+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 100;  -- INT+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 101;  -- INT+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 102;  -- INT+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 103;  -- HP+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 104;  -- HP+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 105;  -- HP+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 106;  -- HP+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 107;  -- HP+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 108;  -- MP+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 109;  -- MP+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 110;  -- MP+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 111;  -- MP+9
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 112;  -- HPSTL+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 113;  -- HPSTL+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 114;  -- HPSTL+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 115;  -- MPSTL+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 116;  -- MPSTL+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 117;  -- MPSTL+6
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 118;  -- HPRGN+4
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 119;  -- HPRGN+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 120;  -- HPRGN+6
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 121;  -- MPRGN+4
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 122;  -- MPRGN+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 123;  -- MPRGN+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 124;  -- TOHIT+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 125;  -- TOHIT+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 126;  -- TOHIT+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 127;  -- TOHIT+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 128;  -- TOHIT+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 129;  -- DEF+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 130;  -- DEF+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 131;  -- DEF+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 132;  -- DEF+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 133;  -- DEF+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 134;  -- DAM+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 135;  -- DAM+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 136;  -- DAM+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 137;  -- DAM+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 138;  -- DAM+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 139;  -- PRO+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 140;  -- PRO+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 141;  -- PRO+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 142;  -- PRO+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 143;  -- PRO+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 144;  -- DUR+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 145;  -- DUR+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 146;  -- DUR+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 147;  -- DUR+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 148;  -- DUR+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 149;  -- PORES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 150;  -- PORES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 151;  -- PORES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 152;  -- ACRES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 153;  -- ACRES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 154;  -- ACRES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 155;  -- CURES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 156;  -- CURES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 157;  -- CURES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 158;  -- BLRES+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 159;  -- BLRES+5
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 160;  -- BLRES+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 161;  -- VIS+4
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 162;  -- VIS+5
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 163;  -- VIS+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 164;  -- ASPD+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 165;  -- ASPD+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 166;  -- ASPD+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 167;  -- ASPD+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 168;  -- ASPD+10
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 169;  -- CRI+6
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 170;  -- CRI+7
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 171;  -- CRI+8
UPDATE `OptionInfo` SET `UpgradeOptionType` = 0, `UpgradeThirdRatio` = 0, `PreviousOptionType` = 0 WHERE `OptionType` = 172;  -- CRI+9
UPDATE `OptionInfo` SET `PreviousOptionType` = 0 WHERE `OptionType` = 173;  -- CRI+10
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 174;  -- HPRGN+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 175;  -- LUCK+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 178;  -- RES+1
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 179;  -- RES+2
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 180;  -- RES+3
UPDATE `OptionInfo` SET `UpgradeThirdRatio` = 0 WHERE `OptionType` = 183;  -- ATTR+1
DELETE FROM `SchemaVersion` WHERE `Major` = 1 AND `Minor` = 3 AND `Bug` = 6;
