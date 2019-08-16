#!/usr/bin/env bash

( # Assert for variables, dirty test:
printf "${PKG_CFTARG:?'PKG_CFTARG is unknown.'}"
printf "${PKG_ARCH:?'PKG_ARCH is unknown.'}" 
) > /dev/null

if [[ ! -e ${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/target ]]; then
    echo "unknown architecture: ${PKG_ARCH}/${PKG_CFTARG}" 1>&2
    exit 1
fi

source ${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/environ.sh
declare -rx PKG_TARG=$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/target")
