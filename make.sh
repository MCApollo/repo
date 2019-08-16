#!/usr/bin/env bash
set -e
shopt -s extglob nullglob

if (( ! $# )); then
    echo "usage: ${0##*/} <package>"
    exit 1
fi

# Mark as readonly.
declare -rx PKG_MAKE=$0 \
    PKG_NAME=${1%_}     \
    PKG_BASE=$(realpath "$(dirname "$0")")

. "${PKG_BASE}/lib/helper.sh"

# Clean up
mkdir -p "${PKG_STAT}"
rm -f "${PKG_STAT:-/nonexist}/data-md5"

rm -rf "${PKG_MORE}" "${PKG_DEST}" "${PKG_WORK}"
mkdir -p "${PKG_MORE}" "${PKG_DEST}" "${PKG_WORK}"

# Export all build functions.
. "${PKG_BASE}/lib/pkg.sh"

( # Execute package's make.sh in a subshell.
cd "${PKG_WORK}"
"${PKG_BASE}/exec.sh" "${PKG_NAME}" . "${PKG_DATA}/make.sh"
)

