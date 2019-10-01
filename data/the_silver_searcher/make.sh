pkg:setup
autoreconf -fiv
pkg:configure --disable-dependency-tracking 
make
pkg:install 
