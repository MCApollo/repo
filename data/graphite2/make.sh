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
EOF

sed -i 's|-mfpmath=sse||' src/CMakeLists.txt
# ^ only for x86 arch, not arm.
cmake . -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=iphoneos_toolchain.cmake -DCMAKE_LOCALSTATEDIR="${PKG_TAPF}/var" -DCMAKE_OSX_SYSROOT="${PKG_ROOT}" -DCMAKE_INSTALL_PREFIX="${PKG_TAPF}"
make
pkg:install 
