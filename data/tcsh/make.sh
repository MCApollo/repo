pkg:setup
pkg:configure ac_cv_func_setpgrp_void=yes --bindir=/bin
make -j8
pkg:install
