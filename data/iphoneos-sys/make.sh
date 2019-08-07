pkg: mkdir /var
pkg: tar -zxf %/include.tgz -C /var
pkg: rm -rf /var/include/c++/4.0.0/{i686,powerpc{,64},x86_64}-apple-darwin8
pkg: mkdir -p /etc/profile.d
pkg: cp -a %/iphone-headers.sh /etc/profile.d
