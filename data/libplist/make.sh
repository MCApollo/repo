pkg:setup
autoreconf -f -i
pkg:configure --without-cython
pkg:make
pkg:install
