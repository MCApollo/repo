pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure ac_cv_va_copy=yes
make -j8
pkg:install
pkg: find /usr/lib -name '*.la' | xargs rm
