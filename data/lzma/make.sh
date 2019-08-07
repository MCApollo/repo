pkg:setup
autoreconf -f -i
pkg:configure
make
pkg:install
