pkg:setup
autoconf
CC="${PKG_TARG}"-gcc pkg:configure --with-iconv="${PKG_ROOT}"/usr --with-curl="$(PKG_DEST_ curl)"/usr --enable-fastcgi
make
make install prefix="${PKG_DEST}"/usr datarootdir="${PKG_DEST}"/usr
