#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stack>
#include <queue>
class Ship {

public:
    Ship(std::string filename);
    ~Ship() {};

    void ParseInput();
    void InitCago(std::string filename);
    void ProccessMove(std::string instruction);
    void AddCargo(std::string cargo);
    void PrintCargo();

private:
    std::ifstream file;
    std::vector<std::stack<std::string>> cargo;
    
};