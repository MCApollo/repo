pkg:setup
autoreconf -f -i
pkg:configure --without-gssapi cvs_cv_func_printf_ptr=yes --with-external-zlib
make -j8
pkg:install
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/cvs.sh /etc/profile.d
