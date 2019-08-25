# Taken from elucubratus

pkg:setup
echo ./Configure -D__DARWIN_UNIX03 "${PKG_TARG}" --prefix=${PKG_TAPF} --openssldir=${PKG_TAPF}/lib/ssl shared
./Configure -D__DARWIN_UNIX03 "${PKG_TARG}" --prefix=${PKG_TAPF} --openssldir=${PKG_TAPF}/lib/ssl shared
make AR="${PKG_TARG}-ar -r" -j8
make install_sw INSTALL_PREFIX="${PKG_DEST}"
pkg: rm -rf ${PKG_TAPF}/lib/man ${PKG_TAPF}/lib/ssl/man
pkg: mkdir -p ${PKG_TAPF}/etc/ssl
mv "${PKG_DEST}"${PKG_TAPF}/lib/ssl/{certs,openssl.cnf,private} "${PKG_DEST}"/${PKG_TAPF}/etc/ssl
rm -rf "${PKG_DEST}"${PKG_TAPF}/lib/*.a
