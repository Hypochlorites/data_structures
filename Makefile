all: main

CXX = g++ -std=c++2a

override CXXFLAGS += -g -Wall -Werror 


SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

main: $(SRCS) $(HEADERS) 
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"  
