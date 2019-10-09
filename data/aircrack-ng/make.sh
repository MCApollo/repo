pkg:setup
NOCONFIGURE=1 ./autogen.sh 
arm_neon_cxxflags=no ax_cv_neon_cflags=no pkg:configure --disable-silent-rules --disable-dependency-tracking  --with-experimental
pkg:install 
