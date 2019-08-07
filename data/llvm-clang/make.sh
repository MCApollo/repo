pkg:extract
cd swift-llvm-swift*
mv ../swift-clang-swift* tools/clang
pkg:patch
mkdir native
cd native
MACOSX_DEPLOYMENT_TARGET="$(sw_vers -productVersion | sed -e 's/\.[0-9]*$//')" CC="$(xcrun -f clang)" CXX="$(xcrun -f clang++)" cmake -j16 -DCMAKE_INSTALL_NAME_DIR="/usr/local/lib" -DCMAKE_INSTALL_LIBDIR="local/lib" -DLLVM_BUILD_LLVM_DYLIB=ON -DCMAKE_BUILD_TYPE=RELEASE -DLLVM_INCLUDE_TESTS=OFF ..
make -j16 llvm-tblgen clang-tblgen
cd ..
mkdir build
cd build

cat >iphoneos_toolchain.cmake <<EOF
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

unset MACOSX_DEPLOYMENT_TARGET
cmake -j32 -DCMAKE_TOOLCHAIN_FILE=iphoneos_toolchain.cmake -DCMAKE_INSTALL_NAME_DIR="/usr/local/lib" -DCMAKE_INSTALL_LIBDIR="local/lib" -DCMAKE_INSTALL_RPATH="/usr/" -DCMAKE_OSX_SYSROOT="${PKG_ROOT}" -DCMAKE_INSTALL_PREFIX="/usr/" -DLLVM_INCLUDE_TESTS=OFF -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_SYSTEM_NAME=Darwin -DLLVM_TABLEGEN="$(pwd)/../native/bin/llvm-tblgen" -DCLANG_TABLEGEN="$(pwd)/../native/bin/clang-tblgen" -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON -DLLVM_DEFAULT_TARGET_TRIPLE="$(echo ${PKG_TARG} | sed -e s/aarch64/arm64/ -e 's/darwin.*/darwin/')" ..

make -j32
pkg:install
pkg: mkdir -p /usr/local/lib
mv ${PKG_DEST}/usr/lib/*.dylib ${PKG_DEST}/usr/local/lib
pkg: find /usr/lib -name '*.a' -exec rm {} +
pkg: mkdir -p /usr/share/SDKs
cd ..
