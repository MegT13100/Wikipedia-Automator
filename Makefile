EXENAME = graph
OBJS = main.o PNG.o HSLAPixel.o lodepng.o Graph.o BFS.o forceDirected.o PageRank.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp Graph.h BFS.h cs225/PNG.h cs225/HSLAPixel.h forceDirected.h PageRank.h
	$(CXX) $(CXXFLAGS) main.cpp

Graph.o : Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) Graph.cpp

forceDirected.o : forceDirected.cpp forceDirected.h
	$(CXX) $(CXXFLAGS) forceDirected.cpp

PageRank.o : PageRank.cpp PageRank.h
	$(CXX) $(CXXFLAGS) PageRank.cpp

BFS.o : BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

test: output_msg catchmain.o bfs_tests.o forcedirected_tests.o graph_tests.o pagerank_tests.o PNG.o HSLAPixel.o lodepng.o Graph.o BFS.o
	$(LD) catchmain.o PNG.o HSLAPixel.o lodepng.o Graph.o BFS.o forceDirected.o PageRank.o $(LDFLAGS) -o test

catchmain.o : cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

bfs_tests.o : tests/bfs_tests.cpp cs225/catch/catch.hpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) tests/bfs_tests.cpp

forcedirected_tests.o : tests/forcedirected_tests.cpp cs225/catch/catch.hpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) tests/forcedirected_tests.cpp

graph_tests.o : tests/graph_tests.cpp cs225/catch/catch.hpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) tests/graph_tests.cpp

pagerank_tests.o : tests/pagerank_tests.cpp cs225/catch/catch.hpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) tests/pagerank_tests.cpp

clean :
	-rm -f *.o $(EXENAME) test

