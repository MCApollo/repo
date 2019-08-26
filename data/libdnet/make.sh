pkg:setup
ACLOCAL_PATH="$ACLOCAL_PATH:config" autoreconf -ivf
pkg:configure --disable-dependency-tracking 
pkg:install 
