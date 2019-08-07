pkg:setup
./Configure -D__DARWIN_UNIX03 "${PKG_TARG}" --prefix=/usr --openssldir=/usr/lib/ssl shared
make -j16 AR="${PKG_TARG}-ar -r"
make install_sw INSTALL_PREFIX="${PKG_DEST}"
pkg: mkdir -p /etc/ssl
mv "${PKG_DEST}"/usr/lib/ssl/{certs,openssl.cnf,private} "${PKG_DEST}"/etc/ssl
ln -s /etc/ssl/{certs,openssl.cnf,private} "${PKG_DEST}"/usr/lib/ssl
rm -rf "${PKG_DEST}"/usr/lib/*.a
