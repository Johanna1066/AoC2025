// day4.cpp
// https://adventofcode.com/2025/day/4

#include "day4.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>

void part1(std::vector<std::vector<char>> &grid) {
  int sum{};

  // coordinates
  int x{0}, y{0};
  int xCords[8] = {-1, 0, 1, -1, 1, -1, 0, 1},
      yCords[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

  for (auto row : grid) {
    // std::cout << "__________\n";

    // for (auto nodes : row) {
    //   std::cout << nodes;
    // }

    for (auto node : row) {

      int count{0};
      if (node != '@') {
        x++;
        continue;
      } else {
        for (int i : {0, 1, 2, 3, 4, 5, 6, 7}) {
          if (grid[(yCords[i] + y)][(xCords[i] + x)] != '.') {
            /* std::cout << "träff på x = " << x << " y = " << y
                      << "   värdet är:  "
                      << grid[(yCords[i] + y)][(xCords[i] + x)] << '\n';
            // std::cout << "hit" << '\n';*/
            count++;
          }
        }
      }
      if (count < 4) {
        sum++;
      }

      x++;
    }
    y++;
    x = 0;
  }

  std::cout << "part 1: " << sum << std::endl;
}

void part2(std::vector<std::vector<char>> &grid) {
  int sum{};

  // coordinates
  int x{0}, y{0};
  int xCords[8] = {-1, 0, 1, -1, 1, -1, 0, 1},
      yCords[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int removed{1};

  // Keeps going until there are no more elements to be removed
  while (removed > 0) {

    // Resets removed elements and y-coordinates for antoher loop
    removed = 0;
    y = 0;

    for (auto row : grid) {

      for (auto node : row) {

        int count{0};
        if (node != '@') {
          x++;
          continue;
        } else {
          for (int i : {0, 1, 2, 3, 4, 5, 6, 7}) {
            if (grid[(yCords[i] + y)][(xCords[i] + x)] != '.') {
              count++;
            }
          }
        }
        if (count < 4) {
          grid[y][x] = '.';
          removed++;
          sum++;
        }
        x++;
      }
      y++;
      x = 0;
    }
  }

  std::cout << "part 2: " << sum << std::endl;
}

void day4() {
  std::string fileURL = "../day4/inputDay4.txt";
  std::ifstream input = readFile(fileURL);

  std::string line;

  std::vector<std::vector<char>> grid;
  std::vector<char> row{};

  bool first{true};
  int length{};

  while (std::getline(input, line)) {

    // adding one more row of only '.' before all the indata
    if (first) {
      length = line.size();
      for (int i = 0; i <= length; i++) {
        row.push_back('.');
      }
      grid.push_back(row);
      row.clear();
      first = false;
    }

    row.push_back('.');
    for (char node : line) {
      if (node == '\r') {
        continue;
      }
      row.push_back(node);
    }
    row.push_back('.');

    grid.push_back(row);
    row.clear();
  }

  // adding one more row of only '.' after all the indata
  for (int i = 0; i <= length; i++) {
    row.push_back('.');
  }
  grid.push_back(row);

  /*for (auto rows : grid) {
    for (auto nodes : rows) {
      std::cout << nodes;
    }
    std::cout << '\n';
  }*/
  part1(grid);
  part2(grid);
  input.close();
}