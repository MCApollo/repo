pkg:setup
pkg:configure CFLAGS=-fnested-functions --enable-gdk-pixbuf=no
make
pkg:install
