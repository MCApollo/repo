pkg:setup
cat > iphoneos_toolchain.cmake << EOF
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_SYSTEM_NAME Darwin)  # Tell CMake we're cross-compiling
set(CMAKE_CROSSCOMPILING true)
#include(CMakeForceCompiler)
# Prefix detection only works with compiler id "GNU"
# CMake will look for prefixed g++, cpp, ld, etc. automatically
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(triple ${PKG_TARG})
set(CMAKE_FIND_ROOT_PATH $(echo ${PKG_PATH} | sed -e s/:/' '/g))
set(CMAKE_LIBRARY_PATH $(echo ${LIBRARY_PATH} | sed -e s/:/' '/g))
set(CMAKE_INCLUDE_PATH $(echo ${INCLUDE_PATH} | sed -e s/:/' '/g))
set(CMAKE_C_COMPILER ${PKG_TARG}-gcc)
set(CMAKE_CXX_COMPILER ${PKG_TARG}-g++)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG ")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ")

set(JPEG_INCLUDE_DIR "$(PKG_DEST_ jpeg-turbo)/${PKG_TAPF}/include")
set(JPEG_LIBRARY "$(PKG_DEST_ jpeg-turbo)/${PKG_TAPF}/lib/libjpeg.dylib")
EOF

cmake . -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=iphoneos_toolchain.cmake -DCMAKE_LOCALSTATEDIR="${PKG_TAPF}/var" -DCMAKE_OSX_SYSROOT="${PKG_ROOT}" -DCMAKE_INSTALL_PREFIX="${PKG_TAPF}"
make
pkg:install 

tar -xf ${PKG_DATA}/../xorg-server/xorg-server*.tar.* \
    --strip-components=1 -C unix/xserver
cd unix/xserver; patch -Np1 -i ../xserver120.patch; patch -Np1 -i ${PKG_DATA}/../xorg-server/*.diff
autoreconf -ivf \
-I$(PKG_DEST_ util-macros)/${PKG_TAPF}/share/aclocal \
-I$(PKG_DEST_ XorgFonts)/${PKG_TAPF}/share/aclocal \
-I$(PKG_DEST_ Xorg)/${PKG_TAPF}/share/aclocal
pkg:configure \
      --disable-xwayland    --disable-dri        --disable-dmx         \
      --disable-xorg        --disable-xnest      --disable-xvfb        \
      --disable-xwin        --disable-xephyr     --disable-kdrive      \
      --disable-devel-docs  --disable-config-hal --disable-config-udev \
      --disable-unit-tests  --disable-selective-werror                 \
      --disable-static      --enable-dri3                              \
      --without-dtrace      --enable-dri2        --enable-glx --enable-xquartz=no
sed -i 's/-Wl,-z,now//' hw/vnc/Makefile
pkg:install LDFLAGS="-lz\ -undefined\ dynamic_lookup"

pkg: rm -rf ${PKG_TAPF}/lib/xorg/protocol.txt ${PKG_TAPF}/share

