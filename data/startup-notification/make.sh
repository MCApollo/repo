pkg:setup
cp ${PKG_BASE}/util/config.sub .
lf_cv_sane_realloc=yes \
pkg:configure --disable-debug --disable-dependency-tracking --disable-silent-rules 
pkg:install 
