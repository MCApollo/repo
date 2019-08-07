pkg:setup
pkg:configure HTOP_NCURSESW6_CONFIG_SCRIPT="${PKG_DATA}/ncursesw6-config" --disable-linux-affinity
pkg:make -j8
pkg:install
pkg: rm -rf /usr/share
