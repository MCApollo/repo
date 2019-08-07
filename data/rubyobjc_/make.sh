pkg:setup
pkg: cp -a %/UIKit.xml bridged
cd objc
for bridge in foundation uikit; do
    ruby ../ruby/bridge.rb "${bridge}" >../ruby/"${bridge}".rb
done
erb fast_handlers.ri >fast_handlers.i
${PKG_TARG}-gcc -o objc.bundle -bundle *.m -I"${PKG_ROOT}"/usr/lib/ruby/1.8/arm-darwin -lffi -lobjc -framework Foundation -framework CoreFoundation -lruby -framework UIKit
pkg: mkdir -p /usr/lib/ruby/site_ruby/1.8/arm-darwin
pkg: cp -a objc.bundle /usr/lib/ruby/site_ruby/1.8/arm-darwin
cd ../ruby
pkg: cp -a {foundation,generator,objc,uikit}.rb /usr/lib/ruby/site_ruby/1.8
