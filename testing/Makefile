# Makefile: description file for make in shg/testing directory

include ../make.inc

OBJECTS = testshg.o bdstest.o brent.o date.o drbnwtsn.o except.o hmm.o	\
      laplace.o mathprog.o matrix.o mstat.o mzt.o normmix.o ols.o	\
      permentr.o runs.o smc.o specfunc.o stock.o strdlr.o unicode.o	\
      utils.o vector.o

OBJDIR = ../build/testing
OBJS = $(OBJECTS:%.o=$(OBJDIR)/%.o)

# To generate report, append this with 2>&1 | tee -a report.txt.
$(OBJDIR)/%.o : %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all FORCE check clean spotless

all: ../bin/testshg

../bin/testshg: $(OBJDIR) $(OBJS) FORCE | ../bin
	cd ../src && $(MAKE) static
	$(CXX) $(LDFLAGS) $(OBJS) $(LOADLIBES) $(LDLIBS) -o $@

FORCE:

check: ../bin/testshg
	../bin/testshg

$(OBJDIR) ../bin:
	mkdir -p $@
clean:
	rm -rf $(OBJDIR)
	rm -f testshg.log mtrace
	if ! test "$$(ls -A ../build 2>/dev/null)"; \
	then                                        \
	    rm -rf ../build;                        \
	fi
spotless: clean
	rm -rf ../bin/testshg
	if ! test "$$(ls -A ../bin 2>/dev/null)";   \
	then                                        \
	    rm -rf ../bin;                          \
	fi
-include $(OBJECTS:%.o=$(OBJDIR)/%.d)
