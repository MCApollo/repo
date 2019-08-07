pkg:setup
pkg:configure --disable-examples --disable-gconf-peer --disable-gtk-peer --disable-plugin
make
pkg:install
