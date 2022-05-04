CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: main

# note that lines below targets must be
# TABBED in (not spaces!)
clean:
	rm *.o main

main: Point.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Point.o -o main

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c Point.cpp
