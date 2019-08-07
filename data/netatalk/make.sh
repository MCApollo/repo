pkg:setup
autoconf
AR=$(which "${PKG_TARG}-ar") pkg:configure --enable-cups=no --sysconfdir=/etc --with-bdb="$(PKG_DEST_ berkeleydb)/usr"
make
pkg:install

pkg: mkdir -p /System/Library/LaunchDaemons
pkg: cp -a %/com.saurik.afpd.dns-sd.plist /System/Library/LaunchDaemons
pkg: cp -a %/net.sourceforge.netatalk.afpd.plist /System/Library/LaunchDaemons

{
    pkg: grep '^#' /etc/netatalk/AppleVolumes.default
    echo '~ home'
    echo '/ root'
} >AppleVolumes.default

chmod --reference="${PKG_DEST}/etc/netatalk/AppleVolumes.default" AppleVolumes.default
chown --reference="${PKG_DEST}/etc/netatalk/AppleVolumes.default" AppleVolumes.default

pkg: mv AppleVolumes.default /etc/netatalk/AppleVolumes.default
