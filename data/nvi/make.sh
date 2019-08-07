pkg:setup
cd build.unix
PKG_CONF=../dist/configure pkg:configure vi_cv_sprintf_count=yes vi_cv_sys5_pty=no "--with-db-prefix=$(PKG_DEST_ berkeleydb)/usr"
make
pkg:install
pkg: rm -f /usr/bin/ex /usr/bin/view
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/nvi.sh /etc/profile.d
