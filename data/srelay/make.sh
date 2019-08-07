pkg:setup
cp "${PKG_BASE}/config.sub" .
autoconf
pkg:configure
make -j8
pkg: mkdir -p /usr/bin
pkg: cp -a srelay /usr/bin
