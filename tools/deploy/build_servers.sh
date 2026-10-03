#!/bin/bash
#-----------------------------------------------------------------------------
# Build gameserver, loginserver and sharedserver from a clean tree.
#
#   tools/deploy/build_servers.sh                 build with what is installed
#   tools/deploy/build_servers.sh --install-deps  apt-get the toolchain first
#                                                 (the CI container: ubuntu:20.04)
#
# Ubuntu 20.04 on purpose: the VPS runs binaries built on 20.04 and has that
# release's runtime libraries (libssl1.1, libmysqlclient21, ...). A build on a
# newer release would link libraries the VPS does not have.
#
# Always a full build of src/ (`make all`): the Makefiles track no header
# dependencies, so reusing old objects can link a server against a stale
# struct layout. ccache, when present, makes the full build cheap again
# without that risk - it keys every object on the preprocessed source.
#
# JOBS overrides the parallelism (default: every core).
#-----------------------------------------------------------------------------
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
JOBS="${JOBS:-$(nproc)}"

if [ "${1:-}" = "--install-deps" ]; then
    export DEBIAN_FRONTEND=noninteractive
    apt-get update -qq
    apt-get install -y -qq --no-install-recommends \
        g++ make ccache ca-certificates \
        libmysqlclient-dev libxerces-c-dev liblua5.1-0-dev freetds-dev \
        libssl-dev zlib1g-dev > /dev/null
fi

if [ -d /usr/lib/ccache ]; then
    export PATH="/usr/lib/ccache:$PATH"
    ccache --zero-stats > /dev/null
fi
g++ --version | head -1

cd "$ROOT/src"
make -j"$JOBS" all

for s in gameserver loginserver sharedserver; do
    if [ ! -x "$ROOT/bin/$s" ]; then
        echo "build finished but bin/$s is missing" >&2
        exit 1
    fi
    ls -la "$ROOT/bin/$s"
done

if command -v ccache > /dev/null && [ -d /usr/lib/ccache ]; then
    ccache --show-stats
fi
