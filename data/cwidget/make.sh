pkg:setup
cp ${PKG_BASE}/config.sub .
CXXFLAGS="-std=c++11 -D_XOPEN_SOURCE_EXTENDED -Wno-error" CFLAGS="-D_XOPEN_SOURCE_EXTENDED" pkg:configure
pkg:make -j8
pkg:install
pkg: cp -a cwidget-config.h /usr/include/
