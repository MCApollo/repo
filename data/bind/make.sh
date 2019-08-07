pkg:setup
pkg:configure --with-randomdev=/dev/random BUILD_CC=gcc --with-openssl="$(PKG_DEST_ _openssl1.0)/usr" --with-ecdsa=no --with-gost=no --with-eddsa=no --with-libxml2=no --with-zlib="${PKG_ROOT}/usr" --with-gssapi=no
make -j8 CFLAGS="${CFLAGS} -DNO_VERSION_DATE"
pkg:install
