pkg:setup
pkg:configure --with-app-defaults=${PKG_TAPF}/etc/X11/app-defaults
pkg:install

# pkg: mkdir -p ${PKG_TAPF}/share/terminfo
# make install-ti DESTDIR=${PKG_DEST} TERMINFO_DIR=${PKG_DEST}/${PKG_TAPF}/share/terminfo
