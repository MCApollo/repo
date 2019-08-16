#!/bin/bash
set -e
shopt -s extglob nullglob

PKG_BASE=$(dirname "$(realpath "$0")")
cd "${PKG_BASE}"
PKG_RVSN=1

PKG_REPO="${PKG_BASE}/apt/"

rm -rf "${PKG_BASE}/apt-old"
cp -a "${PKG_REPO}" "${PKG_BASE}/apt-old"
rm -rf "${PKG_REPO}/debs/"
mkdir -p "${PKG_REPO}/debs/"

for PKG_ARCH in "${PKG_BASE}/arch"/*/; do
    if [[ -e "${PKG_BASE}/$environ.sh" ]]; then
		    source "${PKG_BASE}/$environ.sh"
		fi
    for PKG_CFTARG in "${PKG_ARCH}"/*/; do
        if [[ -e "${PKG_BASE}/$environ.sh" ]]; then
            source "${PKG_CFTARG}/$environ.sh"
		    fi
        PKG_ARCH=$(basename "${PKG_ARCH}")
        PKG_CFTARG=$(basename "${PKG_CFTARG}")
        echo "scanning ${PKG_ARCH}/${PKG_CFTARG}"

        PKG_DCBF=${PKG_REPO}/dists/ios/${PKG_CFTARG}/main/binary-${PKG_ARCH}
        mkdir -p "${PKG_DCBF}"
        PKG_PKGS=${PKG_DCBF}/Packages

        rm -rf "${PKG_BASE}/link"
        mkdir "${PKG_BASE}/link"
        mkdir "${PKG_BASE}/link/${PKG_CFTARG}"

        for package in "${PKG_BASE}/data"/!(*_); do
            PKG_NAME=$(basename "${package}")

            # XXX: add to above filter
            if [[ ${PKG_NAME} == _* || ! -f "${package}/_metadata/in.${PKG_CFTARG}" ]]; then
                continue
            fi

            PKG_DATA="${PKG_BASE}/data/${PKG_NAME}"
            PKG_STAT="${PKG_BASE}/stat/${PKG_ARCH}/${PKG_CFTARG}/${PKG_NAME}"
            PKG_PRIO=$(cat "${PKG_DATA}/_metadata/priority")

            if [[ -e ${PKG_STAT}/fail ]]; then
                continue
            fi

            echo "${PKG_NAME}" "${PKG_PRIO#+}" "$(cat "${PKG_DATA}/_metadata/section")"

            PKG_FILE=${PKG_STAT}/dest-ver
            if [[ -e ${PKG_FILE} ]]; then
                PKG_REAL=${PKG_STAT}/real-ver
                if [[ -e ${PKG_REAL} ]]; then
                    PKG_RVER=$(cat "${PKG_REAL}")
                else
                    PKG_RVER=$(cat "${PKG_STAT}/data-ver")-$(cat "${PKG_FILE}")
                fi

                PKG_FILE=${PKG_BASE}/debs/${PKG_CFTARG}/${PKG_NAME}_${PKG_RVER}_${PKG_ARCH}.deb
                if [[ -e ${PKG_FILE} && ! -e "${PKG_STAT}/exclude" ]]; then
                    ln -s "${PKG_FILE}" "${PKG_BASE}/link/${PKG_CFTARG}/"
                fi
            fi
        done >"${PKG_BASE}/overrides.txt"

        for deb in "${PKG_BASE}/xtra/${PKG_ARCH}/${PKG_CFTARG}"/*.deb; do
            ln -s "$(readlink -f "${deb}")" "${PKG_BASE}/link/${PKG_CFTARG}/"
        done

        for deb in "${PKG_BASE}/xtra/all/${PKG_CFTARG}"/*.deb; do
            ln -s "$(readlink -f "${deb}")" "${PKG_BASE}/link/${PKG_CFTARG}/"
        done

        dpkg-scanpackages -m link "${PKG_BASE}/overrides.txt" | sed -e 's/: link\//: debs\//' | while IFS= read -r line; do
            if [[ ${line} == '' ]]; then
                PKG_TAGS=$(cat "${PKG_BASE}/tags/${PKG_NAME}" 2>/dev/null || true)
                if [[ -z ${PKG_TAGS} ]]; then
                    PKG_TAGS=$(cat "${PKG_BASE}/data/${PKG_NAME}/_metadata/tags" 2>/dev/null || true)
                fi
                PKG_ROLE="${PKG_BASE}/data/${PKG_NAME}/_metadata/role"
                if [[ -n ${PKG_TAGS} || -e ${PKG_ROLE} ]]; then
                    echo -n "Tag: "
                    if [[ -n ${PKG_TAGS} ]]; then
                        echo -n "${PKG_TAGS}"
                    fi
                    if [[ -n ${PKG_TAGS} && -e ${PKG_ROLE} ]]; then
                        echo -n ", "
                    fi
                    if [[ -e ${PKG_ROLE} ]]; then
                        echo -n "role::$(cat "${PKG_ROLE}")"
                    fi
                    echo
                fi
            elif [[ ${line} == Package:* ]]; then
                PKG_NAME=${line#Package: }
            fi

            echo "${line}"
        done >"${PKG_PKGS}"
		    cp -a "${PKG_BASE}/link"/* "${PKG_REPO}/debs/"
#rm -f "${PKG_BASE}/overrides.txt"
        bzip2 -c "${PKG_PKGS}" >"${PKG_PKGS}.bz2"
        xz -c "${PKG_PKGS}" >"${PKG_PKGS}.xz"
    done
done

cd "${PKG_REPO}/dists/ios/"

for PKG_CFTARG in */ */*/binary*/; do
    pushd ${PKG_CFTARG}
        {
        cat <<EOF
Origin: Bingner/Elucubratus
Label: Bingner/Elucubratus
Suite: stable
Version: 1.0r${PKG_RVSN}
Codename: ios
Architectures: iphoneos-arm
Components: main
Description: Distribution of Unix Software for iPhoneOS
Support: https://cydia.saurik.com/api/support/*
MD5Sum:
EOF

        find * -type f | grep -v Release | while read -r line; do
            echo " $(md5sum "${line}" | cut -d ' ' -f 1) $(stat -f %z "${line}" | cut -d $'\t' -f 1) ${line}"
        done

        } >"Release"

        rm -f Release.gpg
        gpg -abs -o Release.gpg Release
    popd
done

rsync -a "${PKG_BASE}/info" "${PKG_REPO}"
diff -x Release.gpg -x Release -x Packages.xz -x Packages.bz2 -ur "${PKG_BASE}/apt-old/" "${PKG_REPO}" 
