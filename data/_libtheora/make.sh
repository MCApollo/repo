pkg:setup
cp -f ${PKG_BASE}/config.sub .
pkg:configure --disable-oggtest --disable-vorbistest --disable-examples
pkg:install
