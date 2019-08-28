pkg:setup
pkg:make CCFLAGS="-Wall -O3 -funroll-loops"
pkg: mkdir -p ${PKG_TAPF}/bin
cp httpry ${PKG_DEST}/${PKG_TAPF}/bin
