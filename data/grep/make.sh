pkg:setup
pkg:configure --disable-perl-regexp --bindir=/bin ac_use_included_regex=no
make -j8
pkg:install
