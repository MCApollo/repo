pkg:setup
make CC=${PKG_TARG}-gcc
pkg: mkdir -p /usr/bin
pkg: mv dmg2img /usr/bin
