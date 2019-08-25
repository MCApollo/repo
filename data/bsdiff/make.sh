pkg:setup
${PKG_TARG}-gcc -O3 -lbz2 bsdiff.c -o bsdiff
${PKG_TARG}-gcc -O3 -lbz2 bspatch.c -o bsdpatch
pkg: mkdir -p ${PKG_TAPF}/bin
install -c -s -m 555 bsdiff ${PKG_DEST}/${PKG_TAPF}/bin
install -c -s -m 555 bsdpatch ${PKG_DEST}/${PKG_TAPF}/bin

