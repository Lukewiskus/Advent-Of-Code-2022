//include ship.hpp
#include "../include/ship.hpp"

Ship::Ship(std::string filename) {
    file.open(filename);
    InitCago(filename);
    if (file.is_open()) {
        ParseInput();
    }
}

void Ship::InitCago(std::string filename) {
    int size = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find('1') != std::string::npos) {
            std::reverse(line.begin(), line.end());
            for(int i = 0; i < line.size(); i++) {
                if (line[i] != ' ') {
                    size = std::stoi(line.substr(i, i+1));
                    break;
                }
            }
            break;
        }
    }

    cargo.resize(size);
    for (int i = 0; i < size; i++) {
        cargo[i] = std::stack<std::string>();
    }
    
    file.close();
    file.open(filename);
}

void Ship::ParseInput() {
    std::string line;
    std::string cargoString;
    bool cargoStringDone = false;
    int count = 0;
    while (std::getline(file, line)) {
        if (!cargoStringDone) {
            if(line.find('1') != std::string::npos) {
                cargoStringDone = true;
                cargoString = cargoString.substr(0, cargoString.size() - 1);
                AddCargo(cargoString);
                for (int i = 0; i < cargo.size(); i++) {
                    std::stack<std::string> temp;
                    while (!cargo[i].empty()) {
                        temp.push(cargo[i].top());
                        cargo[i].pop();
                    }
                    cargo[i] = temp;
                }
                continue;
            }
            cargoString += line + "\n";
            
        }
        else {
            count++;
            //print count
            // std::cout << count << std::endl;
            ProccessMove(line);
            
            
        }        
    }
    PrintCargo();
}


void Ship::AddCargo(std::string cargoString) {
    std::stringstream ss(cargoString);
    std::string line;
    int i = 0;

    while (std::getline(ss, line)) {
        std::replace(line.begin(), line.end(), '[', ' ');
        std::replace(line.begin(), line.end(), ']', ' ');
        std::replace(line.begin(), line.end(), ' ', '0');
        for(int j = 0; j < line.size(); j++){
            if(line[j] != '0') {
                int index = ((j - 1) / 4);
                std::string str(1, line[j]);
                cargo[index].push(str);
            }
        }
        i++;
    }
}

void Ship::PrintCargo() {
    for (int i = 0; i < cargo.size(); i++) {
        std::cout << "Cargo " << i << ": ";
        std::stack<std::string> temp = cargo[i];
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }

}

void Ship::ProccessMove(std::string instruction) {
    if(instruction == "") return;
    std::vector<int> instructionVector;
    std::stringstream ss(instruction);
    std::string line;
    int count = 0;
    while (std::getline(ss, line)) {
        int countWhiteSpaces = 0;

        std::string temp = "";
        int num1 = std::stoi(line.substr(5, line.find('f') - 5));
        int num2 = std::stoi(line.substr(line.find('r') + 3, line.find('t') - ((line.find('r') + 4))));
        int num3 = std::stoi(line.substr(line.find('t') + 3, line.size()));



        instructionVector.push_back(num1);
        instructionVector.push_back(num2);
        instructionVector.push_back(num3);
    }
    //print count
    //part 2
    for (int i = 0; i < instructionVector.size(); i += 3) {
        int amount = instructionVector[i];
        int from = instructionVector[i + 1];
        int to = instructionVector[i + 2];
        std::stack<std::string> placeholder;
        
        for (int j = 0; j < amount; j++) {
            std::string tempVal = cargo[from - 1].top();
            
            cargo[from - 1].pop();
            placeholder.push(tempVal);
        }
        for (int j = 0; j < amount; j++) {
           cargo[to - 1].push(placeholder.top());
           placeholder.pop();
        }

        
        
        
    }
    //part 1
    // for (int i = 0; i < instructionVector.size(); i += 3) {
    //     int amount = instructionVector[i];
    //     int from = instructionVector[i + 1];
    //     int to = instructionVector[i + 2];
    //     std::queue<std::string> placeholder;
        
    //     for (int j = 0; j < amount; j++) {
    //         std::string tempVal = cargo[from - 1].top();
            
    //         cargo[from - 1].pop();
    //         placeholder.push(tempVal);
    //     }
    //     for (int j = 0; j < amount; j++) {
    //        cargo[to - 1].push(placeholder.front());
    //        placeholder.pop();
    //     }

    //     placeholder.empty();
        
        
    // }
    return;
}