pkg:setup
pkg:configure --enable-jit --enable-utf
make
pkg:install
pkg: ln -s libpcre.1.dylib /usr/lib/libpcre.0.dylib
