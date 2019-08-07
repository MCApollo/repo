pkg:setup
cd uicaboodle.java
mv ../minimal source/com/saurik/uicaboodle
./ant.sh
pkg: mkdir -p /usr/lib /usr/share/java
pkg: cp -a archives/libuicaboodle.jnilib /usr/lib
pkg: cp -a archives/uicaboodle.jar /usr/share/java
