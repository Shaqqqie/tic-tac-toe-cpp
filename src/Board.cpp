#include "Board.h"
#include <iostream>

void Board::display_board(){
    std::cout << " " << grid[0] << " | " << grid[1] << " | " << grid[2] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << grid[3] << " | " << grid[4] << " | " << grid[5] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << grid[6] << " | " << grid[7] << " | " << grid[8] << "\n";
}