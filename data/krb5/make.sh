pkg:setup
cd src
pkg:configure ac_cv_func_regcomp=yes ac_cv_printf_positional=yes ac_cv_file__etc_environment=no ac_cv_file__etc_TIMEZONE=no ac_cv_prog_AR="$(which ${PKG_TARG}-ar)" krb5_cv_attr_constructor_destructor=yes,yes
make
pkg:install
pkg: rm -f /usr/bin/{ftp,rcp,rlogin,rsh,telnet}
