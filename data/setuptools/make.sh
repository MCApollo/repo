#tail -n +9 "${PKG_DATA}/setuptools-0.6c7-py2.5.egg" >setuptools.zip
#unzip -d setuptools setuptools.zip
#cd setuptools
pkg: mkdir -p /usr/bin /usr/lib/python2.5/site-packages
pkg: cp -a %/easy_install %/easy_install-2.5 /usr/bin
pkg: cp -a %/easy-install.pth %/setuptools-0.6c7-py2.5.egg %/setuptools.pth /usr/lib/python2.5/site-packages
