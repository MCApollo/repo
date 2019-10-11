# libziparchive
# =========================================================

LIBZIPARCHIVE_ARCHIVE := obj/libziparchive/libziparchive.a

LIBZIPARCHIVE_CXXFLAGS := \
    -D_FILE_OFFSET_BITS=64 \
    -DZLIB_CONST \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/include \
    -I$(srcdir)/core/libziparchive/include \
    -I$(srcdir)/include \
    -Wold-style-cast \
    -Wno-logical-not-parentheses \
    -Wno-missing-field-initializers \

LIBZIPARCHIVE_SRC_FILES := \
    zip_archive.cc \
    zip_archive_stream_entry.cc \

LIBZIPARCHIVE_CXX_OBJ_FILES := \
    $(patsubst %.cc,obj/libziparchive/%.o,$(LIBZIPARCHIVE_SRC_FILES))

DIRS += $(dir $(LIBZIPARCHIVE_CXX_OBJ_FILES))

libziparchive: $(LIBZIPARCHIVE_ARCHIVE)

$(LIBZIPARCHIVE_ARCHIVE): $(LIBZIPARCHIVE_CXX_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBZIPARCHIVE_CXX_OBJ_FILES): obj/libziparchive/%.o: $(srcdir)/core/libziparchive/%.cc | dirs
	$(CXX) $(CXXFLAGS) $(LIBZIPARCHIVE_CXXFLAGS) -c -o $@ $^
