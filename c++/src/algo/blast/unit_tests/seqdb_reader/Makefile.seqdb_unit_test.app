# $Id: Makefile.seqdb_unit_test.app 311249 2011-07-11 14:12:16Z camacho $

APP = seqdb_unit_test
SRC = seqdb_unit_test

CPPFLAGS = $(ORIG_CPPFLAGS) $(BOOST_INCLUDE)
CXXFLAGS = $(FAST_CXXFLAGS)
LDFLAGS  = $(FAST_LDFLAGS)

LIB = test_boost seqdb xobjutil blastdb $(SOBJMGR_LIBS)
LIBS = $(DL_LIBS) $(ORIG_LIBS)

CHECK_REQUIRES = in-house-resources
CHECK_CMD  = seqdb_unit_test
CHECK_COPY = seqdb_unit_test.ini data

REQUIRES = Boost.Test.Included

CHECK_TIMEOUT = 600

WATCHERS = maning madden camacho
