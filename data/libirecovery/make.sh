pkg:setup
NOCONFIGURE=1 sh autogen.sh
pkg:configure --disable-largefile ac_cv_func_malloc_0_nonnull=yes ac_cv_func_realloc_0_nonnull=yes
pkg:make
pkg:install
