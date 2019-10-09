if ! command -v protoc &>/dev/null; then
	echo "Google protobuf is required for \`protoc\`"
	echo "brew install protobuf"
	exit 127
fi

pkg:setup
CXXFLAGS="-std=c++11" pkg:configure  --enable-completion --with-ncursesw
pkg:install 
