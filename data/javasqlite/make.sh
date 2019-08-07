pkg:setup
autoconf
pkg:configure --with-sqlite="$(PKG_DEST_ sqlite3)/usr" --with-sqlite3="$(PKG_DEST_ sqlite3)/usr"
JAVAC_FLAGS='-source 1.5 -target 1.5' make
pkg:install
