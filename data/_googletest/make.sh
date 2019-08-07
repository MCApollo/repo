pkg:extract
mv * googletest
cd googletest
#autoreconf -f -i
#pkg:configure
#pkg:make -j8
pkg: mkdir -p /usr/{lib,include}
pkg: cp -a {googletest,googlemock}/include/. /usr/include/
#pkg: cp -a {googletest,googlemock}/lib/.libs/lib*.dylib /usr/lib
#pkg: cp {googletest,googlemock}/lib/.libs/lib*.la /usr/lib
