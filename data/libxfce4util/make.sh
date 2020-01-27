if ! command -v intltool-update &>/dev/null; then
echo 'brew install intltool'
exit 127
fi

pkg:setup

# XML not found- homebrew issue intltool
mkdir host; pushd host
url='https://cpan.metacpan.org/authors/id/T/TO/TODDR/XML-Parser-2.44.tar.gz'
wget ${url}
tar xf ${url##*/}; rm ${url##*/}
cd *
perl Makefile.PL INSTALL_BASE=${PWD}/../
make install
popd

# LDFLAGS="-undefined dynamic_lookup" \
PERL5LIB="${PWD}/host/lib/perl5/" \
pkg:configure --enable-visibility=no #  --enable-maintainer-mode FIXME: HAVE_GNUC_VISIBILITY - iPhone.diff doesn't fix alias issues
pkg:install
