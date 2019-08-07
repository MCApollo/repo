pkg:setup
autoconf
#EXTRA_CFLAGS='-DSVN_SQLITE_MIN_VERSION="3.19.3"' pkg:configure --enable-maintainer-mode --disable-keychain --with-apr="$(PKG_WORK_ _apr)/apr-$(cat $(PKG_DATA_ _apr)/_metadata/version)/" --with-apr-util="$(PKG_WORK_ apr-util)/apr-util-$(cat $(PKG_DATA_ apr-util)/_metadata/version)/" --without-apxs
pkg:configure --enable-maintainer-mode --disable-keychain --with-apr="$(PKG_WORK_ _apr)/apr-$(cat $(PKG_DATA_ _apr)/_metadata/version)/" --with-apr-util="$(PKG_WORK_ apr-util)/apr-util-$(cat $(PKG_DATA_ apr-util)/_metadata/version)/" --without-apxs --enable-sqlite-compatibility-version=3.8.11.1
make -j8
pkg:install
