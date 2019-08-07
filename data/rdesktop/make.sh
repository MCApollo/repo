pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure --with-openssl="$(PKG_DEST_ _openssl1.0)/usr" --with-sound=no
make -j8
pkg:install
