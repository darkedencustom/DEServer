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
# DE_DB_HOST / DE_DB_USER / DE_DB_NAME come from the environment.
#
# Everything that can be checked is checked before a server is touched: the
# database's version, and that the new binaries find all their libraries here.
# Then: stop the servers, replace db/ and run deploy_db.py, install the new
# binaries, start the servers with the VPS's own bin/start.local.sh.
#
# A failure after the stop leaves the servers stopped on purpose: the old
# binaries on a half-migrated database is worse than a closed server.
#-----------------------------------------------------------------------------
set -euo pipefail

DIR=$1
STAGE=$2
MODE=$3
COMMIT=${4:-unknown}
BIN="$DIR/bin"
SERVERS=(gameserver loginserver sharedserver)

IFS= read -r DE_DB_PASSWORD || true
export DE_DB_PASSWORD
if [ -z "$DE_DB_PASSWORD" ]; then
    echo "no database password on stdin" >&2
    exit 1
fi

say() { printf '\n== %s\n' "$*"; }
# the pattern start.local.sh and stop.local.sh use; [.] keeps it off pgrep's own line
running() { pgrep -f "[.]/$1 -f" > /dev/null; }

#----------------------------------------------------------------- checks
for f in "$BIN/start.local.sh" "$BIN/stop.local.sh"; do
    if [ ! -f "$f" ]; then
        echo "missing $f; the deploy starts and stops the servers with it" >&2
        exit 1
    fi
done

say "database"
status=$(python3 "$STAGE/db/deploy_db.py" status --migrations "$STAGE/db/migrations" 2>&1) || {
    echo "$status" >&2
    exit 1
}
# a dry run prints it below, with what it would apply
if [ "$MODE" != "dry-run" ]; then echo "$status"; fi
case "$status" in
    *"missing or empty"*)
        echo "refusing: \`${DE_DB_NAME:-DARKEDEN}\` is missing or empty, and a deploy would import the skeleton into it" >&2
        exit 1 ;;
    *"no SchemaVersion table"*)
        echo "refusing: the database's version is unknown; declare it once with deploy_db.py --baseline" >&2
        exit 1 ;;
esac

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

if [ "$MODE" = "dry-run" ]; then
    say "dry run"
    python3 "$STAGE/db/deploy_db.py" --dry-run --migrations "$STAGE/db/migrations"
    rm -rf "$STAGE"
    echo
    echo "dry run: nothing was stopped, migrated or replaced"
    exit 0
fi

#----------------------------------------------------------------- stop
say "stopping the servers"
(cd "$BIN" && ./stop.local.sh) || true

# the gameserver saves every player on the way down; give it time
left=""
for i in $(seq 1 60); do
    left=""
    for s in "${SERVERS[@]}"; do
        if running "$s"; then left="$left $s"; fi
    done
    if [ -z "$left" ]; then break; fi
    sleep 5
done
if [ -n "$left" ]; then
    echo "still running after 5 minutes:$left" >&2
    echo "nothing was migrated or replaced; stop them by hand and run the workflow again" >&2
    exit 1
fi
echo "all stopped"

#----------------------------------------------------------------- migrate
say "migrating the database"
rm -rf "$DIR/db"
mv "$STAGE/db" "$DIR/db"
if ! python3 "$DIR/db/deploy_db.py"; then
    echo >&2
    echo "the migration failed and the servers are STOPPED, still on the old binaries." >&2
    echo "Fix the migration and run the workflow again (migrations are safe to repeat)," >&2
    echo "or bring the old build back up with $BIN/start.local.sh" >&2
    exit 1
fi

#----------------------------------------------------------------- install
if [ -d "$STAGE/new/bin" ]; then
    say "installing the new binaries"
    for s in "${SERVERS[@]}"; do
        mv -f "$STAGE/new/bin/$s" "$BIN/$s"
    done
fi

#----------------------------------------------------------------- start
say "starting the servers"
(cd "$BIN" && ./start.local.sh)

sleep 10
failed=""
for s in "${SERVERS[@]}"; do
    if ! running "$s"; then failed="$failed $s"; fi
done
if [ -n "$failed" ]; then
    for s in $failed; do
        echo "--- $s is not running; last lines of log/$s.log" >&2
        tail -n 40 "$DIR/log/$s.log" >&2 || true
    done
    exit 1
fi

printf '%s %s\n' "$COMMIT" "$(date -u +%Y-%m-%dT%H:%M:%SZ)" > "$DIR/DEPLOYED"
rm -rf "$STAGE"
say "deployed $COMMIT"
