pkg:setup
ac_cv_func_realloc_0_nonnull=yes ac_cv_func_malloc_0_nonnull=yes pkg:configure --datadir="${PKG_TAPF}"/var
pkg:install

pkg: mkdir "${PKG_TAPF}"/var

