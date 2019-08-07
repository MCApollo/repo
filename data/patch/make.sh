pkg:setup
pkg:configure ac_cv_func_setmode=no
make
make install prefix="${PKG_DEST}/usr"
