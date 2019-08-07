pkg:setup
./autogen.sh NOCONFIGURE=1
pkg:configure ac_cv_func_malloc_0_nonnull=yes ac_cv_func_realloc_0_nonnull=yes
pkg:make
pkg:install
