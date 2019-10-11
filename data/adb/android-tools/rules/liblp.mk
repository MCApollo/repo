# liblp
# =========================================================

LIBLP_ARCHIVE := obj/liblp/liblp.a

LIBLP_CXXFLAGS := \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/fs_mgr/liblp/include \
    -I$(srcdir)/core/libsparse/include \
    -I$(srcdir)/extras/ext4_utils/include \
    -I$(srcdir)/include \

LIBLP_SRC_FILES := \
    builder.cpp \
    images.cpp \
    partition_opener.cpp \
    reader.cpp \
    utility.cpp \
    writer.cpp \

LIBLP_OBJ_FILES := \
    $(patsubst %.cpp,obj/liblp/%.o,$(LIBLP_SRC_FILES))

DIRS += $(dir $(LIBLP_OBJ_FILES))

liblp: $(LIBLP_ARCHIVE)

$(LIBLP_ARCHIVE): $(LIBLP_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBLP_OBJ_FILES): obj/liblp/%.o: $(srcdir)/core/fs_mgr/liblp/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBLP_CXXFLAGS) -c -o $@ $^
