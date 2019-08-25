pkg:setup
autoreconf -ivf
pkg:configure --disable-debug --disable-dependency-tracking CFLAGS="-ffast-math -std=gnu89"
pkg:install 
