pkg:setup
cp ${PKG_BASE}/util/config.sub auxdir/
pkg:configure --disable-debug --disable-dependency-tracking
pkg:install 
