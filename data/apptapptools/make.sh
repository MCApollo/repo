pkg:setup
make CC=${PKG_TARG}-gcc
pkg: mkdir -p /usr/bin
pkg: cp -a atpkg atsrc /usr/bin
