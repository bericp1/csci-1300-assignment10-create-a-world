#include <cstdlib>
#include <iostream>

#include "world_map.h"

int main() {
    std::cout << std::endl << "World Name: ";
    // Get the world name from stdin
    std::string result; std::getline(std::cin, result);
    std::cout << std::endl << "Number of Rows: ";
    // Get the number of rows from stdin
    std::size_t rows = 0; std::cin >> rows;
    std::cout << std::endl << "Number of Cols: ";
    // Get the number of columns from stdin
    std::size_t cols = 0; std::cin >> cols;
    // Generate the world as a temporary and print its serialization to stdout
    std::cout << std::endl << WorldMap(result, rows, cols).serialize() << std::endl;
    return 0;
}