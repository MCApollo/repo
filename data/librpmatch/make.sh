pkg:setup
autoreconf -f -i
pkg:configure
pkg:make -j8
pkg:install
