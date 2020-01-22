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
c_args = [ '-I$(PKG_DEST_ glib)/${PKG_TAPF}/include/glib-2.0', '-I$(PKG_DEST_ glib)/${PKG_TAPF}/include/gio-unix-2.0', '-I$(PKG_DEST_ glib)/${PKG_TAPF}/lib/glib-2.0/include', '-I$(PKG_DEST_ dbus)/${PKG_TAPF}/include/dbus-1.0', '-I$(PKG_DEST_ dbus)/${PKG_TAPF}/lib/dbus-1.0/include']

EOF

AR=ar meson --cross-file cross_file.txt --prefix=${PKG_TAPF} --sysconfdir=${PKG_TAPF}/etc -Dgir=false-Dtests=off
ninja -v
DESTDIR=${PKG_DEST} ninja install -v 
