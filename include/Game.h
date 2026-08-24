#ifndef _GAME_
#define _GAME_

#include <iostream>
#include "Board.h"

class Game{
private:    
    Board board;

public:
    bool check_win();   
    bool check_draw();
    void player_vs_player();
    void player_vs_computer();
    bool valid_move(int);
    void switch_player(char &);
    int computer_move();
};




















#endif