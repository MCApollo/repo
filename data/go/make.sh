pkg:setup
cd src

if ! command -v go >&/dev/null; then
	url='https://storage.googleapis.com/golang/go1.7.darwin-amd64.tar.gz'
	echo
	echo "Go needs to be installed."
	echo
	echo "Extract the url to ${TMPDIR:-/tmp} and append it to \$PATH and \$GOROOT_BOOTSTRAP"
	echo "url: ${url}"
	exit 127
fi

export GOROOT_FINAL="${PKG_TAPF}/libexec/go"
export GOARCH=arm64
export GOOS=darwin
export CGO_ENABLED=1
export CC_FOR_TARGET="${PKG_TARG}-clang"
export CXX_FOR_TARGET="${PKG_TARG}-clang++"

sed -i "s|@ENT_FILE@|${GOROOT_FINAL}/entitlement.xml|"	\
	cmd/go/internal/work/buildid.go	\
	cmd/link/internal/ld/main.go 

./make.bash --no-clean

cd ..
for file in AUTHORS CONTRIBUT* favicon.ico LICENSE PATENTS README.md robots.txt VERSION api pkg/obj; do
	rm -rf ${file} || :
done
ln -rsf bin/darwin_arm64/* bin/
pkg: mkdir -p "${GOROOT_FINAL}" "${PKG_TAPF}"/bin
cp -Rv . "${PKG_DEST}/${GOROOT_FINAL}"/

pkg: ln -rs "${GOROOT_FINAL}"/bin/go "${PKG_TAPF}"/bin
pkg: ln -rs "${GOROOT_FINAL}"/bin/gofmt "${PKG_TAPF}"/bin
cp "${PKG_DATA}"/entitlement.xml "${PKG_DEST}/${GOROOT_FINAL}"/

rm -rf $(find ${PKG_DEST} -name darwin_amd64)
