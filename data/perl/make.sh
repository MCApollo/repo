pkg:extract
VERSION="$(cat "${PKG_DATA}/_metadata/version")"
cp -af perl-cross*/. perl-5*/
cd perl-5*/
pkg:patch
PREFIX="$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/prefix")"
CFLAGS='-DPERL_DARWIN' ./configure --build="$(${PKG_BASE}/util/config.guess)" --target="${PKG_TARG}" --prefix="${PREFIX}" -Duseshrplib -Dusevendorprefix --vendorprefix="${PREFIX}" -Dusethreads \
			 -Dvendorlib="${PREFIX}/share/perl5" -Dvendorarch="${PREFIX}/lib/perl5/${VERSION}"
make -j16
make install.perl DESTDIR="${PKG_DEST}"
