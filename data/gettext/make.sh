pkg:setup
pkg:configure --disable-java --without-libintl-prefix
make -j8
pkg:install
pkg: rm -rf /usr/share
