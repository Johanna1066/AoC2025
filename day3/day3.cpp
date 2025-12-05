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
    size_t posFound{};
    std::string remainder{};
    std::string max{};

    for (char i : {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'}) {
      posFound = joltage.find(i);
      size_t posLast = (joltage.length() - 2);

      if (posFound == posLast) {
        continue;
      }
      if (posFound != std::string::npos) {
        max = i;
        remainder = joltage.substr(posFound + 1);
        break;
      }
    }

    for (char i : {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'}) {
      posFound = remainder.find(i);
      size_t posLast = (joltage.length() - 1);
      if (posFound == posLast) {
        continue;
      }
      if (posFound != std::string::npos) {
        max = max + i;
        break;
      }
    }
    sum += std::stoi(max);
  }

  std::cout << "Part 1: " << sum << std::endl;
}

// Part two is basically just a recursive version of part 1
// part 1 could be solved with this function aswell. I would add one more
// in-argument to decide how many digits to looks for and create the array
// automatically from that argumen tinstead of manually as I've done in this
// version

void part2(std::vector<std::string> &joltages) {
  long sum{};

  for (auto joltage : joltages) {
    size_t posFound{};
    std::string remainder{};
    remainder = joltage;
    std::string max{};

    // The request was to find the 'best' 12 digits to create the largest
    // number.
    for (int j : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}) {

      // Checking through the whole line to see if there are any 9's, if not
      // check for 8's and so on.
      for (char i : {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'}) {
        posFound = remainder.find(i);

        // Making sure that the found digit isn't too close to the end.
        size_t posLast = (remainder.length() - (14 - j));
        if (posFound > posLast) {
          continue;
        }

        // Adding the found digit to the number 'max'
        if (posFound != std::string::npos) {
          max = max + i;
          remainder = remainder.substr(posFound + 1);
          break;
        }
      }
    }
    sum += std::stol(max);
  }

  std::cout << "Part 2: " << sum << std::endl;
}

void day3() {
  std::string fileURL = "../day3/inputDay3.txt";
  std::ifstream input = readFile(fileURL);

  std::string line;
  int sum1{}, sum2{};
  std::vector<std::string> joltages{};

  while (std::getline(input, line)) {
    joltages.push_back(line);
  }
  input.close();

  part1(joltages);
  part2(joltages);
}