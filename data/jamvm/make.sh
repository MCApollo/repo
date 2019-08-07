pkg:setup
#PKG_CONF=./autogen.sh
PKG_MCPU=-marm pkg:configure --with-classpath-install-dir=/usr --enable-ffi=no
make with_classpath_install_dir="$(PKG_DEST_ classpath)/usr"
pkg:install
pkg: rm -rf /usr/include
pkg: ln -s jamvm /usr/bin/java
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/jamvm.sh /etc/profile.d
