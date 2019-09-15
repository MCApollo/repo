pkg:setup
CPPFLAGS="-DSQLITE_ENABLE_COLUMN_METADATA=1 -DSQLITE_MAX_VARIABLE_NUMBER=250000 -DSQLITE_ENABLE_RTREE=1 -DSQLITE_ENABLE_FTS3=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1 -DSQLITE_ENABLE_JSON1=1"	\
pkg:configure  --disable-dependency-tracking --enable-dynamic-extensions --enable-readline --disable-editline --enable-session
pkg:install 
