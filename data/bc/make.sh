pkg:setup
unset BC_ENV_ARGS
autoreconf -ivf
pkg:configure --disable-debug --disable-dependency-tracking --disable-silent-rules
pkg:install 
