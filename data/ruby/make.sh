pkg:setup
# Host
mkdir host; pushd host
env -i ../configure --prefix=$PWD/install
env -i make install
popd
# Target
DLDFLAGS="-undefined dynamic_lookup" ac_cv_func_setpgrp_void=yes rb_cv_binary_elf=no rb_cv_stack_grow_dir=-1 rb_cv_bsd_signal=yes ac_cv_type_getgroups=gid_t ac_cv_c_stack_direction=-1 ac_cv_func_memcmp_working=yes  ac_cv_func_finite=yes   \
pkg:configure --without-gmp --disable-dtrace --enable-wide-getaddrinfo --with-baseruby=$PWD/host/install/bin/ruby
pkg:make
pkg:install
