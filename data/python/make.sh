pkg:extract

############################################

# Build for the host. Configure is picky about having python >= 3.7.

if [ -z "$(which python3.7)" ]; then
    SRC_DIR="$(echo *)"
    mkdir host-python
    cd host-python
    ../Python*/configure --prefix=${PWD}
    make install -j16
    export PATH="${PWD}/bin:$PATH"
    cd ..
fi

cd Python*
pkg:patch

# Feel free to use another variable for this.
# PYTHON_FOR_BUILD will break the build (don't use it).

###########################################

autoconf
pkg:configure CPPFLAGS="-I$(PKG_DEST_ ncurses)/usr/include/ncursesw"     \
        --enable-loadable-sqlite-extensions \
	--with-system-ffi --with-signal-module --enable-big-digits      \
	--with-system-expat --enable-ipv6 --without-ensurepip            \
        ac_cv_file__dev_ptmx=no ac_cv_file__dev_ptc=no ac_cv_func_sendfile=no
pkg:make
pkg:install

# (FIXME) Fix the config to allow for pip installs.
# ./configure / Python will use the $CC from the build.
sed -i  -e "s/-gcc/-clang/" -e "s/-cc/-clang/"		\
	-e "s/-c++/-clang++/" -e "s/-g++/-clang++/"	\
	-e "s/${PKG_TARG}-//"				\
	${PKG_DEST}/${PKG_TAPF}/lib/python*/_sysconfigdata*.py
cp ${PKG_DATA}/install_certificates.command ${PKG_DEST}/${PKG_TAPF}/lib/python*
