// day1.cpp
// https://adventofcode.com/2025/day/1

#include "day1.h"
#include "../functions.h"
#include <iostream>
#include <string>

void part1() {
}

void part2() {
}

void dayX()
{
    std::string fileURL = "../dayX/inputDay1.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    while (std::getline(input, line)){
        
    }
    input.close();

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}