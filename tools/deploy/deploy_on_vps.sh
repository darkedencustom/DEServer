#!/bin/bash
#-----------------------------------------------------------------------------
# Runs ON the VPS; .github/workflows/deploy-server.yml uploads and calls it.
#
#   deploy_on_vps.sh <server dir> <stage dir> deploy|dry-run <commit>
#
# The stage dir holds what the workflow uploaded:
#   servers.tar.gz   bin/gameserver, bin/loginserver, bin/sharedserver
#                    (absent: the binaries on the VPS stay as they are)
#   db/              the repo's db/ folder: deploy_db.py, migrations/, ...
#
# The database password arrives on stdin, never on a command line.
# DE_DB_HOST / DE_DB_PORT / DE_DB_USER / DE_DB_NAME come from the environment.
#
# It never stops, starts or restarts a server. What it does:
#   1. checks the database's version, and that the new binaries find every
#      library on this VPS
#   2. copies the live database to <name>_deploytest and runs the pending
#      migrations there; the live database is touched only if every one of
#      them passes on the copy
#   3. replaces db/ and runs the same migrations on the live database
#   4. moves the new binaries into bin/; the running servers keep the old ones
#      until someone restarts them
# A dry run stops after 2.
#-----------------------------------------------------------------------------
set -euo pipefail

DIR=$1
STAGE=$2
MODE=$3
COMMIT=${4:-unknown}
BIN="$DIR/bin"
DB="${DE_DB_NAME:-DARKEDEN}"
SCRATCH="${DB}_deploytest"
SERVERS=(gameserver loginserver sharedserver)

IFS= read -r DE_DB_PASSWORD || true
export DE_DB_PASSWORD
if [ -z "$DE_DB_PASSWORD" ]; then
    echo "no database password on stdin" >&2
    exit 1
fi

# the mysql/mysqldump login for the copy, in a private file like dbconn.py's
CNF=$(mktemp)
chmod 600 "$CNF"
pw=${DE_DB_PASSWORD//\\/\\\\}
pw=${pw//\"/\\\"}
printf '[client]\nhost=%s\nport=%s\nuser=%s\npassword="%s"\n' \
    "${DE_DB_HOST:-127.0.0.1}" "${DE_DB_PORT:-3306}" "${DE_DB_USER:-elcastle}" "$pw" > "$CNF"
unset pw

scratch_made=""
DUMP="$STAGE/live.sql"		# the copy in transit; holds player data
cleanup() {
    if [ -n "$scratch_made" ]; then
        mysql --defaults-extra-file="$CNF" -e "DROP DATABASE IF EXISTS \`$SCRATCH\`" || true
    fi
    rm -f "$CNF" "$DUMP" "$DUMP.tmp"
}
trap cleanup EXIT

say() { printf '\n== %s\n' "$*"; }
# the pattern start.local.sh and stop.local.sh use; [.] keeps it off pgrep's own line
running() { pgrep -f "[.]/$1 -f" > /dev/null; }

#----------------------------------------------------------------- 1. checks
say "database"
status=$(python3 "$STAGE/db/deploy_db.py" status --migrations "$STAGE/db/migrations" 2>&1) || {
    echo "$status" >&2
    exit 1
}
echo "$status"
case "$status" in
    *"missing or empty"*)
        echo "refusing: \`$DB\` is missing or empty, and a deploy would import the skeleton into it" >&2
        exit 1 ;;
    *"no SchemaVersion table"*)
        echo "refusing: the database's version is unknown; declare it once with deploy_db.py --baseline" >&2
        exit 1 ;;
esac
pending=""
if ! printf '%s\n' "$status" | grep -qx 'pending: nothing'; then pending=1; fi

if [ -f "$STAGE/servers.tar.gz" ]; then
    say "new binaries"
    mkdir -p "$STAGE/new"
    tar -xzf "$STAGE/servers.tar.gz" -C "$STAGE/new"
    for s in "${SERVERS[@]}"; do
        if [ ! -x "$STAGE/new/bin/$s" ]; then
            echo "servers.tar.gz has no bin/$s" >&2
            exit 1
        fi
        missing=$(ldd "$STAGE/new/bin/$s" | grep "not found" || true)
        if [ -n "$missing" ]; then
            echo "$s needs libraries this VPS does not have:" >&2
            echo "$missing" >&2
            exit 1
        fi
        printf '  %-13s %s bytes\n' "$s" "$(stat -c %s "$STAGE/new/bin/$s")"
    done
else
    say "binaries: keeping the ones in $BIN"
fi

