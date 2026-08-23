#ifndef _BOARD_
#define _BOARD_

#include <array>

class Board{
private:
    std::array<char, 9> grid {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


public:
    void display_board();
    
};




#endif
