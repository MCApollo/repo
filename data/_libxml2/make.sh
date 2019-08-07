pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure --without-python
make -j8
pkg:install
