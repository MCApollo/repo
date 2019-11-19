pkg:setup

mkdir host-bin
clang -I./tools/lemon ./tools/lemon/lemon.c -o host-bin/lemon
PATH=${PWD}/host-bin:${PATH}
sed -i 's/HAVE_MACOS_FRAMEWORKS/XXX/'  caputils/capture-pcap-util.c  # FIXME: Use of macos only functions.

cat > iphoneos_toolchain.cmake << EOF
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
EOF
cmake . -DCMAKE_OSX_SYSROOT="${PKG_ROOT}" -DCMAKE_LOCALSTATEDIR="${PKG_TAPF}/var" -DCMAKE_INSTALL_NAME_DIR="${PKG_TAPF}/lib" -DCMAKE_INSTALL_RPATH="${PKG_TAPF}" -DCMAKE_INSTALL_PREFIX="${PKG_TAPF}" -DCMAKE_TOOLCHAIN_FILE=iphoneos_toolchain.cmake -DINSTALL_SYSCONFDIR="${PKG_TAPF}"/etc -DENABLE_CARES=ON -DENABLE_GNUTLS=ON -DENABLE_MAXMINDDB=ON -DBUILD_wireshark_gtk=OFF -DENABLE_PORTAUDIO=OFF -DENABLE_SMI=ON -DBUILD_sshdump=ON -DBUILD_ciscodump=ON  -DENABLE_NGHTTP2=ON -DBUILD_wireshark=OFF -DENABLE_APPLICATION_BUNDLE=OFF -DENABLE_QT5=OFF
pkg:install    
