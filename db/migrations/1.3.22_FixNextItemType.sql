-- 1.3.22 fix NextItemType in every item table.
-- A missing target is set to self.
-- Each ADV line links to the next step of the same gender or element.
-- Coat/trouser use the M/W name, because Muscle Suit has the GEN flag swapped.
-- Valkirie suits no longer point back at Combat Mail. Safe to rerun.
SET NAMES latin1;

-- ARInfo
UPDATE `ARInfo` SET NextItemType=18 WHERE ItemType=14;
UPDATE `ARInfo` SET NextItemType=22 WHERE ItemType=22;

-- BeltInfo
UPDATE `BeltInfo` SET NextItemType=11 WHERE ItemType=11;

-- BladeInfo
UPDATE `BladeInfo` SET NextItemType=18 WHERE ItemType=14;
UPDATE `BladeInfo` SET NextItemType=22 WHERE ItemType=22;

-- BraceletInfo
UPDATE `BraceletInfo` SET NextItemType=17 WHERE ItemType=16;
UPDATE `BraceletInfo` SET NextItemType=18 WHERE ItemType=17;
UPDATE `BraceletInfo` SET NextItemType=18 WHERE ItemType=18;

-- CarryingReceiverInfo

-- CoatInfo
UPDATE `CoatInfo` SET NextItemType=26 WHERE ItemType=24;
UPDATE `CoatInfo` SET NextItemType=27 WHERE ItemType=25;
UPDATE `CoatInfo` SET NextItemType=32 WHERE ItemType=26;
UPDATE `CoatInfo` SET NextItemType=33 WHERE ItemType=27;
UPDATE `CoatInfo` SET NextItemType=30 WHERE ItemType=30;
UPDATE `CoatInfo` SET NextItemType=31 WHERE ItemType=31;
UPDATE `CoatInfo` SET NextItemType=34 WHERE ItemType=34;
UPDATE `CoatInfo` SET NextItemType=35 WHERE ItemType=35;

-- CrossInfo
UPDATE `CrossInfo` SET NextItemType=16 WHERE ItemType=12;
UPDATE `CrossInfo` SET NextItemType=20 WHERE ItemType=20;

-- DermisInfo

-- FasciaInfo

-- GloveInfo
UPDATE `GloveInfo` SET NextItemType=14 WHERE ItemType=14;

-- HelmInfo
UPDATE `HelmInfo` SET NextItemType=14 WHERE ItemType=13;

-- MaceInfo
UPDATE `MaceInfo` SET NextItemType=16 WHERE ItemType=12;
UPDATE `MaceInfo` SET NextItemType=20 WHERE ItemType=20;

-- MittenInfo

-- NecklaceInfo
UPDATE `NecklaceInfo` SET NextItemType=18 WHERE ItemType=17;
UPDATE `NecklaceInfo` SET NextItemType=18 WHERE ItemType=18;

-- OustersArmsbandInfo
UPDATE `OustersArmsbandInfo` SET NextItemType=17 WHERE ItemType=17;

-- OustersBootsInfo
UPDATE `OustersBootsInfo` SET NextItemType=17 WHERE ItemType=17;

-- OustersChakramInfo
UPDATE `OustersChakramInfo` SET NextItemType=18 WHERE ItemType=14;
UPDATE `OustersChakramInfo` SET NextItemType=22 WHERE ItemType=22;

-- OustersCircletInfo
UPDATE `OustersCircletInfo` SET NextItemType=16 WHERE ItemType=16;

-- OustersCoatInfo
UPDATE `OustersCoatInfo` SET NextItemType=13 WHERE ItemType=12;
UPDATE `OustersCoatInfo` SET NextItemType=17 WHERE ItemType=17;

-- OustersPendentInfo
UPDATE `OustersPendentInfo` SET NextItemType=18 WHERE ItemType=17;

-- OustersRingInfo
UPDATE `OustersRingInfo` SET NextItemType=19 WHERE ItemType=18;

-- OustersStoneInfo
UPDATE `OustersStoneInfo` SET NextItemType=27 WHERE ItemType=19;
UPDATE `OustersStoneInfo` SET NextItemType=28 WHERE ItemType=21;
UPDATE `OustersStoneInfo` SET NextItemType=29 WHERE ItemType=23;
UPDATE `OustersStoneInfo` SET NextItemType=27 WHERE ItemType=27;
UPDATE `OustersStoneInfo` SET NextItemType=28 WHERE ItemType=28;
UPDATE `OustersStoneInfo` SET NextItemType=29 WHERE ItemType=29;

