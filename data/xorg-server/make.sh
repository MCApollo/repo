pkg:setup
#  BUG: https://stackoverflow.com/questions/13905200/is-it-wise-to-ignore-gcc-clangs-wmissing-braces-warning
CFLAGS="-Wno-error=missing-braces" \
pkg:configure --sysconfdir=${PKG_TAPF}/etc --enable-suid-wrapper --with-xkb-output=/var/lib/xkb --enable-xorg --disable-glamor # --enable-dmx FIXME: duplicate symbol
#  Is d-lookup meant to be used?
pkg:install LDFLAGS="-undefined\ dynamic_lookup"

mkdir -pv ${PKG_DEST}/${PKG_TAPF}/etc/{X11/xorg.conf.d,sysconfig}
cat >> ${PKG_DEST}/${PKG_TAPF}/etc/sysconfig/createfiles << "EOF"
/tmp/.ICE-unix dir 1777 root root
/tmp/.X11-unix dir 1777 root root
EOF
