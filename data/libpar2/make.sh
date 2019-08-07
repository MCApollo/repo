pkg:setup
autoreconf -f -i
PKG_CONFIG="$(realpath "${PKG_BASE}/util/pkg-config.sh")" ./configure ac_cv_prog_cc_g=no ac_cv_prog_cxx_g=no --build="$(${PKG_BASE}/util/config.guess)" --host="${PKG_TARG}" --enable-static=no --enable-shared=yes --prefix="$(cat "${PKG_BASE}/arch/${PKG_ARCH}/prefix")" --localstatedir="/var/cache/${PKG_NAME}" CFLAGS="-O2  -fno-common" CXXFLAGS="-O2  -fno-common -std=c++11"
make -j8
pkg:install
