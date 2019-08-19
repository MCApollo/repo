#!/usr/bin/env bash
rm -f stat/${PKG_ARCH}/${PKG_CFTARG}/$1/data-md5
./make.sh "$1"
