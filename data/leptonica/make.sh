pkg:setup
pkg:configure --disable-dependency-tracking  --with-libwebp --with-libopenjpeg	\
	CFLAGS="-I$(PKG_DEST_ openjpeg)/${PKG_TAPF}/include/openjpeg-2.3"
pkg:install 
