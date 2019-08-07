pkg:setup
autoreconf -f -i
pkg:configure --with-included-libtasn1 --without-libiconv-prefix --without-libintl-prefix --without-libseccomp-prefix \
	--without-libcrypto-prefix --without-librt-prefix --without-libpthread-prefix --without-libnsl-prefix \
	--without-libunistring-prefix --without-libdl-prefix --without-libz-prefix P11_KIT_LIBS="-lp11-kit"
make -j8 V=1
pkg:install V=1
