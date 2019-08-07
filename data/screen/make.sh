pkg:setup
autoconf
pkg:configure --disable-pam --with-sys-screenrc=/etc/screenrc ac_cv_header_dwarf_h=yes
make
pkg:install
pkg: mkdir -p /etc
pkg: cp -a etc/etcscreenrc /etc/screenrc
