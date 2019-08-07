pkg:setup
cp ${PKG_BASE}/config.sub config/
pkg:configure
make -j8
pkg:install
