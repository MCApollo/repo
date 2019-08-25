#!/usr/bin/env bash
set -e
PKG_ROOT=$(dirname $(realpath $0))

cd ${PKG_ROOT}/util/MCApollo.github.io/Public/
cp "${1}" ./Athena
dpkg-scanpackages -m . > Packages
bzip2 -f -k ./Packages
git add Athena
git commit -m "upload.sh: ${1##*/}"
git push
