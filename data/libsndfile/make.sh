pkg:setup
autoreconf -fvi
pkg:configure --disable-dependency-tracking 
pkg:install 