CXX=g++
SRC_DIR = src
INC_DIR = include
OBJECTS_DIR = objects
CXXFLAGS = -std=c++17 -g 

all: main

#make a executable out of main.cc in /src
main: $(SRC_DIR)/main.cc 
	$(CXX) $(CXXFLAGS) -o main $(SRC_DIR)/main.cc

run:
	./main 2