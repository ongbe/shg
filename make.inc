# make.inc: file included by description files for make

SHELL = /bin/sh

# Things you might add to DEFS:
# -DMCHECK              To debug memory allocation in GCC.
# -D_GLIBCXX_DEBUG      Use the libstdc++ debug mode.
# -DSHG_IEEE_EXCEPTIONS	Enable traps for IEEE exceptions.

DEFS = -DMCHECK -D_GLIBCXX_DEBUG -DSHG_IEEE_EXCEPTIONS

CXX = g++ -O2
DEBUG = -g
INCLUDE = -I../include
WARNINGS = -pedantic -Wall -Wextra -Weffc++ -Wold-style-cast
CXXFLAGS = -MMD $(DEBUG) $(INCLUDE) -std=c++11 $(WARNINGS) $(DEFS)
CPPFLAGS =
LDFLAGS = -static
LOADLIBES = -L../lib
LDLIBS = -lshg

AR = /usr/bin/ar
ARFLAGS = rc
RANLIB = /usr/bin/ranlib

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

% : %.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LOADLIBES) $(LDLIBS) -o $@
