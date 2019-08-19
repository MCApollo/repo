#!/usr/bin/env bash
set -e
shopt -s extglob nullglob

if [[ $# == 0 ]]; then
    echo "usage: $0 <package>"
    exit
fi

export PKG_MAKE=$0
export PKG_NAME=${1%_}

export PKG_BASE=$(realpath "$(dirname "$0")")

# when running fakeroot, we shouldn't use the previous build result
# as we don't have the fakeroot session info anymore

if [[ -z ${FAKEROOTKEY} ]]; then
    ./make.sh "${PKG_NAME}"
else
    ./remake.sh "${PKG_NAME}"
fi

source "${PKG_BASE}/lib/helper.sh"

pkg: mkdir -p /DEBIAN
./control.sh "${PKG_NAME}" control >"$(pkg_ /DEBIAN/control)"

for script in preinst extrainst_ postinst prerm postrm; do
    if [[ -e "${PKG_DATA}/_metadata/${script}.c" ]]; then
        ./exec.sh - "${PKG_TARG}-gcc" -o "$(pkg_ /DEBIAN)/${script}" "${PKG_DATA}/_metadata/${script}.c"
				if [[ -e "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/entitlement.xml" ]]; then
            ./exec.sh - ldid -S"${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/entitlement.xml" "$(pkg_ /DEBIAN)/${script}"
				else
            ./exec.sh - ldid -S "$(pkg_ /DEBIAN)/${script}"
				fi
    elif [[ -e "${PKG_DATA}/_metadata/${script}" ]]; then
        cp -a "${PKG_DATA}/_metadata/${script}" "$(pkg_ /DEBIAN)"
    fi
done

if [[ -e "${PKG_DATA}"/_metadata/conffiles ]]; then
    cp -a "${PKG_DATA}"/_metadata/conffiles "$(pkg_ /DEBIAN)"
fi

export PKG_HASH=$(util/catdir.sh "${PKG_DEST}" | md5sum | cut -d ' ' -f 1)
echo "hashed dest ${PKG_NAME} to: ${PKG_HASH}"
NEED_PACK=0

if [[ -z ${PKG_RVSN} || ! -e "${PKG_STAT}/dest-md5" || ${PKG_HASH} != $(cat "${PKG_STAT}/dest-md5" 2>/dev/null) ]]; then
    if [[ -z ${PKG_RVSN} ]]; then
        PKG_RVSN=1
    else
        PKG_RVSN=$((${PKG_RVSN} + 1))
    fi
    NEED_PACK=1
fi
export PKG_PACK=${PKG_BASE}/debs/${PKG_CFTARG}/${PKG_NAME}_${PKG_VRSN}-${PKG_RVSN}_${PKG_ARCH}.deb
if [[ ${NEED_PACK} == 0 && -f "${PKG_PACK}" ]]; then
    echo "skipping re-package of ${PKG_NAME}"
else
    if [[ ! -d "${PKG_BASE}/debs/${PKG_CFTARG}" ]]; then
        mkdir -p "${PKG_BASE}/debs/${PKG_CFTARG}"
    fi
    export PKG_PACK=${PKG_BASE}/debs/${PKG_CFTARG}/${PKG_NAME}_${PKG_VRSN}-${PKG_RVSN}_${PKG_ARCH}.deb
    if [[ -e ${PKG_PACK} ]]; then
        echo "package ${PKG_PACK} already exists..."
    else
        ./control.sh "${PKG_NAME}" control "${PKG_VRSN}-${PKG_RVSN}" >"$(pkg_ /DEBIAN/control)"
        ${FAKEROOT} dm.pl -Z"${PKG_ZLIB}" -b "${PKG_DEST}" "${PKG_PACK}"
        echo "${PKG_HASH}" >"${PKG_STAT}/dest-md5"
        echo "${PKG_RVSN}" >"${PKG_STAT}/dest-ver"
        if [[ -e "${PKG_BASE}"/upload.sh ]]; then
            "${PKG_BASE}"/upload.sh debs "${PKG_PACK}"
        fi
    fi
fi

pkg: rm -rf /DEBIAN
