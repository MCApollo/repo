pkg:setup
ac_cv_c_stack_direction=-1 zsh_cv_rlimit_vmem_is_rss=no zsh_cv_rlimit_vmem_is_as=no zsh_cv_rlimit_rss_is_as=yes zsh_cv_sys_fifo=no zsh_cv_sys_link=yes zsh_cv_sys_killesrch=yes zsh_cv_sys_sigsuspend=yes zsh_cv_sys_tcsetpgrp=yes zsh_cv_sys_getpwnam_faked=no zsh_cv_sys_elf=no zsh_cv_func_dlsym_needs_underscore=no pkg:configure --enable-fndir=${PKG_TAPF}/share/functions --enable-scriptdir=${PKG_TAPF}/share/scripts --enable-site-fndir=${PKG_TAPF}/share/zsh/site-functions --enable-site-scriptdir=${PKG_TAPF}/share/zsh/site-scripts --enable-runhelpdir=${PKG_TAPF}/share/help --enable-cap --enable-maildir-support --enable-multibyte --enable-pcre --enable-zsh-secure-free --enable-unicode9 --enable-etcdir=${PKG_TAPF}/etc/zsh --with-tcsetpgrp DL_EXT=bundle
sed -i 's|$(libdir)/$(tzsh)/$(VERSION)|$(libdir)|'	\
	Makefile Src/Makefile
pkg:install install.info

pkg: mkdir -p ${PKG_TAPF}/etc/zsh
cp -r ${PKG_DATA}/etc/* ${PKG_DEST}/${PKG_TAPF}/etc/zsh/
