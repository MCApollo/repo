pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure ac_cv_c_stack_direction=-1 zsh_cv_rlimit_vmem_is_rss=no zsh_cv_rlimit_vmem_is_as=no zsh_cv_rlimit_rss_is_as=yes zsh_cv_sys_fifo=no zsh_cv_sys_link=yes zsh_cv_sys_killesrch=yes zsh_cv_sys_sigsuspend=yes zsh_cv_sys_tcsetpgrp=yes zsh_cv_sys_getpwnam_faked=no zsh_cv_sys_elf=no zsh_cv_func_dlsym_needs_underscore=no zsh_cv_path_utmpx=/var/run/utmpx --enable-function-subdirs --bindir=/bin
pkg:make
pkg:install