#----------------------------------------------------------------- 2. rehearsal
if [ -n "$pending" ]; then
    say "rehearsing the migrations on a copy: \`$SCRATCH\`"
    echo "client: $(mysql --version)"
    echo "server: $(mysql --defaults-extra-file="$CNF" -N -e 'SELECT VERSION()')"
    copy_failed() {
        echo >&2
        echo "could not copy \`$DB\` to \`$SCRATCH\`, so nothing was migrated." >&2
        case "$1" in
            *"denied"*)
                echo "The account ${DE_DB_USER:-elcastle} needs CREATE, DROP, TRIGGER and CREATE ROUTINE on" >&2
                echo "\`$SCRATCH\`, and SELECT, SHOW VIEW, TRIGGER and SHOW_ROUTINE on \`$DB\`." >&2 ;;
        esac
        exit 1
    }
    # binary out, latin1 in, as make_skeleton.py does: the latin1 tables hold
    # CP949 bytes that any conversion would corrupt. The procedures' DEFINER
    # becomes CURRENT_USER and the triggers are rewritten as plain CREATE TRIGGER
    # (plain_triggers.awk says why), so the copy belongs to the deploy account.
    # The dump holds player data: private files, removed on the way out.
    scratch_made=1
    err=$(mysql --defaults-extra-file="$CNF" -e "DROP DATABASE IF EXISTS \`$SCRATCH\`; CREATE DATABASE \`$SCRATCH\`" 2>&1) || { echo "$err" >&2; copy_failed "$err"; }
    err=$( (umask 077; mysqldump --defaults-extra-file="$CNF" --default-character-set=binary \
              --single-transaction --routines --triggers "$DB" > "$DUMP") 2>&1) || { echo "$err" >&2; copy_failed "$err"; }
    (umask 077; LC_ALL=C sed -E 's/DEFINER=`[^`]*`@`[^`]*`/DEFINER=CURRENT_USER/g' "$DUMP" \
        | LC_ALL=C awk -f "$STAGE/plain_triggers.awk" > "$DUMP.tmp")
    mv -f "$DUMP.tmp" "$DUMP"
    if ! err=$(mysql --defaults-extra-file="$CNF" --default-character-set=latin1 "$SCRATCH" < "$DUMP" 2>&1); then
        echo "$err" >&2
        # show the statement it choked on, byte for byte, unless it is row data
        # (the run log is public)
        n=$(printf '%s\n' "$err" | sed -nE 's/^ERROR .* at line ([0-9]+):.*/\1/p' | head -1)
        if [ -n "$n" ]; then
            if sed -n "${n}p" "$DUMP" | grep -q '^INSERT'; then
                echo "(dump line $n is row data, not shown)" >&2
            else
                echo "dump lines $n-$((n + 2)), \$ = line end, ^M = carriage return:" >&2
                sed -n "${n},$((n + 2))p" "$DUMP" | grep -v '^INSERT' | cut -c1-300 | cat -A >&2
            fi
        fi
        copy_failed "$err"
    fi
    rm -f "$DUMP"
    if ! python3 "$STAGE/db/deploy_db.py" --db "$SCRATCH" --migrations "$STAGE/db/migrations"; then
        echo >&2
        echo "the migrations FAIL on a copy of \`$DB\`; nothing was changed on \`$DB\`," >&2
        echo "the binaries or the servers. Fix the migration and run the workflow again." >&2
        exit 1
    fi
    mysql --defaults-extra-file="$CNF" -e "DROP DATABASE IF EXISTS \`$SCRATCH\`"
    scratch_made=""
    echo "every pending migration passed on the copy"
fi

if [ "$MODE" = "dry-run" ]; then
    rm -rf "$STAGE"
    echo
    echo "dry run: the live database, the binaries and the servers are untouched"
    exit 0
fi

#----------------------------------------------------------------- 3. migrate
say "migrating \`$DB\`"
rm -rf "$DIR/db"
mv "$STAGE/db" "$DIR/db"
if ! python3 "$DIR/db/deploy_db.py"; then
    echo >&2
    echo "the migrations passed on the copy but failed on \`$DB\` (did it change in between?)." >&2
    echo "The new binaries were NOT installed. Fix the cause and run the workflow again." >&2
    exit 1
fi

#----------------------------------------------------------------- 4. install
if [ -d "$STAGE/new/bin" ]; then
    say "installing the new binaries"
    # a rename: a running server keeps the file it started from
    for s in "${SERVERS[@]}"; do
        mv -f "$STAGE/new/bin/$s" "$BIN/$s"
    done
fi

printf '%s %s\n' "$COMMIT" "$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$DIR/DEPLOYED"
rm -rf "$STAGE"

say "deployed $COMMIT; the servers were not restarted"
for s in "${SERVERS[@]}"; do
    if running "$s"; then
        echo "  $s: running (still the build it started with)"
    else
        echo "  $s: NOT running"
    fi
done
echo "To load the new build and tables:  cd $BIN && ./stop.local.sh && ./start.local.sh"
