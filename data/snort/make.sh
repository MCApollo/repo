pkg:setup
autoreconf -ivf
export PATH="$(PKG_DEST_ daq)/${PKG_TAPF}/bin:$PATH"
pkg:configure --sysconfdir=${PKG_TAPF}/snort --disable-debug --disable-dependency-tracking --disable-silent-rules --enable-active-response --enable-flexresp3 --enable-gre --enable-mpls --enable-normalizer --enable-react --enable-reload --enable-sourcefire --enable-targetbased --with-libpcre-includes=$(PKG_DEST_ pcre)/${PKG_TAPF}/include --with-libpcre-libraries=$(PKG_DEST_ pcre)/${PKG_TAPF}/lib --disable-open-appid ac_cv_lib_daq_static_daq_load_modules=yes have_daq_real_addresses=yes
make
pkg:install
