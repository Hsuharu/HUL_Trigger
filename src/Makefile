BINDIR		= ../bin
CXXFLAGS	+= -Wall -g -MMD
LDFLAGS		+= -lz
CXX = g++
CC  = gcc

SRCALL		= $(wildcard *.cc)
DEPENDS		= $(SRCALL:.cc=.d)

SRC		= $(filter-out %main.cc,$(SRCALL))
OBJ		= $(SRC:.cc=.o)

#all: Register Region1 Region2_1 Region2_2 Region2_3 Region2_4 Region2_5 Region2_6 Region3 Region4 debug set_nimio sel_TOF_seg reconfig_fpga daq
#all: Register Region1 Region2_1 Region2_2 Region2_3 Region2_4 Region2_5 Region2_6 Region3 Region4 debug nimIO sel_TOF_seg reconfig_fpga daq
all: Register debug nimIO sel_TOF_seg reconfig_fpga daq
#all: Region1 Region2_1 Region2_2 Region2_3 Region2_4 Region2_5 Region2_6 Region3 Region4 debug set_nimio sel_TOF_seg reconfig_fpga daq

Register: Register_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

#Region1: Region1_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region2_1: Region2_1_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region2_2: Region2_2_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region2_3: Region2_3_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region2_4: Region2_4_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region2_5: Region2_5_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region2_6: Region2_6_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region3: Region3_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
#Region4: Region4_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)
#
debug: debug_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

#set_nimio: set_nimio_main.o $(OBJ)
#	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

nimIO: nimIO_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

sel_TOF_seg:sel_TOF_seg_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

reconfig_fpga: reconfig_fpga_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

daq: daq_main.o $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(BINDIR)/* *.o *.d *~ *.swp
	find . \( -name ".*.swp" \) -exec $(RM) \{\} \;

-include $(DEPENDS)
