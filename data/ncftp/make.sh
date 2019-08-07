pkg:setup
CFLAGS="-O2  -fno-common" CXXFLAGS="-O2  -fno-common" RANLIB=$(which "${PKG_TARG}-ranlib") CC=$(which "${PKG_TARG}-gcc") ./configure --build="$(${PKG_BASE}/util/config.guess)" --host="${PKG_TARG}" --enable-static=no --enable-shared=yes --prefix="$(cat "${PKG_BASE}/arch/${PKG_ARCH}/prefix")" --localstatedir="/var/cache/${PKG_NAME}" 
make -j8
mkdir -p "${PKG_DEST}/usr/share"
pkg:install
