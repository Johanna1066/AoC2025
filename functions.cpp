// functions.cpp
#include "functions.h"
#include <iostream>

std::ifstream readFile(const std::string& fileURL) {
    std::ifstream input(fileURL);

    if (!input) {
        std::cerr << "Failed to open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    return input;
}