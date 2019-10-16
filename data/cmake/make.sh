pkg:setup

# Private header- don't expect to be any includes.
mkdir Source/CoreFoundation
cp "${PKG_DATA}"/*.h Source/CoreFoundation

mkdir build && cd build
cat >iphoneos_toolchain.cmake <<EOF
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
EOF

cmake -j4 -DCMAKE_BUILD_TYPE=Release -DCMAKE_Fortran_COMPILER:FILEPATH=FALSE -DCMAKE_TOOLCHAIN_FILE=iphoneos_toolchain.cmake -DCMAKE_LOCALSTATEDIR="/private/var" -DCMAKE_INSTALL_NAME_DIR="/usr/lib" -DCMAKE_INSTALL_RPATH="/usr/" -DCMAKE_OSX_SYSROOT="${PKG_ROOT}" -DCMAKE_INSTALL_PREFIX="/usr/" -DKWSYS_LFS_WORKS=FALSE ..
make -j4
pkg:install
