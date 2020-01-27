pkg:setup

# FIXME: cairo-X11 
#if [[ -d "$(PKG_DEST_ Xorg)/${PKG_TAPF}" ]]; then 
#CFLAGS="-I$(PKG_DEST_ Xorg)/${PKG_TAPF}/include"
#LDFLAGS="-L$(PKG_DEST_ Xorg)/${PKG_TAPF}/lib"
#X_FLAGS='--enable-xcb=yes --enable-xlib=yes --enable-xlib-xrender=yes'
#export PKG_CONFIG_PATH="$(PKG_DEST_ Xorg)/${PKG_TAPF}/lib/pkgconfig"
#else
#X_FLAGS='--enable-xcb=no --enable-xlib=no --enable-xlib-xrender=no'
#echo -e "\n\n#####\nWARNING: Cairo-X11 is not being built! './make.sh Xorg'\n#####\n\n"; sleep 5
#fi

PKG_CONFIG=${PKG_DATA}/pkg-config.sh \
pkg:configure --disable-dependency-tracking  --enable-gobject=yes --enable-svg=yes --enable-tee=yes ${X_FLAGS} \
	CFLAGS="-I$(PKG_DEST_ pixman)/${PKG_TAPF}/include/pixman-1 -I$(PKG_DEST_ glib)/${PKG_TAPF}/include/glib-2.0 -I$(PKG_DEST_ glib)/${PKG_TAPF}/lib/glib-2.0/include ${CFLAGS}" LDFLAGS="${LDFLAGS}" 
pkg:install 
