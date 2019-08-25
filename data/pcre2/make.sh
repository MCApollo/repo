pkg:setup
pkg:configure --disable-dependency-tracking  --enable-pcre2-16 --enable-pcre2-32 --enable-pcre2grep-libz --enable-pcre2grep-libbz2 --enable-jit
make
pkg:install 