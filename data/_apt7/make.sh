pkg:setup
rm buildlib/config.sub
cp ${PKG_BASE}/config.sub buildlib/
autoconf
DPKG_DATADIR=$(ls -d $(PKG_WORK_ _dpkg)/dpkg-*/data) DPKG_ARCH=$(ls -d $(PKG_WORK_ _dpkg)/dpkg-*/scripts) pkg:configure --disable-nls
make

pkg: mkdir -p /etc/apt/apt.conf.d
pkg: mkdir -p /etc/apt/preferences.d
pkg: mkdir -p /etc/apt/sources.list.d
pkg: mkdir -p /etc/apt/trusted.gpg.d
pkg: mkdir -p /var/cache/apt/archives/partial
pkg: mkdir -p /var/lib/apt/lists/partial
pkg: mkdir -p /var/lib/apt/periodic
pkg: mkdir -p /var/log/apt

pkg: mkdir -p /usr/bin /usr/lib/apt
pkg: cp -a bin/apt-* /usr/bin
pkg: cp -a bin/libapt-* /usr/lib
pkg: cp -a bin/methods /usr/lib/apt

pkg: mkdir -p /usr/lib/dpkg/methods
pkg: cp -a scripts/dselect /usr/lib/dpkg/methods/apt

pkg: mkdir -p /usr/include
pkg: cp -a include/apt-pkg /usr/include
