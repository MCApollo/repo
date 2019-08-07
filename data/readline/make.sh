pkg:extract
cd *

for ((x = 1; x != 1; ++x)); do
    patch -p0 <"${PKG_DATA}/readline80-$(printf '%.3u\n' "$x")"
done

pkg:patch
autoconf
pkg:configure ac_cv_func_strcoll_works=yes bash_cv_func_sigsetjmp=present bash_cv_func_ctype_nonascii=no bash_cv_must_reinstall_sighandlers=no bash_cv_func_strcoll_broken=yes
make CFLAGS='-O2'
pkg:install
pkg: ln -s libreadline.5.2.dylib /usr/lib/libreadline.5.dylib
pkg: ln -s libreadline.6.0.dylib /usr/lib/libreadline.5.2.dylib
pkg: ln -s libreadline.7.0.dylib /usr/lib/libreadline.6.0.dylib
pkg: ln -s libreadline.7.0.dylib /usr/lib/libreadline.7.dylib
pkg: ln -s libreadline.8.0.dylib /usr/lib/libreadline.7.0.dylib
pkg: ln -s libhistory.5.2.dylib /usr/lib/libhistory.5.dylib
pkg: ln -s libhistory.6.0.dylib /usr/lib/libhistory.5.2.dylib
pkg: ln -s libhistory.7.0.dylib /usr/lib/libhistory.6.0.dylib
pkg: ln -s libhistory.7.0.dylib /usr/lib/libhistory.7.dylib
pkg: ln -s libhistory.8.0.dylib /usr/lib/libhistory.7.0.dylib
