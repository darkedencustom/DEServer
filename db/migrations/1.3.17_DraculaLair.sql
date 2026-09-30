-- 1.3.11 Dracula Castle 2F lair
-- Vlad II Dracul is spawned by the DraculaCastleManager at the end of the 5-minute lair countdown
-- (started when the Mihnea is placed on the altar), at 2F 60/80, so the zone's own spawn list must not
-- put him up every hour any more. Everything else about the lair (timer, fire pillars in the hallways,
-- PvE, resurrect at the entrance) is code.
UPDATE ZoneInfo SET EventMonsterList = ''
 WHERE ZoneID = 6052 AND EventMonsterList = '(1196,1,3600)';
