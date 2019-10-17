pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules --disable-ppp-plugin --with-runtime-dir=${PKG_TAPF}/var/run/sstpc
pkg:install 
pkg: mkdir -p ${PKG_TAPF}/var/run/sstpc
