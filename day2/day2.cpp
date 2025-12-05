// day2.cpp
// https://adventofcode.com/2025/day/2

#include "day2.h"
#include "../functions.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int countOccurrences(const std::string &s, const std::string &word) {

  if (word.empty())
    return 0;

  int count = 0;
  std::size_t pos = 0;

  // Count possibly overlapping occurrences of word inside s.
  while (true) {

    pos = s.find(word, pos);

    if (pos == std::string::npos)
      break;
    ++count;
    ++pos; // add one to allow overlapping matches
  }

  return count;
}

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

void part2(std::vector<std::string> &ranges) {
  long sum{};

  for (auto range : ranges) {

    std::string firstStr = range.substr(0, range.find('-'));
    std::string lastStr = range.substr(range.find('-') + 1);

    long current{std::stol(firstStr)}, last{std::stol(lastStr)};

    do {
      std::string currentStr = std::to_string(current);

      // iterate all substrings (only keep unique substrings in `subStrings`)
      for (int i = 1; i <= (currentStr.size() / 2); i++) {

        std::string subStr = currentStr.substr(0, i);

        if (countOccurrences(currentStr, subStr) > 1) {

          // Checking if the substring multiplied so that
          // it has the same length as the current string
          // is the same as current string.
          int j{0}, n{0};
          n = (currentStr.size() / i);
          std::string comp{};

          while (j < n) {
            comp = comp + subStr;
            j++;
          }

          if (comp == currentStr) {
            current = std::stol(currentStr);
            sum += current;
            break;
          }
        }
      }

      current++;
    } while (current != (last + 1));
  }
  std::cout << "part 2: " << sum << std::endl;
}

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

    part1(ranges);
    part2(ranges);
  }
  input.close();
}