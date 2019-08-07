pkg:setup
autoconf
PCRE_LIB=-lpcre pkg:configure --libdir=/usr/lib/lighttpd --with-bz2 --with-webdav-locks --with-webdav-props
make
pkg:install
