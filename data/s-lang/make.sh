pkg:setup
pkg:configure
make
make install DESTDIR=${PKG_DEST} # => multiple jobs will break make.
