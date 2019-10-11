# libdiagnose_usb
# =========================================================

LIBDIAGNOSE_USB_ARCHIVE := obj/libdiagnose_usb/libdiagnose_usb.a

LIBDIAGNOSE_USB_CXXFLAGS := \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/diagnose_usb/include \
    -I$(srcdir)/include \

LIBDIAGNOSE_USB_SRC_FILES := \
    diagnose_usb.cpp \

LIBDIAGNOSE_USB_OBJ_FILES := \
    $(patsubst %.cpp,obj/libdiagnose_usb/%.o,$(LIBDIAGNOSE_USB_SRC_FILES))

DIRS += $(dir $(LIBDIAGNOSE_USB_OBJ_FILES))

libdiagnose_usb: $(LIBDIAGNOSE_USB_ARCHIVE)

$(LIBDIAGNOSE_USB_ARCHIVE): $(LIBDIAGNOSE_USB_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBDIAGNOSE_USB_OBJ_FILES): obj/libdiagnose_usb/%.o: $(srcdir)/core/diagnose_usb/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBDIAGNOSE_USB_CXXFLAGS) -c -o $@ $^
