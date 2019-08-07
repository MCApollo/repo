pkg:setup
pkg:configure sudo_cv_uid_t_len=10 sudo_cv_type_long_is_quad=no --without-pam --with-env-editor ac_cv_func_utimensat=no ac_cv_func_futimens=no
pkg:make
pkg:install
