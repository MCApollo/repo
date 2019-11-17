pkg:setup
sed -i "s|%TARGET%|${PKG_TARG}|" src/mkheader.c
pkg:configure --disable-dependency-tracking --disable-silent-rules  
pkg:install 
