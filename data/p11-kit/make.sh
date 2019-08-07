pkg:setup
pkg:configure ac_cv_func_issetugid=no --without-trust-paths --without-libffi
pkg:make -j8
pkg:install
