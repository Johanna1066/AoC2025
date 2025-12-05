// day3.cpp
// https://adventofcode.com/2025/day/3

#include "day3.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>

void part1(std::vector<std::string> &joltages) {
  int sum{};

  for (auto joltage : joltages) {
    size_t posFirst{};
    std::string remainder{};
    std::string max{};

    for (char i : {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'}) {
      posFirst = joltage.find(i);
      size_t posLast = (joltage.length() - 2);

      if (posFirst == posLast) {
        continue;
      }
      if (posFirst != std::string::npos) {
        max = i;
        // std::cout << "max i 1: " << max << std::endl;
        remainder = joltage.substr(posFirst + 1);
        break;
      }
    }

    // std::cout << "remainder: " << remainder << std::endl;

    for (char i : {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'}) {
      posFirst = remainder.find(i);
      size_t posLast = (joltage.length() - 1);
      if (posFirst == posLast) {
        continue;
      }
      if (posFirst != std::string::npos) {
        max = max + i;
        // std::cout << "max i 2: " << max << std::endl;
        break;
      }
    }
    // std::cout << max << std::endl;
    sum += std::stoi(max);
  }

  std::cout << "Part 1: " << sum << std::endl;
}

void part2() {}

void day3() {
  std::string fileURL = "../day3/inputDay3.txt";
  std::ifstream input = readFile(fileURL);

  std::string line;
  int sum1{}, sum2{};
  std::vector<std::string> joltage{};

  while (std::getline(input, line)) {
    joltage.push_back(line);
  }
  input.close();

  part1(joltage);
}