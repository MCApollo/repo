#!/usr/bin/env bash
# MCApollo
# Switch-lan-play doesn't provide a working release tar.
set -e
shopt -s extglob
shopt -s nullglob

(( ! $# )) && { echo "Provide a commit hash."; exit 1; }
hash=$1


pwd="$(dirname $(realpath $0))"
pushd ${TMPDIR:-/tmp}
git clone --recursive https://github.com/spacemeowx2/switch-lan-play.git switch-lan-play

cd switch-lan-play
git checkout ${hash}
rm -rf .git
cd ..

tar czvf switch-lan-play.tar.gz switch-lan-play
popd
cp ${TMPDIR:-/tmp}/switch-lan-play.tar.gz .
rm -rf ${TMPDIR:-/tmp}/switch-lan-play*
