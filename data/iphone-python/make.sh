pkg: mkdir /Applications
pkg: cp -a %/HelloPython.app /Applications
pkg: find / -name '.svn' -prune -exec rm -rfv {} \;
