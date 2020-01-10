if ! command -v meson ninja &>/dev/null; then
cat << EOF 1>&2
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
cpu_family = 'aarch64'
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
c_link_args = ['-lXxf86vm']

EOF

# Notes
# Meson sets PYTHONPATH, so we have to install to $HOME
# Can't install to a tmpdir because meson sucks.
#    tar xvf ${PKG_DATA}/Mako/Mako-*.tar.*
#    python3 Mako-*/setup.py install --user --prefix=
# OR
#    sudo pip3 install mako
# If the above fails.
#
# FIXME: lXxf86vm isn't linked without help.

echo  -e "#####\n\nSee Notes in make.sh if Meson fails.\n\n#####" >&2
sleep 1

GALLIUM_DRV="swrast"
DRI_DRIVERS=""

AR=ar meson --cross-file cross_file.txt --prefix=${PKG_TAPF} -Dbuildtype=release -Ddri-drivers=${DRI_DRIVERS} -Dgallium-drivers=${GALLIUM_DRV} -Dgallium-nine=false -Dglx=dri -Dosmesa=gallium  -Dplatforms=auto
ninja -v
DESTDIR=${PKG_DEST} ninja install -v 

