#!/bin/bash
set -e
shopt -s extglob nullglob

PKG_BASE=$(dirname "$(realpath "$0")")
cd "${PKG_BASE}"
PKG_RVSN=1

PKG_REPO="${PKG_BASE}/apt/"

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
