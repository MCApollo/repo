pkg:extract
export CFLAGS="-I${PKG_DEST}/${PKG_TAPF}/include"
export LDFLAGS="-L${PKG_DEST}/${PKG_TAPF}/lib"

pkg: mkdir -p ${PKG_TAPF}/lib/pkgconfig
for dir in $(grep -v '^#' ${PKG_DATA}/lib-7.md5 | awk '{print $2}'); do
    dir=${dir%.tar.bz2}
    opt=
    pushd ${dir}
    case ${dir} in
     libICE*) opt="ICE_LIBS=-lpthread" ;;
     libXfont2-[0-9]*) opt="--disable-devel-docs" ;;
     libXt-[0-9]*) opt="--with-appdefaultdir=${PKG_TAPF}/etc/X11/app-defaults" ;;
#     libX11*) opt=LDFLAGS="${LDFLAGS} -lxcb" ;;
     libpciaccess*)
         # Can't be ported, not included.
         mkdir -p include/sys
         cat > include/sys/endian.h << EOF
#include <libkern/OSByteOrder.h>

#define htobe16(x) OSSwapHostToBigInt16(x)
#define htole16(x) OSSwapHostToLittleInt16(x)
#define be16toh(x) OSSwapBigToHostInt16(x)
#define le16toh(x) OSSwapLittleToHostInt16(x)

#define htobe32(x) OSSwapHostToBigInt32(x)
#define htole32(x) OSSwapHostToLittleInt32(x)
#define be32toh(x) OSSwapBigToHostInt32(x)
#define le32toh(x) OSSwapLittleToHostInt32(x)

#define htobe64(x) OSSwapHostToBigInt64(x)
#define htole64(x) OSSwapHostToLittleInt64(x)
#define be64toh(x) OSSwapBigToHostInt64(x)
#define le64toh(x) OSSwapLittleToHostInt64(x)
EOF
     ;;
    esac
    pkg:configure --enable-malloc0returnsnull PKG_CONFIG="${PKG_DATA}/pkg-config.sh" ${opt}
    make -j4
    pkg:install
    ln -rsf ${PKG_DEST}/${PKG_TAPF}/share/pkgconfig/*.pc ${PKG_DEST}/${PKG_TAPF}/lib/pkgconfig/ || :
    popd
done
