pkg: mkdir /Applications
javac -source 1.5 -d . -cp "$(PKG_DEST_ jocstrap)/usr/share/java/jocstrap.jar:$(PKG_DEST_ javasqlite)/usr/share/java/sqlite.jar" "${PKG_DATA}/HelloJava.app/HelloJava.java"
pkg: cp -a %/Hello{Java,Script}.app /Applications
cp -a *.class "${PKG_DEST}/Applications/HelloJava.app"
pkg: find / -name '.svn' -prune -exec rm -rfv {} \;
