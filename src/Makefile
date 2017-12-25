BINDIR		= ../bin
CXXFLAGS	+= -Wall -g -MMD
LDFLAGS		+= -lz
CXX = g++
CC  = gcc

SRCALL		= $(wildcard *.cc)
DEPENDS		= $(SRCALL:.cc=.d)

SRC		= $(filter-out %main.cc,$(SRCALL))
OBJ		= $(SRC:.cc=.o)

all: Register debug set_nimio sel_TOF_seg reconfig_fpga daq

Register: Register_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

debug: debug_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

set_nimio: set_nimio_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

sel_TOF_seg:sel_TOF_seg_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

reconfig_fpga: reconfig_fpga_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

daq: daq_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(BINDIR)/* *.o *.d *~

-include $(DEPENDS)
