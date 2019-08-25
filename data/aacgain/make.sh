pkg:setup
autoreconf -ivf
pkg:configure --disable-debug --disable-dependency-tracking 
pkg:install 
