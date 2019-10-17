pkg:setup
pkg:configure --enable-zlib --enable-bundled-libtom --sysconfdir=${PKG_TAPF}/etc/dropbear
make
pkg:install 
