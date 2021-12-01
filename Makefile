EXENAME = main
OBJS = main.o 

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp Graph.cpp ConstructGraph.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)

# Use the cs225 makefile template:
include cs225/make/cs225.mk

#EXENAME = intro
#OBJS = PNG.o HSLAPixel.o lodepng.o Graph.o ConstructGraph.o main.o

#CXX = clang++
#CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
#LD = clang++
#LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
#ccred=$(shell echo -e "\033[0;31m")
#ccyellow=$(shell echo -e "\033[0;33m")
#ccend=$(shell echo -e "\033[0m")

#IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
#IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
#ifneq ($(strip $(IS_EWS)),)
#ifeq ($(strip $(IS_CORRECT_CLANG)),)
#CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
#endif
#else
#ifneq ($(strip $(SKIP_EWS_CHECK)),True)
#CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
#endif
#endif

#.PHONY: all test clean output_msg

#all : $(EXENAME)

#output_msg: ; $(CLANG_VERSION_MSG)

#$(EXENAME): output_msg $(OBJS)
#	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

#Graph.o: main.cpp Graph.cpp cs225/PNG.h cs225/HSLAPixel.h
#	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp

#ConstructGraph.o: main.cpp ConstructGraph.cpp cs225/PNG.h cs225/HSLAPixel.h
#	$(CXX) $(CXXFLAGS) main.cpp ConstructGraph.cpp

#PNG.o: cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
#	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

#HSLAPixel.o: cs225/HSLAPixel.cpp cs225/HSLAPixel.h
#	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

#lodepng.o: cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
#	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

#test: output_msg tests.o PNG.o HSLAPixel.o lodepng.o Graph.o ConstructGraph.o
#	$(LD) tests.o PNG.o HSLAPixel.o lodepng.o Graph.o ConstructGraph.o $(LDFLAGS) -o test

#tests.o: tests/tests.cpp tests/catch.hpp cs225/PNG.h cs225/HSLAPixel.h
#	$(CXX) $(CXXFLAGS) tests/tests.cpp


#clean:
#	-rm -f *.o $(EXENAME) test
