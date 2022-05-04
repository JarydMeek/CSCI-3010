CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: test

clean:
	-rm main test

main: main.cpp Linear.hpp Tree.hpp HashMap.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test: test.cpp Linear.hpp Tree.hpp HashMap.hpp
	$(CXX) $(CXXFLAGS) test.cpp -o test

