#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

int main(int argc, char** argv) {
    std::string input = argv[1];

    std::ifstream file;
    file.open("assets/input.txt", std::ifstream::out);

    if (!file.is_open()){
        //print failed to open
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    std::string line;
    int currentElf = 0;
    int maxElf = 0;
    int maxCalories = 0;
    int currentCalories = 0;

    std::vector<int> topThreeCalories;
 
    while (std::getline(file, line)) {
        if(input.compare("1") == 0){
            std::cout << line << std::endl;
            if(line.compare("") == 0){
                maxCalories = currentCalories;
                currentElf++;
                currentCalories = 0;
            }
            else {
                currentCalories += std::stoi(line);
            }   
        }
        if(input.compare("2") == 0){
            if(line.compare("") == 0){
                bool flag = false;
                int temp = 0;
                topThreeCalories.push_back(currentCalories);
                currentElf += 1;
                currentCalories = 0;
            } else {
                currentCalories += std::stoi(line);
            }
        }
    }
   
    if(input.compare("1") == 0){
         std::cout << "Elf " << maxElf << " ate the most with " << maxCalories << " calories" << std::endl;
    }
    if(input.compare("2") == 0){
        std::sort(topThreeCalories.begin(), topThreeCalories.end(), std::greater<int>());
        //sum the last three in the top three calories vector
        int sum = 0;
        for(int i = 0; i < 3; i++){
            std::cout << topThreeCalories[i] << std::endl;
            sum += topThreeCalories[i];
        }
        
       std::cout << "The sum of the top three calories is: " << sum << std::endl;
    }

    file.close();


}

