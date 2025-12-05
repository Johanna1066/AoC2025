// day3.cpp
// https://adventofcode.com/2025/day/3

#include "../functions.h"
#include "day3.h"
#include <iostream>
#include <string>


void part1() {}

void part2() {}

void day3() {
  std::string fileURL = "../day3/inputDay3.txt";
  std::ifstream input = readFile(fileURL);

  std::string line;
  int sum1{}, sum2{};

  while (std::getline(input, line)) {
  }
  input.close();

  std::cout << "part 1: " << sum1 << std::endl;
  std::cout << "part 2: " << sum2 << std::endl;
}