pkg:setup
#pkg:configure ac_cv_func_stat64=no ac_cv_func_fstat64=no ac_cv_func_fstatat64=no CFLAGS=-g --with-ipc=tcp
pkg:configure --with-ipc=tcp
pkg:make
pkg:install
