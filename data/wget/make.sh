pkg:setup
pkg:configure --with-ssl=openssl --with-libssl-prefix="$(PKG_DEST_ openssl)" --without-libpsl gl_cv_func_unlink_honors_slashes=yes
pkg:make
pkg:install
