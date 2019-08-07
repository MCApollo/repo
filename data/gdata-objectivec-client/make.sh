pkg:setup
"${PKG_TARG}-gcc" -std=c99 -fobjc-exceptions -I"$(PKG_DEST_ libxml2)/usr/include/libxml2" -I. -ISource/{.,ACL,BaseClasses,Elements,Geo,Media,Networking,XMLSupport} -ISource/Clients/{Calendar,CodeSearch,Contacts,Docs,GoogleBase,Photos,Spreadsheets,YouTube} -o GData -dynamiclib $(find Source -name Tests -prune -o -name '*.m' -print) -lobjc -framework CoreFoundation -framework Foundation -lxml2 -install_name /System/Library/Frameworks/GData.framework/GData
pkg: mkdir -p /System/Library/Frameworks/GData.framework/Headers
pkg: cp -a %/Info.plist GData /System/Library/Frameworks/GData.framework
pkg: cp -a $(find Source -name Tests -prune -o -name '*.h' -print) /System/Library/Frameworks/GData.framework/Headers
