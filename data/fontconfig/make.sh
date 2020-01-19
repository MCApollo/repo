pkg:setup
pkg:configure --sysconfdir=${PKG_TAPF}/etc --with-default-fonts=${PKG_TAPF}/share/fonts
echo "#define FC_NO_MT 1" >> config.h
make
pkg:install RUN_FC_CACHE_TEST=false
