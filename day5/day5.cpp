// day5.cpp
// https://adventofcode.com/2025/day/5

#include "day5.h"
#include "../functions.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void part1(std::vector<std::string> &ranges, std::vector<long> &productIDs) {
  int sum{};

  for (auto ID : productIDs) {
    for (auto range : ranges) {
      std::string temp{};
      long first{}, last{};
      size_t length;
      first = std::stol(range, &length);
      temp = range.substr(length + 1);
      last = std::stol(temp, &length);

      if (first > last) {
        long temp = last;
        last = first;
        first = temp;
      }

      if (first <= ID && ID <= last) {
        sum++;
        break;
      }
    }
  }

  std::cout << "part 1: " << sum << std::endl;
}

void part2(std::vector<std::string> &ranges) {
  int sum{};
  std::cout << "part 2: " << sum << std::endl;
}

void day5() {
  std::string fileURL = "../day5/inputDay5.txt";
  std::ifstream input = readFile(fileURL);

  std::string line{};
  bool rangesDone{false};

  std::vector<long> productIDs{};
  std::vector<std::string> ranges{};

  while (std::getline(input, line)) {
    if (line == "\r") {
      rangesDone = true;
      continue;
    }

    if (rangesDone) {
      // Saving all product IDs
      long ID = std::stol(line);
      productIDs.push_back(ID);

    } else {
      // Saving all ranges
      ranges.push_back(line);
    }
  }

  part1(ranges, productIDs);
  part2(ranges);

  input.close();
}