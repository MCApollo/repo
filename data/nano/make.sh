pkg:setup
pkg:configure --enable-all --sysconfdir=/etc
make -j8
pkg:install
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/nano.sh /etc/profile.d
pkg: cp -a ./doc/sample.nanorc /usr/share/nano
