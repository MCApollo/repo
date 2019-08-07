if [[ ! -e ${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/target ]]; then
    echo "unknown architecture: ${PKG_ARCH}" 1>&2
    exit 1
fi

source ${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/environ.sh
export PKG_TARG=$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/target")
