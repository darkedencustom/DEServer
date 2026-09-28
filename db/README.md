# db/ - the DARKEDEN database

| File | What it is |
|---|---|
| `DARKEDEN_skeleton.sql` | Schema **1.0.0**: every table, the content rows the game is built from, nothing a player made. Written by `make_skeleton.py`. |
| `migrations/` | Every change since, one file each. |
| `deploy_db.py` | Skeleton + the migrations a database has not had yet. |
| `create_account.py` | Make an account that can log in. |
| `make_skeleton.py` | Regenerate the skeleton from the live database. |
| `dbconn.py` | Shared by the scripts. |

## Deploying

```bash
export DE_DB_PASSWORD=...          # or --password, or be asked
./deploy_db.py status              # version, history, what is pending
./deploy_db.py --dry-run           # what a deploy would do
./deploy_db.py                     # do it
./create_account.py myname mypassword
```

An empty or missing database gets the skeleton, then every migration. A
database that is already tracked gets only the migrations newer than its
version. The version lives in the `SchemaVersion` table; a migration is
recorded only after it ran clean.

A database built before this existed has tables but no `SchemaVersion`. It is
never guessed at. If it matches the skeleton, say so once:

```bash
./deploy_db.py --baseline 1.0.0
```

Other connection settings: `--host --port --user --db`, or `$DE_DB_HOST`,
`$DE_DB_PORT`, `$DE_DB_USER`, `$DE_DB_NAME`. `--db` lets you deploy a second
copy (`--db DARKEDEN_TEST`) to try a migration without touching the real one.

After a first deploy, edit the rows that describe the installation:
`GameServerInfo`, `GameServerGroupInfo`, `WorldInfo`, `WorldDBInfo`,
`CastleStatInfo`, `ClientVersion`, `IPAllowInfo`, `IPBlockInfo`.

## Writing a migration

**Never change the database by hand and never edit the skeleton.** Add the next
file to `migrations/`:

    <Major>.<Minor>.<Bug>_<ShortDescription>.sql      1.1.0_CharIDUpdate.sql

Pick the number by the size of the change: a fix bumps Bug (`1.1.1_...`), a
feature or a structural change bumps Minor (`1.2.0_...`). Running the file makes
the database that version. Two files may not share a number, and a number below
the database's current version will not run, so always go up.

Rules that keep a deploy repeatable:

* **Safe to run twice.** MySQL commits every `ALTER` on its own, so a migration
  that fails half way leaves half its work behind, and is simply run again.
  Check `information_schema` before each step (see `1.1.0_CharIDUpdate.sql`),
  use `CREATE TABLE IF NOT EXISTS`, `INSERT IGNORE`, `DROP ... IF EXISTS`.
* **No database name** in the file. The deploy script selects it; use
  `DATABASE()` when you query `information_schema`.
* **Open with `SET NAMES`.** The file is sent with a `latin1` client, which
  passes bytes through unparsed. `SET NAMES utf8mb4;` for plain ASCII DDL and
  routines; `SET NAMES binary;` before rows that carry CP949 Korean for the
  `latin1` tables. Do **not** run the client as `binary`: it cannot parse its
  own `DELIMITER` command under it and cuts every `BEGIN ... END` at the first
  semicolon.
* A migration that the server code depends on ships with that code, and says so
  in its header.

## Characters, names and CharID (schema 1.1.0)

`Slayer` is the registry: creating a character of any race inserts a `Slayer`
row (`Race` says which), then the `Vampire` or `Ousters` row. `Slayer.CharID` is
the one place an id is issued. It is the first column and primary key of all
three tables; `Vampire.CharID` and `Ousters.CharID` are foreign keys to it and
are filled by a `BEFORE INSERT` trigger. `Name` is unique among the rows that
have one.

Deleting a character keeps it. `CLDeletePCHandler` sets `Active='INACTIVE'` and
calls `sp_RetireCharacter`, after which the character is known by its CharID
alone: its key in every name-keyed column is `~<CharID>` and the name it had is
in `Slayer.RetiredName`. The name is free at once and a new character of that
name inherits nothing.

```sql
CALL sp_RetireCharacter('Anna');     -- what a delete does
CALL sp_RestoreCharacter(15);        -- bring CharID 15 back, if its name is still free
SELECT CharID, RetiredName, PlayerID FROM Slayer WHERE RetiredName IS NOT NULL;
```

A name-keyed column that is not called `OwnerID` has to be listed in
`CharacterNameRef`, or a reused name inherits its rows. Add the row in a
migration when such a table appears.

## Rolling back

Migrations only go forward, so a change that may need undoing ships its own
rollback in `rollback/`, named after the migration (`rollback/1.3.0_ExpCurve_rollback.sql`
undoes `migrations/1.3.0_ExpCurve.sql`). `deploy_db.py` never runs these; run
one by hand against the same database, then restart the gameserver:

```bash
mysql --default-character-set=utf8mb4 -h 127.0.0.1 -u elcastle -p DARKEDEN < db/rollback/1.3.0_ExpCurve_rollback.sql
```

A rollback restores what the migration saved into its `*_Backup_*` tables and
deletes the migration's `SchemaVersion` row, so the database reports the
previous version again. The next deploy would re-apply the migration unless
its file is removed or renamed first.
