pkg:setup
autoreconf -f -i
pkg:configure --disable-largefile --with-perl=no --with-fontconfig=no --with-x=no --with-pango=no --without-freetype --with-gs-font-dir=none --with-lcms=no --without-webp
make -j8
pkg:install
