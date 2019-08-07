pkg:setup
make all install PREFIX=/usr SYSCONFDIR=/etc DESTDIR="${PKG_DEST}" UCBINSTALL=/usr/bin/install CC="${PKG_TARG}-gcc"
pkg: ln -s mailx /usr/bin/mail
