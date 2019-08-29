# Taken from elucubratus
pkg:setup
./Configure -D__DARWIN_UNIX03 "${PKG_TARG}" --prefix=${PKG_TAPF} --openssldir=${PKG_TAPF}/lib/ssl shared
pkg:make
make install_sw DESTDIR="${PKG_DEST}"
pkg: rm -rf ${PKG_TAPF}/lib/man ${PKG_TAPF}/lib/ssl/man
pkg: mkdir -p ${PKG_TAPF}/etc/ssl
rm -rf "${PKG_DEST}"${PKG_TAPF}/lib/*.a

# TODO: Fix patch for other aarch64-apple-darwin* targets.
