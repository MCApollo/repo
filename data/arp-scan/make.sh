pkg:setup
autoreconf -fiv
pkg:configure --disable-dependency-tracking 
pkg:install 