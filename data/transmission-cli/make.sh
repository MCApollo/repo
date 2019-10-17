pkg:setup
LDFLAGS="-framework Foundation -prebind -liconv" \
pkg:configure --disable-dependency-tracking  --disable-mac --disable-nls --without-gtk
pkg:install
