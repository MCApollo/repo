pkg:setup
autoreconf -ivf
pkg:configure --disable-debug --disable-dependency-tracking --without-x
pkg:install 
