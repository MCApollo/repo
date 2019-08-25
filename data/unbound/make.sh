pkg:setup
pkg:configure --enable-event-api --sysconfdir=${PKG_TAPF}/etc --with-ssl=$(PKG_DEST_ openssl)/${PKG_TAPF} --with-libevent=$(PKG_DEST_ libevent)/${PKG_TAPF} --with-libexpat=$(PKG_DEST_ expat)/${PKG_TAPF}
pkg:make
