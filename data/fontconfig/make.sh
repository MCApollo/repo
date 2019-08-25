pkg:setup
pkg:configure --sysconfdir=${PKG_TAPF}/etc
make
pkg:install RUN_FC_CACHE_TEST=false
