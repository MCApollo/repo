pkg:setup
make CC="${PKG_TARG}-gcc" AR="${PKG_TARG}-ar" RANLIB="${PKG_TARG}-ranlib"
make install STRIP="${PKG_TARG}-strip" DSTROOT="${PKG_DEST}"
