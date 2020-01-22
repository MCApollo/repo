if ! command -v meson ninja &>/dev/null; then
cat << EOF 1>&2

	brew install meson
	brew install ninja
EOF
	exit 127
fi
	
pkg:setup
sed -i "s/subdir('tests')//" meson.build

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

[properties]
c_args	= [ '-I$(PKG_DEST_ cairo)/${PKG_TAPF}/include/cario', '-I$(PKG_DEST_ freetype2)/${PKG_TAPF}/include/freetype2', '-I$(PKG_DEST_ glib)/${PKG_TAPF}/include/glib-2.0', '-I$(PKG_DEST_ glib)/${PKG_TAPF}/lib/glib-2.0/include', '-I$(PKG_DEST_ libpng)/${PKG_TAPF}/include/libpng16', '-I$(PKG_DEST_ pixman)/${PKG_TAPF}/include/pixman-1', '-I$(PKG_DEST_ harfbuzz)/${PKG_TAPF}/include/harfbuzz' ]

EOF

meson --cross-file cross_file.txt --prefix=${PKG_TAPF} --sysconfdir=${PKG_DEST}/etc -Dintrospection=false 
ninja -v
DESTDIR=${PKG_DEST} ninja install -v 