-- OustersWristletInfo
UPDATE `OustersWristletInfo` SET NextItemType=54 WHERE ItemType=42;
UPDATE `OustersWristletInfo` SET NextItemType=55 WHERE ItemType=43;
UPDATE `OustersWristletInfo` SET NextItemType=56 WHERE ItemType=44;
UPDATE `OustersWristletInfo` SET NextItemType=64 WHERE ItemType=64;
UPDATE `OustersWristletInfo` SET NextItemType=66 WHERE ItemType=66;
UPDATE `OustersWristletInfo` SET NextItemType=68 WHERE ItemType=68;

-- PersonaInfo
UPDATE `PersonaInfo` SET NextItemType=1 WHERE ItemType=1;

-- RingInfo
UPDATE `RingInfo` SET NextItemType=19 WHERE ItemType=18;

-- SGInfo

-- SMGInfo

-- SRInfo
UPDATE `SRInfo` SET NextItemType=18 WHERE ItemType=14;
UPDATE `SRInfo` SET NextItemType=22 WHERE ItemType=22;

-- ShieldInfo
UPDATE `ShieldInfo` SET NextItemType=14 WHERE ItemType=13;
UPDATE `ShieldInfo` SET NextItemType=17 WHERE ItemType=17;

-- ShoesInfo
UPDATE `ShoesInfo` SET NextItemType=13 WHERE ItemType=13;

-- ShoulderArmorInfo

-- SwordInfo
UPDATE `SwordInfo` SET NextItemType=18 WHERE ItemType=14;
UPDATE `SwordInfo` SET NextItemType=22 WHERE ItemType=22;

-- TrouserInfo
UPDATE `TrouserInfo` SET NextItemType=26 WHERE ItemType=24;
UPDATE `TrouserInfo` SET NextItemType=27 WHERE ItemType=25;
UPDATE `TrouserInfo` SET NextItemType=32 WHERE ItemType=26;
UPDATE `TrouserInfo` SET NextItemType=33 WHERE ItemType=27;
UPDATE `TrouserInfo` SET NextItemType=30 WHERE ItemType=30;
UPDATE `TrouserInfo` SET NextItemType=31 WHERE ItemType=31;
UPDATE `TrouserInfo` SET NextItemType=34 WHERE ItemType=34;
UPDATE `TrouserInfo` SET NextItemType=35 WHERE ItemType=35;

-- VampireAmuletInfo
UPDATE `VampireAmuletInfo` SET NextItemType=17 WHERE ItemType=17;

-- VampireBraceletInfo
UPDATE `VampireBraceletInfo` SET NextItemType=15 WHERE ItemType=15;

-- VampireCoatInfo
UPDATE `VampireCoatInfo` SET NextItemType=22 WHERE ItemType=20;
UPDATE `VampireCoatInfo` SET NextItemType=23 WHERE ItemType=21;
UPDATE `VampireCoatInfo` SET NextItemType=24 WHERE ItemType=22;
UPDATE `VampireCoatInfo` SET NextItemType=25 WHERE ItemType=23;
UPDATE `VampireCoatInfo` SET NextItemType=34 WHERE ItemType=28;
UPDATE `VampireCoatInfo` SET NextItemType=35 WHERE ItemType=29;
UPDATE `VampireCoatInfo` SET NextItemType=32 WHERE ItemType=32;
UPDATE `VampireCoatInfo` SET NextItemType=33 WHERE ItemType=33;
UPDATE `VampireCoatInfo` SET NextItemType=30 WHERE ItemType=34;
UPDATE `VampireCoatInfo` SET NextItemType=31 WHERE ItemType=35;

-- VampireEarringInfo
UPDATE `VampireEarringInfo` SET NextItemType=17 WHERE ItemType=16;
UPDATE `VampireEarringInfo` SET NextItemType=18 WHERE ItemType=17;
UPDATE `VampireEarringInfo` SET NextItemType=18 WHERE ItemType=18;

-- VampireNecklaceInfo
UPDATE `VampireNecklaceInfo` SET NextItemType=18 WHERE ItemType=17;

-- VampireRingInfo
UPDATE `VampireRingInfo` SET NextItemType=19 WHERE ItemType=18;

-- VampireWeaponInfo
UPDATE `VampireWeaponInfo` SET NextItemType=20 WHERE ItemType=19;
UPDATE `VampireWeaponInfo` SET NextItemType=23 WHERE ItemType=20;
UPDATE `VampireWeaponInfo` SET NextItemType=27 WHERE ItemType=27;

