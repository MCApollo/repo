pkg:setup
automake -a -c -f 2>/dev/null || true
pkg:configure --with-readline-inc=-I"$(PKG_DEST_ readline)"/usr/include/readline --with-readline-lib=-lreadline --disable-tcl
make
pkg:install
