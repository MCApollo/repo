pkg:setup
pkg:configure --disable-dependency-tracking  --enable-gobject=yes --enable-svg=yes --enable-tee=yes --enable-xcb=no --enable-xlib=no --enable-xlib-xrender=no	\
	CFLAGS="-I$(PKG_DEST_ pixman)/${PKG_TAPF}/include/pixman-1 -I$(PKG_DEST_ glib)/${PKG_TAPF}/include/glib-2.0 -I$(PKG_DEST_ glib)/${PKG_TAPF}/lib/glib-2.0/include"
pkg:install 
