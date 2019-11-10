pkg:setup
cp ${PKG_BASE}/util/{config.guess,config.sub} .
pkg:configure --disable-dependency-tracking  --disable-oggtest --disable-vorbistest --disable-examples 
pkg:install 
