pkg:setup
export PATH
SCONS="scons APR=\"$(echo $(PKG_WORK_ _apr)/*/apr-1-config)\" APU=\"$(echo $(PKG_WORK_ apr-util)/*/apu-1-config)\" OPENSSL=\"$(PKG_DEST_ _openssl1.0)/usr\" PREFIX=/usr LIBDIR=/usr/lib CC=\"$(which ${PKG_TARG}-gcc)\" SOURCE_LAYOUT=1 LINKFLAGS=\"-L$(PKG_DEST_ _apr)/usr/lib -L$(PKG_DEST_ apr-util)/usr/lib -L$(PKG_DEST_ expat)/usr/lib\""
echo ${SCONS}
eval ${SCONS}
mkdir -p "$(PKG_DEST_ libserf)"
scons install --install-sandbox="$(PKG_DEST_ libserf)"
pkg: rm /usr/lib/libserf-1.a
