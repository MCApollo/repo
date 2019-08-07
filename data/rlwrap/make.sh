pkg:setup
autoconf
pkg:configure ac_cv_func_openpty=no
make
pkg:install
