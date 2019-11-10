pkg:setup
pkg:make DATADIR=${PKG_TAPF}/share BINDIR=${PKG_TAPF}/bin
pkg:install DATADIR=${PKG_DEST}/${PKG_TAPF}/share BINDIR=${PKG_DEST}/${PKG_TAPF}/bin MANDIR=${PKG_DEST}/${PKG_TAPF}/share
