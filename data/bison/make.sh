pkg:setup
pkg:configure gl_cv_func_strndup=no ac_cv_func_obstack=no
make CFLAGS='-O2 -fno-common'
pkg:install
