pkg:setup
autoconf
mkdir x86
cd x86
env -i ../configure  --disable-install-rdoc --disable-install-doc --prefix="$(pwd)/../x86rb"
env -i make -j16
mkdir ../x86rb
make install
cd ..
pkg:configure ac_cv_func_setpgrp_void=yes rb_cv_binary_elf=no rb_cv_stack_grow_dir=-1 rb_cv_bsd_signal=yes ac_cv_type_getgroups=gid_t ac_cv_c_stack_direction=-1 ac_cv_func_memcmp_working=yes --enable-wide-getaddrinfo ac_cv_func_finite=yes --disable-install-doc --disable-install-rdoc --with-baseruby="$(pwd)/x86rb/bin/ruby"
pkg:make
pkg:install
