#include <iostream> 
#include "../include/ship.hpp"

int main() {
    //print hello world
    Ship *ship = new Ship("./input.txt");
    delete ship;
}
