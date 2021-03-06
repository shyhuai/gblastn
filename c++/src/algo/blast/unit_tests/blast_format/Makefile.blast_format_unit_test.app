# $Id: Makefile.blast_format_unit_test.app 341721 2011-10-21 18:54:51Z camacho $

APP = blast_format_unit_test
SRC = seqalignfilter_unit_test blastfmtutil_unit_test build_archive_unit_test vecscreen_run_unit_test

CPPFLAGS = $(ORIG_CPPFLAGS) $(BOOST_INCLUDE)
CXXFLAGS = $(FAST_CXXFLAGS)
LDFLAGS = $(FAST_LDFLAGS)

LIB_ = test_boost $(BLAST_FORMATTER_LIBS) ncbi_xloader_blastdb_rmt \
    $(BLAST_LIBS) $(OBJMGR_LIBS)

LIB = $(LIB_:%=%$(STATIC))
LIBS = $(CMPRS_LIBS) $(NETWORK_LIBS) $(DL_LIBS) $(ORIG_LIBS)

CHECK_REQUIRES = in-house-resources
CHECK_CMD = blast_format_unit_test
CHECK_COPY = data

REQUIRES = Boost.Test.Included

CHECK_TIMEOUT = 300

WATCHERS = jianye zaretska maning madden camacho
