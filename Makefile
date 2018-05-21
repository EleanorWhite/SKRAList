
node: node.hpp node.cpp
	clang++ --std=c++11 -o node node.cpp 

node.o: node.hpp node.cpp
	clang++ --std=c++11 -c node.cpp

skralist.o: skralist.hpp skralist.cpp node.o
	clang++ --std=c++11 -c skralist.cpp node.o

test: test.cpp skralist.cpp skralist.hpp node.o
	clang++ --std=c++11 -o test test.cpp skralist.cpp node.o 
