-- 1.3.7_MihneaRitual.sql
--
-- Dracula Castle: the Mihnea ritual that opens the 2nd floor (DraculaCastleManager in the gameserver).
--
--   * Mihnea's Storage (NPC 1202, sprite set 350: the altar with the Mihnea burning on it) stands on 1F at
--     103/134. Every 12 hours from server start its seal fades; talking to it then hands over the Mihnea.
--   * The Mihnea Altar (NPC 1203, sprite set 351: the empty altar) stands by the 2F stairs at 204/47. Its
--     cage drops 5 minutes after the Mihnea was taken; placing the Mihnea there breaks the door across the
--     stairs, which stands again when the next Vlad II Dracul appears on 2F.
--   * The Mihnea itself is CommonQuestItem 91/64. Carrying it works like a Blood Bible (no attacks, half
--     speed, dropped on death/logout/leaving 1F); it never gets an ItemObject row - it exists only while a
--     ritual runs, so no ItemObject/CommonQuestItemObject data is touched here.
--
-- The NPCs are placed by their AtFirst triggers, as every NPC is, and the dialogue rows mirror Marcus's
-- (5906-5909 / Script 20300). The client's creature.en.inf 1202/1203, NPCScript.en.inf 20301/20302,
-- item.en.inf 91/64 and the door's effectstatus/action rows ship separately.
--
-- Idempotent: ON DUPLICATE KEY UPDATE for keyed rows; the trigger rows are replaced by NPC name.

SET NAMES utf8mb4;

-- ------------------------------------------------------------------------------------------ NPCs
INSERT INTO `NPC`
    (`Name`, `NPCID`, `SpriteType`, `Race`, `MainColor`, `SubColor`, `ZoneID`, `ClanType`, `ShowInMinimap`,
     `Description`, `TaxingCastleZoneID`, `NpcFace`)
VALUES
    ('Mihnea Storage', 1202, 350, 4, 1, 1, 6051, 0, 1, '', 0, 0),
    ('Mihnea Altar',   1203, 351, 4, 1, 1, 6051, 0, 1, '', 0, 0)
ON DUPLICATE KEY UPDATE
    `NPCID`         = VALUES(`NPCID`),
    `SpriteType`    = VALUES(`SpriteType`),
    `Race`          = VALUES(`Race`),
    `MainColor`     = VALUES(`MainColor`),
    `SubColor`      = VALUES(`SubColor`),
    `ClanType`      = VALUES(`ClanType`),
    `ShowInMinimap` = VALUES(`ShowInMinimap`);

-- ------------------------------------------------------------------------------------------ dialogue
INSERT INTO `Script` (`ScriptID`, `OwnerID`, `Subject`, `Content`)
VALUES
    (20301, 'Mihnea Storage',
     'The Mihnea rests on its altar, wreathed in cold fire. Whoever carries it cannot fight and walks slowly, and it falls where its bearer falls. Take it to the altar by the stairs to the 2nd floor.',
     'Take the Mihnea.\n**Leave.'),
    (20302, 'Mihnea Altar',
     'An empty altar stands before the door to the 2nd floor. Its cage opens five minutes after the Mihnea leaves its storage. Place the Mihnea here and the door breaks.',
     'Place the Mihnea.\n**Leave.')
ON DUPLICATE KEY UPDATE
    `OwnerID` = VALUES(`OwnerID`),
    `Subject` = VALUES(`Subject`),
    `Content` = VALUES(`Content`);

-- ------------------------------------------------------------------------------------------ triggers
DELETE FROM `Triggers` WHERE `NPC` IN ('Mihnea Storage', 'Mihnea Altar');

INSERT INTO `Triggers` (`TriggerType`, `NPC`, `QuestID`, `Conditions`, `Actions`)
VALUES
    ('NPC', 'Mihnea Storage', 0,
     'ConditionType : AtFirst',
     'ActionType : SetPosition\n\t\tZoneID : 6051\n\t\tX : 103\n\t\tY : 134\n\t\tDir : 2'),
    ('NPC', 'Mihnea Storage', 0,
     'ConditionType : TalkedBy',
     'ActionType : Ask\n\t\tScriptID : 20301'),
    ('NPC', 'Mihnea Storage', 0,
     'ConditionType : AnsweredBy\n\t\tScriptID : 20301\n\t\tAnswerID : 1',
     'ActionType : TakeMihnea'),
    ('NPC', 'Mihnea Storage', 0,
     'ConditionType : AnsweredBy\n\t\tScriptID : 20301\n\t\tAnswerID : 2',
     'ActionType : QuitDialogue'),

    ('NPC', 'Mihnea Altar', 0,
     'ConditionType : AtFirst',
     'ActionType : SetPosition\n\t\tZoneID : 6051\n\t\tX : 204\n\t\tY : 47\n\t\tDir : 2'),
    ('NPC', 'Mihnea Altar', 0,
     'ConditionType : TalkedBy',
     'ActionType : Ask\n\t\tScriptID : 20302'),
    ('NPC', 'Mihnea Altar', 0,
     'ConditionType : AnsweredBy\n\t\tScriptID : 20302\n\t\tAnswerID : 1',
     'ActionType : PlaceMihnea'),
    ('NPC', 'Mihnea Altar', 0,
     'ConditionType : AnsweredBy\n\t\tScriptID : 20302\n\t\tAnswerID : 2',
     'ActionType : QuitDialogue');

-- ------------------------------------------------------------------------------------------ the Mihnea
-- Name is CP949 for the Korean column, as in 1.1.12 (Elixir Fragment); the client shows its own item.en.inf name.
INSERT INTO `CommonQuestItemInfo`
    (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `BonusRatio`, `Race`)
VALUES
    (64, _latin1 X'B9CCC8E5B3D7BEC6', 'Mihnea', 1, 1, 1, 0, 0, 0, 7)
ON DUPLICATE KEY UPDATE
    `Name`       = VALUES(`Name`),
    `EName`      = VALUES(`EName`),
    `Price`      = VALUES(`Price`),
    `Volume`     = VALUES(`Volume`),
    `Weight`     = VALUES(`Weight`),
    `Ratio`      = VALUES(`Ratio`),
    `ItemLevel`  = VALUES(`ItemLevel`),
    `BonusRatio` = VALUES(`BonusRatio`),
    `Race`       = VALUES(`Race`);
