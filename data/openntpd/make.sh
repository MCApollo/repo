pkg:setup
pkg:configure --disable-strip --sysconfdir=/etc
make
pkg:install
