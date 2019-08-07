shopt -s extglob
pkg:setup
GOOGLETEST="$(PKG_WORK_ _googletest)" LIBS="-lrpmatch" CXXFLAGS="-std=c++14 -D_XOPEN_SOURCE_EXTENDED -Wno-error" CFLAGS="-D_XOPEN_SOURCE_EXTENDED" pkg:configure XAPIAN_CONFIG="$(PKG_DEST_ libxapian)/usr/bin/xapian-config" --disable-docs --disable-tests --disable-boost-lib-checks --with-boost-iostreams=boost_iostreams --with-boost-filesystem=boost_filesystem --with-boost-system=boost_system
make AR="${PKG_TARG}-ar" -j8
pkg:install
rm -f "${PKG_DEST}"/usr/share/aptitude/!(aptitude-defaults|section-descriptions) #function_groups|function_pkgs
