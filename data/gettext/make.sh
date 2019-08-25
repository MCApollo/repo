pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules --disable-debug  --with-included-gettext --with-included-glib --with-included-libcroco --with-included-libunistring --disable-java --disable-csharp --without-git --without-cvs --with-xz 
pkg:make
pkg:install 
