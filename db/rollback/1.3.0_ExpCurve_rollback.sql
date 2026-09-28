-- 1.3.0_ExpCurve_rollback.sql
--
-- Undo db/migrations/1.3.0_ExpCurve.sql. NOT a migration: deploy_db.py never runs this. Run it by hand
-- against the same database, then restart the gameserver:
--
--     mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.3.0_ExpCurve_rollback.sql
--
-- It restores the four EXP tables and every character's remaining-GoalExp columns from the
-- ExpCurve130_Backup_* tables the migration created, puts the monster Exp bonuses back, and removes the
-- 1.3.0 row from SchemaVersion so the database reports 1.2.5 again. (deploy_db.py would then re-apply
-- 1.3.0 on the next deploy: delete or rename the migration file too if the rollback is meant to stick.)
--
-- Characters get back exactly the remaining EXP they had when the migration ran, so progress made under
-- the new curve is lost, not converted. Characters created after the migration are not in the backup and
-- keep their current GoalExp; with the old tables that is less than a level's worth, so they simply
-- level up on their next kill.
--
-- Safe to run twice. Fails with "table doesn't exist" if the backup tables were dropped; there is no
-- other copy of the old values.

SET NAMES utf8mb4;

UPDATE `VampEXPBalanceInfo` e JOIN `ExpCurve130_Backup_VampEXPBalanceInfo` b ON b.`Level` = e.`Level`
  SET e.`GoalExp` = b.`GoalExp`, e.`AccumExp` = b.`AccumExp`;
UPDATE `OustersEXPBalanceInfo` e JOIN `ExpCurve130_Backup_OustersEXPBalanceInfo` b ON b.`Level` = e.`Level`
  SET e.`GoalExp` = b.`GoalExp`, e.`AccumExp` = b.`AccumExp`;
UPDATE `SkillDomainInfo` d JOIN `ExpCurve130_Backup_SkillDomainInfo` b ON b.`DomainType` = d.`DomainType` AND b.`Level` = d.`Level`
  SET d.`GoalExp` = b.`GoalExp`, d.`AccumExp` = b.`AccumExp`;
UPDATE `AdvancementClassEXPInfo` a JOIN `ExpCurve130_Backup_AdvancementClassEXPInfo` b ON b.`Level` = a.`Level`
  SET a.`GoalExp` = b.`GoalExp`, a.`AccumExp` = b.`AccumExp`;

UPDATE `Vampire` v JOIN `ExpCurve130_Backup_CharGoals` b ON b.`Race` = 'VAMPIRE' AND b.`CharID` = v.`CharID`
  SET v.`GoalExp` = b.`GoalExp`, v.`AdvancementGoalExp` = b.`AdvancementGoalExp`;
UPDATE `Ousters` o JOIN `ExpCurve130_Backup_CharGoals` b ON b.`Race` = 'OUSTERS' AND b.`CharID` = o.`CharID`
  SET o.`GoalExp` = b.`GoalExp`, o.`AdvancementGoalExp` = b.`AdvancementGoalExp`;
UPDATE `Slayer` s JOIN `ExpCurve130_Backup_CharGoals` b ON b.`Race` = 'SLAYER' AND b.`CharID` = s.`CharID`
  SET s.`BladeGoalExp` = b.`BladeGoalExp`, s.`SwordGoalExp` = b.`SwordGoalExp`, s.`GunGoalExp` = b.`GunGoalExp`,
      s.`HealGoalExp` = b.`HealGoalExp`, s.`EnchantGoalExp` = b.`EnchantGoalExp`,
      s.`AdvancementGoalExp` = b.`AdvancementGoalExp`;

UPDATE `MonsterInfo` SET `Exp` = 0   WHERE `MType` IN (493,494,495,496,497,498,499,500,501,502,624,625,626,627,628,629,630,631,632,633,718,754,755,756,757,758,759,760,761,762,763,778,779,786) AND `Exp` = 300;
UPDATE `MonsterInfo` SET `Exp` = 0   WHERE `MType` IN (894,895,896,897,898,899,900,901,902,903,904,905,906,907) AND `Exp` = 400;
UPDATE `MonsterInfo` SET `Exp` = 100 WHERE `MType` IN (1152,1153,1154,1155,1156) AND `Exp` = 400;
UPDATE `MonsterInfo` SET `Exp` = 0   WHERE `MType` IN (461,463,477,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603) AND `Exp` = 200;

DELETE FROM `SchemaVersion` WHERE `Major` = 1 AND `Minor` = 3 AND `Bug` = 0;

-- Once the rollback is confirmed and the backups are no longer wanted:
-- DROP TABLE `ExpCurve130_Backup_VampEXPBalanceInfo`, `ExpCurve130_Backup_OustersEXPBalanceInfo`,
--            `ExpCurve130_Backup_SkillDomainInfo`, `ExpCurve130_Backup_AdvancementClassEXPInfo`,
--            `ExpCurve130_Backup_CharGoals`;
