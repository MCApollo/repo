cp -a "$(PKG_DEST_ _apt1.4)"/etc "${PKG_DEST}"
cp -a "$(PKG_DEST_ _apt1.4)"/var "${PKG_DEST}"

pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _apt1.4)"/usr/lib/lib*.*.dylib "${PKG_DEST}"/usr/lib/
cp -a "$(PKG_DEST_ _apt1.4)"/usr/libexec "${PKG_DEST}"/usr
rm -f "${PKG_DEST}"/usr/lib/libapt-pkg.*
pkg: ln -s ../libexec/apt /usr/lib/apt
pkg: rm -f /usr/libexec/apt/methods/https
pkg: ln -s http /usr/libexec/apt/methods/https
