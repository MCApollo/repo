pkg:setup
ac_cv_func_stat64=no pkg:configure --disable-dependency-tracking
make
pkg:install 
