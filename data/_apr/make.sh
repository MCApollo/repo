pkg:setup
pkg:configure --disable-static ac_cv_ebcdic=no lt_cv_dlopen_self=yes ap_cv_atomic_builtins=no apr_cv_use_lfs64=no apr_cv_mutex_recursive=yes apr_cv_epoll=no ac_cv_file__dev_zero=yes ac_cv_c_stack_direction=-1 ac_cv_strerror_r_rc_int=yes ac_cv_func_setpgrp_void=yes ac_cv_sizeof_pid_t=4 ac_cv_sizeof_ssize_t=4 ac_cv_sizeof_size_t=4 ac_cv_sizeof_off_t=8 ac_cv_sizeof_struct_iovec=8 ac_cv_struct_rlimit=yes ac_cv_func_sem_open=yes apr_cv_process_shared_works=yes apr_cv_mutex_robust_shared=no apr_fcntl_tryacquire_eacces=no ac_cv_tcp_nodelay_inherited=yes ac_cv_o_nonblock_inherited=yes apr_cv_tcp_nodelay_with_cork=no apr_cv_sctp=no ac_cv_working_getaddrinfo=yes ac_cv_negative_eai=no ac_cv_working_getnameinfo=yes apr_cv_gai_addrconfig=yes #--with-installbuilddir=/usr/lib/apr-1/build
gcc -o tools/gen_test_char.lo -c tools/gen_test_char.c
gcc -o tools/gen_test_char tools/gen_test_char.lo
pkg:make
pkg:install
pkg: rm -rf /usr/build-1
