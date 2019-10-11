# Copyright 2005 The Android Open Source Project
#
# Android.mk for adb
#

adb_version := $(shell git submodule status core | cut -c2-9)-android

ADB_COMMON_CXXFLAGS := \
    -DADB_HOST=1 \
    -DALLOW_ADBD_ROOT=0 \
    -DADB_VERSION='"$(adb_version)"' \
    -I$(srcdir)/include \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/diagnose_usb/include \
    -I$(srcdir)/core/include \
    -I$(srcdir)/core/libcrypto_utils/include \
    -Wexit-time-destructors \
    -Wno-missing-field-initializers \
    -Wno-thread-safety \
    -Wno-unused-parameter \
    -Wvla \

# libadb
# =========================================================

LIBADB_ARCHIVE := obj/libadb/libadb.a

LIBADB_CXXFLAGS := \
    $(ADB_COMMON_CXXFLAGS) \
    -fvisibility=hidden \
    -I$(srcdir)/core/adb \
    -I$(srcdir)/libusb/include \
    -I$(srcdir)/mdnsresponder/mDNSShared \

LIBADB_SRC_FILES := \
    adb.cpp \
    adb_io.cpp \
    adb_listeners.cpp \
    adb_trace.cpp \
    adb_unique_fd.cpp \
    adb_utils.cpp \
    client/adb_install.cpp \
    client/auth.cpp \
    client/transport_mdns.cpp \
    client/usb_dispatch.cpp \
    client/usb_libusb.cpp \
    client/usb_osx.cpp \
    fdevent.cpp \
    services.cpp \
    sockets.cpp \
    socket_spec.cpp \
    sysdeps/errno.cpp \
    sysdeps/posix/network.cpp \
    sysdeps_unix.cpp \
    transport.cpp \
    transport_fd.cpp \
    transport_local.cpp \
    transport_usb.cpp \

LIBADB_OBJ_FILES := \
    $(patsubst %.cpp,obj/libadb/%.o,$(LIBADB_SRC_FILES))

DIRS += $(dir $(LIBADB_OBJ_FILES))

libadb: $(LIBADB_ARCHIVE)

$(LIBADB_ARCHIVE): $(LIBADB_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBADB_OBJ_FILES): obj/libadb/%.o: $(srcdir)/core/adb/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBADB_CXXFLAGS) -c -o $@ $^

# adb host tool
# =========================================================

ADB_BINARY := obj/adb/adb

ADB_CXXFLAGS := \
    $(ADB_COMMON_CXXFLAGS) \
    -D_GNU_SOURCE \
    -I$(srcdir)/core/adb \

ADB_LDFLAGS := $(shell pkg-config.sh --libs libcrypto || echo -lcrypto) -lusb-1.0 -framework IOKIT -framework CoreFoundation

ADB_LIBS := \
    libadb \
    libbase \
    libcrypto_utils \
    libcutils \
    libdiagnose_usb \
    liblog \
    libmdnssd \

ADB_SRC_FILES := \
    client/adb_client.cpp \
    client/bugreport.cpp \
    client/commandline.cpp \
    client/console.cpp \
    client/file_sync_client.cpp \
    client/line_printer.cpp \
    client/main.cpp \
    shell_service_protocol.cpp \

ADB_LIB_DEPS := \
	$(foreach lib,$(ADB_LIBS),obj/$(lib)/$(lib).a)

ADB_OBJ_FILES := \
    $(patsubst %.cpp,obj/adb/%.o,$(ADB_SRC_FILES))

BINS += $(ADB_BINARY)
DIRS += $(dir $(ADB_OBJ_FILES))

adb: $(ADB_BINARY)

$(ADB_BINARY): $(ADB_OBJ_FILES) $(ADB_LIB_DEPS) | dirs
	$(CXX) $(CXXFLAGS) $(ADB_CXXFLAGS) -o $@ $^ $(LDFLAGS) $(ADB_LDFLAGS)

$(ADB_OBJ_FILES): obj/adb/%.o: $(srcdir)/core/adb/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(ADB_CXXFLAGS) -c -o $@ $^
