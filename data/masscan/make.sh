pkg:setup
pkg:make

pkg: mkdir -p "${PKG_TAPF}/bin"
cp  bin/masscan "${PKG_DEST}/${PKG_TAPF}"/bin
