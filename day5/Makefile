CXX=g++
SRC_DIR = src
INC_DIR = include
OBJECTS_DIR = objects
CXXFLAGS = -std=c++20 -g 

all: before ship main after


before:
	mkdir -p $(OBJECTS_DIR)
after:
	rm -rf $(OBJECTS_DIR)
#make a executable out of main.cc that includes ship
main: $(SRC_DIR)/main.cpp $(OBJECTS_DIR)/ship.o
	$(CXX) $(CXXFLAGS) -o main $(SRC_DIR)/main.cpp $(OBJECTS_DIR)/ship.o

#make a trget to compile ship
ship: $(SRC_DIR)/ship.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/ship.cpp -o $(OBJECTS_DIR)/ship.o

run:
	./main

clean:
	rm -f main