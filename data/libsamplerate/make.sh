pkg:setup
autoreconf -ivf
pkg:configure --disable-dependency-tracking 
pkg:install 
