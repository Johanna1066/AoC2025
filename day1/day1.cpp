// day1.cpp
// https://adventofcode.com/2025/day/1

#include "day1.h"
#include "../functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void part1(std::vector<int>& instructions) {
    
    //Starting postition is 50
    int position{50};

    //Counting how many times the dial is left pointing at zero
    int sumZeroes{0};

    for (auto move : instructions){
        position = (position + move) % 100;
        if(position == 0) sumZeroes++;
    }

    std::cout << "Result part 1: " << sumZeroes << std::endl;

}

void part2() {
}

void day1()
{
    std::string fileURL = "../day1/inputDay1.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    std::vector<int> instructions;

    while (std::getline(input, line)){
        std::stringstream ss(line);
        std::string token{};

        while (ss >> token) {
            if (token.empty()) continue;

            char turn = token[0];
            std::size_t length = token.size();
            int dist{};
        
            dist = std::stoi(token.substr(1,length));

            if (turn == 'L') dist = -dist;

            instructions.push_back(dist);
        }
    }
    input.close();

    part1(instructions);

}