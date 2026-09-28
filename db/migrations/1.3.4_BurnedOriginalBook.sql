-- 1.3.4_BurnedOriginalBook.sql
--
-- Burned Original Book (타버린 원본서), CommonQuestItem 53: a collectable that players will trade in for
-- the JC (post level 150 job change) skill books - Dragon Hurricane, Bless 2, Infinity Lightning Bolt and
-- the rest. The pre-JC books already drop from monsters (tools/gen_skillbook_drops.py); the JC books will
-- only come from this item. The exchange NPC is a later change.
--
-- Numbering: DK670 calls it CommonQuestItem 52 and 63, but this server's 52 is Moon Crystal and 63 is
-- Elixir Fragment. 53 is the first free type here (53-55 have no row and nothing in code, scripts, data
-- files or other tables refers to them; 57 is also rowless but NewYear2005ItemUtil.cpp creates it). The
-- client's item.en.inf class 91 already has a filler row at 53, which the client patch overwrites with
-- the name, description and DK670's art (inventory 1684, ground 1642, drop 1642).
--
-- Ships with gameserver code: MonsterManager::addItem rolls it 1 in 300 on every level 150+ monster
-- (next to Forbidden Blood's 1 in 500). That code checks for this row first, so a binary running on a
-- database without this migration simply drops nothing.
--
-- Rollback: db/rollback/1.3.4_BurnedOriginalBook_rollback.sql

SET NAMES binary;

INSERT INTO `CommonQuestItemInfo`
    (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `BonusRatio`, `Race`)
VALUES
    (53, X'C5B8B9F6B8B020BFF8BABBBCAD', 'Burned Original Book', 1, 1, 1, 0, 0, 0, 7)
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
