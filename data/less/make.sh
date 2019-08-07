pkg:setup
pkg:configure
pkg:make
pkg:install
pkg: mkdir -p /etc/profile.d /bin
pkg: cp -a %/less.sh /etc/profile.d
pkg: ln -s less /usr/bin/more
ln -s /usr/bin/less "${PKG_DEST}"/bin/more
