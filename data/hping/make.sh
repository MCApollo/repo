pkg:setup
make distclean
CONFIGOSTYPE="Darwin" CC="${PKG_TARG}-gcc -D__LITTLE_ENDIAN_BITFIEND" ./configure --no-tcl
pkg: mkdir -p "${PKG_TAPF}"/sbin
pkg:install INSTALL_PATH="${PKG_DEST}/${PKG_TAPF}" INSTALL_MANPATH="${PKG_DEST}/${PKG_TAPF}"/share/man
