pkg:setup
sed -i -e 's/-U__APPLE__//' -e 's/-mmacosx-version-min=10.3//' configure
pkg:configure --enable-threads --enable-x11 --disable-tests
sed -i 's/__APPLE__/NONEXIST/' $(grep -rl -- __APPLE__ $(find . -name \*.c -o -name \*.cxx -o -name \*.h -o -name \*.H))
#  Hack to remove tests/, not worth to compile for host
#   due to the required libraries headache
sed -i 's/fluid test/fluid/' Makefile
pkg:install 
