// day2.cpp
// https://adventofcode.com/2025/day/2

#include "day2.h"
#include "../functions.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void part1(std::vector<std::string> &ranges) {
  long sum{};

  for (auto range : ranges) {

    std::string firstStr = range.substr(0, range.find('-'));
    std::string lastStr = range.substr(range.find('-') + 1);

    long current{std::stol(firstStr)}, last{std::stol(lastStr)};

    do {
      long digits = (current == 0) ? 1 : (long)log10(current) + 1;

      if (digits % 2 == 0) {

        std::string currentStr = std::to_string(current);

        std::string firstHalf = currentStr.substr(0, (digits / 2));
        std::string secondHalf = currentStr.substr((digits / 2));

        if (firstHalf == secondHalf) {
          sum += current;
        }
      }

      current++;

    } while (current != (last + 1));
  }
  std::cout << "part 1: " << sum << std::endl;
}

void part2() { std::cout << "part 2: " << std::endl; }

void day2() {
  std::string fileURL = "../day2/inputDay2.txt";
  std::ifstream input = readFile(fileURL);

  std::string line;
  std::vector<std::string> ranges;

  while (std::getline(input, line)) {

    do {
      size_t length = line.find_first_of(',');
      std::string range{};

      if (length == std::string::npos) {
        // take the rest of the string
        range = line;
        line.clear();
      } else {
        range = line.substr(0, length);
        line = line.substr(length + 1);
      }

      ranges.push_back(range);

    } while (!line.empty());

    /*while (!line.empty()) {

      rangePair current;
      std::string row{};

      size_t length;
      current.start = std::stoi(line, &length);
      line = line.substr(length + 1);
      current.finish = std::stoi(line, &length);
      line = line.substr(length + 1);

      std::cout << "start: " << current.start << "  finish: " <<
    current.finish
                << std::endl;

      ranges.push_back(current);
    }*/

    part1(ranges);
  }
  input.close();
}