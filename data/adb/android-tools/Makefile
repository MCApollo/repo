# Core makefiles taken from:
# https://github.com/smaeul/android-tools
# Credit goes towards Samuel Holland.

# Mac C (MCApollo) edits toward iOS port/compile.
# Only adb is built (for now?)

srcdir := $(PWD)

CC = aarch64-apple-darwin17-clang
CFLAGS ?= -g -Os
CFLAGS += \
    -std=gnu18 \
    -Wall \
    -Wextra \
    -Werror=implicit-function-declaration \
    -Werror=implicit-int \
    -Wno-unused-parameter \
    -miphoneos-version-min=12.0
CXX = aarch64-apple-darwin17-clang++ 
CXXFLAGS ?= -g -Os
CXXFLAGS += \
    -std=gnu++2a \
    -Wall \
    -Wextra \
    -Werror=implicit-function-declaration \
    -Werror=implicit-int \
    -Wno-unused-parameter \
    -miphoneos-version-min=12.0
LDFLAGS :=
AR=aarch64-apple-darwin17-ar
PREFIX = /usr

all:

clean:
	rm -rf obj

include rules/adb.mk
include rules/libbase.mk
include rules/libcrypto_utils.mk
include rules/libcutils.mk
include rules/libdiagnose_usb.mk
include rules/liblog.mk
include rules/liblp.mk
include rules/libmdnssd.mk
include rules/libsparse.mk
include rules/libutils.mk
include rules/libziparchive.mk

BINS := $(sort $(BINS))
DIRS := $(sort $(DIRS))

all: $(BINS)
dirs: $(DIRS)

$(DIRS):
	mkdir -p $@

install: $(BINS)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m0755 $(BINS) $(DESTDIR)$(PREFIX)/bin

.PHONY: all clean dirs install
