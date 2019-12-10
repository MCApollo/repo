pkg:setup
pc_path="${PKG_TAPF}/lib/pkgconfig:${PKG_TAPF}/share/pkgconfig:/usr/local/lib/pkgconfig:/usr/lib/pkgconfig"
pkg:configure --disable-debug --disable-host-tool --with-pc-path=${pc_path}
make
pkg:install 
