pkg:setup
cp "${PKG_BASE}/config.sub" .
pkg:configure --disable-aso
make -j8
pkg:install
