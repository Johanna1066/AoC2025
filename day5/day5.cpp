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

void part2(std::vector<std::string> &rangesInput) {

  // Ordering the ranges in vector of pairs
  std::vector<std::pair<long, long>> ranges;

  for (auto range : rangesInput) {
    std::string temp{};
    long first{}, last{};
    size_t length;
    first = std::stol(range, &length);
    temp = range.substr(length + 1);
    last = std::stol(temp, &length);

    ranges.push_back({first, last});
  }

  // Sorting vector of pairs
  std::sort(ranges.begin(), ranges.end());

  // Vectors that will contain the final ranges. Could be made to one vector of
  // pairs
  std::vector<long> start{}, stop{};

  for (auto range : ranges) {

    // Making sure the range is from low to high. Otherwive it's an unvalid
    // range and skip it
    if ((range.first > range.second)) {
      continue;
    }

    bool added{false};

    for (int i = 0; i < start.size(); i++) {

      // not overlapping with range i at all
      if ((range.second < start[i]) || (range.first > stop[i])) {
        continue;
      }

      // The current range is totally overlapped by range i
      if (range.first >= start[i] && range.second <= stop[i]) {
        added = true;
        break;
      }

      // overlapping with range i on one or both sides
      if (range.second >= stop[i]) {
        stop[i] = range.second;
        if (range.first < start[i]) {
          start[i] = range.first;
        }
      }

      if (range.first <= start[i]) {
        start[i] = range.first;
      }
      added = true;
      i = 0;
    }

    if (!added) {
      start.push_back(range.first);
      stop.push_back(range.second);
    }
  }

  // Adding all the ranges. Adding one to each loop to include the whole range
  // and not only the difference
  long sum{};

  for (int i = 0; i < start.size(); i++) {
    sum += (stop[i] - start[i] + 1);
  }

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