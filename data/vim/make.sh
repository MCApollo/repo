pkg:extract
cd *

for patch in "${PKG_DATA}/patches/8.1."*; do
    echo Applying patch $(basename "${patch}")
    patch -p0 <"${patch}"
done

pkg:patch
cd src
autoconf
cd ..
pkg:configure --enable-gui=no --without-x vim_cv_toupper_broken=no --with-tlib=ncurses vim_cv_terminfo=yes vim_cv_tty_group=4 vim_cv_tty_mode=0620 vim_cv_getcwd_broken=no vim_cv_stat_ignores_slash=no ac_cv_sizeof_int=4 vim_cv_memmove_handles_overlap=yes vim_cv_tgetent=zero --disable-darwin
make
pkg:install
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/vim.sh /etc/profile.d
pkg: ln -s vim /usr/bin/vi
