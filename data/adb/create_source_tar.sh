#!/usr/bin/env bash
# author: MCApoll
# description: Create a tar for adb.
set -e
shopt -s nullglob
(( ! $# )) && \
{
echo "Usage: $0 <branch>"
echo "See <https://android.googlesource.com/platform/system/core/> for a branch"
echo "(try: android10-release)"
exit 1
}

pwd="$(dirname $(realpath $0))"
branch="$1"
dir="android-adb"

cd ${TMPDIR:-/tmp}
mkdir -p ${dir}/{system,external}

cd ${dir}/
 git clone -b ${branch} https://android.googlesource.com/platform/system/core
 git clone -b ${branch} https://android.googlesource.com/platform/system/extras
 git clone -b ${branch} https://android.googlesource.com/platform/external/mdnsresponder
 rm -rf */.git
 cp -r ${pwd}/android-tools/* .
cd ${TMPDIR:-/tmp}

tar czf ${dir}-${branch}.tar.gz ${dir}
mv *.tar.gz ${pwd}
rm -rf ${dir}
