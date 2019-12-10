if ! command -v meson ninja &>/dev/null; then
cat << EOF 1>&2
Glib requires meson and ninja, headaches ensured.

	brew install meson
	brew install ninja
EOF
	exit 127
fi
	
pkg:setup

mkdir build; cd build
cat << EOF >> cross_file.txt
[host_machine]
system = 'darwin'
cpu_family = 'arm'
cpu = 'arm64'
endian = 'little'

[binaries]
c       = '${PKG_TARG}-clang'
cpp     = '${PKG_TARG}-clang++'
ar      = '${PKG_TARG}-ar'
strip   = '${PKG_TARG}-strip'
pkgconfig = '${PKG_BASE}/util/pkg-config.sh'
objc	= '${PKG_TARG}-clang'
objcpp	= '${PKG_TARG}-clang++'

EOF

meson --cross-file cross_file.txt --prefix=${PKG_TAPF}
ninja -v
DESTDIR=${PKG_DEST} ninja install -v 

pkg: mkdir -p ${PKG_TAPF}/lib/pkgconfig
ln -rs ${PKG_DEST}/${PKG_TAPF}/share/pkgconfig/* ${PKG_DEST}/${PKG_TAPF}/lib/pkgconfig/
