pkg:setup
pushd src
pkg:configure --disable-native-tests --disable-simd  # TODO: Fix John-Jumbo neon/simd.
pkg:install
popd

pkg: mkdir -p ${PKG_TAPF}/{bin,share/john}
cp -r run/* ${PKG_DEST}/${PKG_TAPF}/share/john/
pkg: ln -rs ${PKG_TAPF}/share/john ${PKG_TAPF}/bin/
