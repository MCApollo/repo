pkg:setup

export CC="${PKG_TARG}-gcc"
export CXX="${PKG_TARG}-g++ -std=gnu++1y"
export LD="${PKG_TARG}-ld"
export AR="${PKG_TARG}-ar"
export RANLIB="${PKG_TARG}-ranlib"
export AS="${PKG_TARG}-as"
export LINK="${CXX}"
export RANLIB="${PKG_TARG}-ranlib"
export SDKROOT="${PKG_ROOT}"
export LDFLAGS="-undefined dynamic_lookup"  # libnode needs this- the binary will have the rest of the symbols.

export CC_host="${HOSTCC:-clang}"
export CXX_host="${HOSTCXX:-clang++} -std=gnu++1y"
export LINK_host="${CXX_host}"
export AR_host="${HOSTAR:-ar}"

export CC_target="${CC}"
export CXX_target="${CXX}"
export LINK_target="${CXX}"  # On purpose, see out/Makefile
export AR_target="${AR}"
export LDFLAGS_target="${LDFLAGS}"

GYP_CROSSCOMPILE=1	\
GYP_DEFINES="v8_enable_inspector=1 target_arch=arm64 v8_target_arch=arm64 host_os=$(uname -s | sed -e 's/Linux/linux/;s/Darwin/mac/')"	\
PKG_CONFIG="$(realpath "${PKG_BASE}/util/pkg-config.sh")" \
./configure --prefix="${PKG_TAPF}" --without-snapshot --cross-compiling --dest-os=ios --dest-cpu=arm64 --without-intl --shared-zlib --shared-cares --shared-openssl --shared-nghttp2 --shared

# Don't use pkg:make, CC_host gets overwritten
SDKROOT="" \
make BUILDTYPE=Release DESTCPU=arm64 install DESTDIR="${PKG_DEST}" -j4
pkg: mkdir -p ${PKG_TAPF}/bin/
pkg: cp out/Release/node ${PKG_TAPF}/bin/
ldid -S"${PKG_DATA}/node.xml" "${PKG_DEST}/${PKG_TAPF}/bin/node"
