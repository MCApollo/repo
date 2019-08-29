pkg:setup
pkg:configure --sysconfdir=${PKG_TAPF}/etc --with-openssl
make
pkg:install

rm -rf ${PKG_DEST:-/nonexist}/Library || :
