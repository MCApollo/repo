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
export PKG_TAPF=$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/prefix")


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

# Clean up
for x in    \
    "${PKG_TAPF:-/usr}/share/man"       \
    "${PKG_TAPF:-/usr}/share/info"      \
    "${PKG_TAPF:-/usr}/share/gtk-doc"   \
    "${PKG_TAPF:-/usr}/share/doc"       \
    "${PKG_TAPF:-/usr}/share/locale"    \
    "${PKG_TAPF:-/usr}/man"             \
    "${PKG_TAPF:-/usr}/local/share/man" \
    "${PKG_TAPF:-/usr}/local/OpenSourceVersions"    \
    "${PKG_TAPF:-/usr}/local/OpenSourceLicenses"    \
    "${PKG_TAPF:-/usr}/lib/charset.alias"           \
    "${PKG_TAPF:-/usr}/info"    \
    "${PKG_TAPF:-/usr}/docs"    \
    "${PKG_TAPF:-/usr}/doc"
do
    x="${PKG_DEST}${x}" # Append the full path.
    if [[ -d "${x}" ]]; then
        rm -rf "${x}"
    else
        rm -f "${x}"
    fi
done

# rmdir_ -> rmdir --ignore-on-empty
rmdir_ "${PKG_DEST}${PKG_TAPF:-/usr}/share"
rmdir_ "${PKG_DEST}${PKG_TAPF:-/usr}/local/share"
rmdir_ "${PKG_DEST}${PKG_TAPF:-/usr}/local"
rmdir_ "${PKG_DEST}${PKG_TAPF:-/usr}/lib"
rmdir_ "${PKG_DEST}${PKG_TAPF:-/usr}"

if [[ -e "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/strip" ]]; then
    . "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/strip"
fi

find "${PKG_DEST}" -type f -name '*.elc' -print0 | while read -r -d $'\0' bin; do
    sed -i -e '
        s/^;;; Compiled by .*$//
        s/^;;; from file .*$//
        s/^;;; in Emacs version .*$//
        s/^;;; with .*$//
    ' "${bin}"
done

find "${PKG_DEST}" -type f -name '*.a' -print0 | while read -r -d $'\0' bin; do
    "${PKG_BASE}/util/arid" "${bin}" || :
done

if [[ -f "${PKG_STAT}/data-ver" && -f "${PKG_STAT}/dest-ver" ]] && dpkg --compare-versions $(cat "${PKG_DATA}/_metadata/version") gt $(cat "${PKG_STAT}/data-ver"); then
    rm "${PKG_STAT}/dest-ver"
fi
cp -aL "${PKG_DATA}/_metadata/version" "${PKG_STAT}/data-ver"
echo "${PKG_HASH}" >"${PKG_STAT}/data-md5"

echo "hashed code ${PKG_NAME} to: $("${PKG_BASE}"/util/catdir.sh "${PKG_DEST}" | md5sum | cut -d ' ' -f 1)"