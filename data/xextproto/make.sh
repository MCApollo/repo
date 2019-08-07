pkg:setup
autoreconf -f -i
pkg:configure
make -j8
pkg:install
