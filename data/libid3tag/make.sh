pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure
make
pkg:install
