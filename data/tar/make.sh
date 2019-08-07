pkg:setup
pkg:configure --disable-dependency-tracking --disable-largefile ac_cv_func_utimensat=no ac_cv_func_futimens=no
make AR="${PKG_TARG}-ar" CFLAGS='-O2' -j8
pkg:install
pkg:bin tar
pkg: mkdir -p /usr/bin
ln -s /bin/tar "${PKG_DEST}/usr/bin/tar"
