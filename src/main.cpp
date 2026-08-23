#include "Board.h"
#include <iostream>


int main(){
    
    Board board;

    int number{};
    board.display_board();
    std::cout << "Pick a number: ";
    std::cin >> number;

    board.make_move(number);
    board.display_board();
    return  0;
    
}




