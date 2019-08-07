pkg:setup
autoreconf -f -i
pkg:configure --enable-install-program=su \
    ac_cv_c_stack_direction=-1 \
    gl_cv_struct_dirent_d_ino=yes \
    ac_cv_func_chown_works=yes \
    gl_cv_func_chown_follows_symlink=yes \
    gl_cv_double_slash_root=no \
    ac_cv_type_getgroups=gid_t \
    ac_cv_func_getgroups_works=yes \
    ac_cv_func_lstat_dereferences_slashed_symlink=no \
    gl_cv_func_getcwd_null=yes \
    ac_cv_func_malloc_0_nonnull=yes \
    ac_cv_func_lstat_empty_string_bug=no \
    gl_cv_func_working_strerror=yes \
    gl_cv_func_working_utimes=yes \
    gl_cv_func_printf_sizes_c99=yes \
    gl_cv_func_printf_long_double=yes \
    gl_cv_func_printf_infinite=yes \
    gl_cv_func_printf_infinite_long_double=no \
    gl_cv_func_printf_directive_a=no \
    gl_cv_func_printf_directive_f=yes \
    gl_cv_func_printf_directive_n=yes \
    gl_cv_func_printf_directive_ls=yes \
    gl_cv_func_printf_positions=yes \
    gl_cv_func_printf_flag_grouping=yes \
    gl_cv_func_printf_flag_leftadjust=yes \
    gl_cv_func_printf_flag_zero=no \
    gl_cv_func_printf_precision=yes \
    gl_cv_func_ungetc_works=yes \
    gl_cv_func_working_acl_get_file=yes \
    ac_cv_func_calloc_0_nonnull=yes \
    gl_cv_header_working_fcntl_h=yes \
    gl_cv_func_fflush_stdin=no \
    gl_cv_func_fnmatch_gnu=no \
    gl_cv_func_signbit=yes \
    gl_cv_func_signbit_gcc=yes \
    gl_fnmatch_cache_var=no \
    gl_cv_func_frexp_works=yes \
    gl_cv_func_frexpl_works=yes \
    gl_cv_func_getcwd_path_max=no \
    gl_cv_func_getcwd_abort_bug=yes \
    am_cv_func_working_getline=no \
    gl_cv_func_gettimeofday_clobber=no \
    am_cv_func_iconv_works=yes \
    gl_cv_pipes_are_fifos='yes (0)' \
    ac_cv_c_bigendian=no \
    gl_cv_func_isnanf_works=yes \
    gl_cv_func_isnanl_works=yes \
    gl_ac_cv_func_link_follows_symlink=yes \
    gl_cv_func_lseek_pipe=yes \
    ac_cv_func_memcmp_working=yes \
    ac_cv_func_strcoll_works=yes \
    gl_cv_func_mkdir_trailing_slash_bug=no \
    gl_cv_func_working_mkstemp=yes \
    ac_cv_func_working_mktime=yes \
    gl_cv_func_nanosleep=yes \
    gl_cv_func_open_slash=yes \
    gl_cv_func_ldexpl_works=yes \
    gl_cv_func_svid_putenv=no \
    ac_cv_func_realloc_0_nonnull=yes \
    gl_cv_func_re_compile_pattern_working=no \
    gl_cv_func_rename_trailing_slash_bug=no \
    gl_cv_func_rename_trailing_dest_slash_bug=no \
    gl_cv_func_rmdir_errno_not_empty=66 \
    gl_cv_func_select_supports0=yes \
    gl_cv_func_snprintf_size1=yes \
    gl_cv_header_working_stdint_h=no \
    gl_cv_func_stpncpy=yes \
    gl_cv_func_strndup=no \
    ac_cv_func_strnlen_working=no \
    ac_cv_func_strtod=yes \
    gl_cv_func_strtod_works=no \
    gl_cv_func_tzset_clobber=no \
    gl_cv_func_unlink_busy_text=yes \
    gl_cv_have_proc_uptime=no \
    gl_cv_func_iswcntrl_works=yes \
    gl_cv_func_wcwidth_works=yes \
    ac_cv_func_fork_works=yes \
    ac_cv_func_vfork_works=yes \
    utils_cv_localtime_cache=no
make AR="${PKG_TARG}-ar" CFLAGS="-O2 ${PKG_MCPU}"
pkg:install
pkg: rm -f /usr/bin/sync
pkg:bin cat chgrp chmod chown cp date dd dir echo false kill ln ls mkdir mknod mktemp mv pwd readlink rm rmdir sleep stty su touch true uname vdir
pkg: mkdir -p /usr/sbin
pkg: mv /usr/bin/chroot /usr/sbin
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/coreutils.sh /etc/profile.d
ln -s /bin/chown "${PKG_DEST}"/usr/bin
ln -s /bin/chown "${PKG_DEST}"/usr/sbin
ln -s /bin/mktemp "${PKG_DEST}"/usr/bin
pkg: fakeroot chmod u+s /bin/su
