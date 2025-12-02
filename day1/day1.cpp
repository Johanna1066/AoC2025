// day1.cpp
// https://adventofcode.com/2025/day/1

#include "day1.h"
#include "../functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void part1() {
}

void part2() {
}

void day1()
{
    std::string fileURL = "../day1/testInputDay1.txt";
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

    part1();

}