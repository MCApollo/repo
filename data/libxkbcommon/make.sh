if ! command -v meson ninja &>/dev/null; then
cat << EOF 1>&2

	brew install meson
	brew install ninja
EOF
	exit 127
fi
	
pkg:setup
# sed -i "s/subdir('tests')//" meson.build

mkdir gtk-build; cd gtk-build
cat << EOF >> cross_file.txt
[host_machine]
system = 'darwin'
cpu_family = 'arm'
cpu = 'arm64'
endian = 'little'

[binaries]
c       = '${PKG_TARG}-clang'
cpp     = '${PKG_TARG}-clang++'
# ar      = '${PKG_TARG}-ar'
strip   = '${PKG_TARG}-strip'
pkgconfig = '${PKG_BASE}/util/pkg-config.sh'
objc	= '${PKG_TARG}-clang'
objcpp	= '${PKG_TARG}-clang++'

EOF

AR=ar meson --cross-file cross_file.txt --prefix=${PKG_TAPF} --sysconfdir=${PKG_TAPF}/etc -Denable-wayland=false -Denable-docs=false
ninja -v
DESTDIR=${PKG_DEST} ninja install -v 
