#if [[ ! -L ${PKG_DATA}/xcursorgen*.tar.* ]]; then
#    echo "### Out of sync with XorgApps, fix symlink!" >&2
#    exit 1
#fi

# Host needs xcursorgen, insanity fun :/

pkg:extract
cd xcursor-themes-*

pushd ../xcursorgen-*
mkdir host
url='https://dl.bintray.com/xquartz/downloads/XQuartz-2.7.11.dmg'
wget ${url}
hdiutil attach ${url##*/} || :

x=${url##*/}; x=${x%%.dmg}
pkgutil --expand /Volumes/${x}/XQuartz.pkg tmp
gzip -dc < tmp/x11.pkg/Payload > cpio.tmp; cpio -i < cpio.tmp; mv opt host

export DYLD_FALLBACK_LIBRARY_PATH=${PWD}/host/opt/X11/lib

CFLAGS="-I${PWD}/host/opt/X11/include" \
LDFLAGS="-L${PWD}/host/opt/X11/lib" \
./configure --prefix=${PWD}/host
make install

# Wrapper script
export PATH=${PWD}/host:${PATH}
echo -e "#!/bin/bash\nDYLD_FALLBACK_LIBRARY_PATH=${PWD}/host/opt/X11/lib ${PWD}/host/bin/xcursorgen \$@" > ${PWD}/host/xcursorgen
chmod +x host/xcursorgen

hdiutil detach /Volumes/${x}
popd

pkg:configure
make
# pkg-config messes with install location
sed -i "s|$(PKG_DEST_ Xorg)||" $(find . -iname Makefile)
pkg:install
