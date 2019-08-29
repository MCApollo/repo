pkg:setup
autoreconf -fvi
pkg:configure --disable-dependency-tracking --with-openssl="$(PKG_DEST_ openssl@1.1)/${PKG_TAPF}"
pkg:install 
