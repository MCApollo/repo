pkg:setup
echo ./Configure -D__DARWIN_UNIX03 "${PKG_TARG}" --prefix=/usr --openssldir=/usr/lib/ssl shared
./Configure -D__DARWIN_UNIX03 "${PKG_TARG}" --prefix=/usr --openssldir=/usr/lib/ssl shared
make AR="${PKG_TARG}-ar -r" -j8
make install_sw INSTALL_PREFIX="${PKG_DEST}"
pkg: rm -rf /usr/lib/man /usr/lib/ssl/man
pkg: mkdir -p /etc/ssl
mv "${PKG_DEST}"/usr/lib/ssl/{certs,openssl.cnf,private} "${PKG_DEST}"/etc/ssl
rm -rf "${PKG_DEST}"/usr/lib/*.a
