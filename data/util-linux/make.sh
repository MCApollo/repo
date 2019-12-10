pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules  --disable-ipcs --disable-ipcrm --disable-wall --enable-libuuid 
pkg:install 

cd ${PKG_DEST}/${PKG_TAPF}/
for prog in cal col colcrt colrm getopt hexdump logger nologin look mesg more renice rev ul whereis; do
    rm -f bin/${prog}    || :
    rm -f sbin/${prog}   || :
    rm -f man1/${prog}.1 || :
    rm -f man8/${prog}.8 || :
    rm -f share/bash-completion/completions/${prog} || :
done

