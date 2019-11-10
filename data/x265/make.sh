pkg:setup

cat > iphoneos_toolchain.cmake <<EOF
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

export MACOSX_DEPLOYMENT_TARGET="${IPHONEOS_DEPLOYMENT_TARGET}"

_cmake_args=(-DCMAKE_OSX_SYSROOT="${PKG_ROOT}" -DCMAKE_LOCALSTATEDIR="${PKG_TAPF}/var" -DCMAKE_INSTALL_NAME_DIR="${PKG_TAPF}/lib" -DCMAKE_INSTALL_RPATH="${PKG_TAPF}" -DCMAKE_INSTALL_PREFIX="${PKG_TAPF}" -DCMAKE_TOOLCHAIN_FILE=$(realpath iphoneos_toolchain.cmake) -DINSTALL_SYSCONFDIR="${PKG_TAPF}"/etc)
_args=(-DENABLE_STATIC=OFF -DEXTRA_LIB="x265_main10.a;x265_main12.a" -DLINKED_10BIT=ON -DLINKED_12BIT=ON -DEXTRA_LINK_FLAGS="-Lx265-10bit -Lx265-12bit")
_high_bit=(-DHIGH_BIT_DEPTH=ON -DEXPORT_C_API=OFF -DENABLE_SHARED=OFF -DENABLE_CLI=OFF)

cd build
mkdir x265-10bit x265-12bit || true

pushd x265-10bit
	cmake ../../source "${_cmake_args[@]}" "${_high_bit[@]}"
	make -j16
	mv libx265.a libx265_main10.a
popd

pushd x265-12bit
	cmake ../../source "${_cmake_args[@]}" -DMAIN12=ON "${_high_bit[@]}"
	make -j16
	mv libx265.a libx265_main12.a
popd 

echo cmake ../source "${_cmake_args[@]}" "${_args[@]}"
cmake ../source "${_cmake_args[@]}" "${_args[@]}"
make -j16
pkg:install
pkg: rm ${PKG_TAPF}/lib/libx265.a
