CXX = g++
CXXFLAGS = -std=c++17 -Wall
CXXGDB = -ggdb

all: main

clean:
	rm main *.o

main: main.cpp Store.o User.o Product.o
	$(CXX) $(CXXFLAGS) main.cpp Store.o User.o Product.o -o main

Store.o: Store.cpp Store.hpp
	$(CXX) $(CXXFLAGS) -c Store.cpp -o Store.o
	
User.o: User.cpp User.hpp
	$(CXX) $(CXXFLAGS) -c User.cpp -o User.o

Product.o: Product.cpp Product.hpp
	$(CXX) $(CXXFLAGS) -c Product.cpp -o Product.o
