pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules daq_cv_libpcap_version_1x=yes ac_cv_func_malloc_0_nonnull=yes ac_cv_func_realloc_0_nonnull=yes
make	# on purpose
pkg:install 
