pkg:setup
cp "${PKG_BASE}/config.sub" .
pkg:configure
make -j8
pkg:install
