pkg:setup
x="-I$(PKG_DEST_ glib)/${PKG_TAPF}/include/glib-2.0 -I$(PKG_DEST_ glib)/${PKG_TAPF}/lib/glib-2.0/include -I$(PKG_DEST_ cairo)/${PKG_TAPF}/include/cairo"
pkg:configure --disable-dependency-tracking --with-cairo=yes --with-coretext=yes --with-freetype=yes --with-glib=yes --with-gobject=yes --with-graphite2=yes --with-icu=yes	\
	CFLAGS="$x" CXXFLAGS="$x"
pkg:install 
