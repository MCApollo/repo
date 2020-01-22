pkg:setup
pkg:configure --enable-launchd --with-launchd-agent-dir=${PKG_TAPF} --enable-launchd --disable-tests \
    --localstatedir=${PKG_TAPF}/var --sysconfdir=${PKG_TAPF}/etc
pkg:install

pkg: mkdir -p ${PKG_TAPF}/var
