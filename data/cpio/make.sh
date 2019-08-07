pkg:setup
pkg:configure ac_cv_func_obstack=no
make -j8
pkg:install
pkg: rm -f /usr/libexec/rmt
