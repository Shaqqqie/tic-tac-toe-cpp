#ifndef _GAME_
#define _GAME_

class Game{
    public:
    void display_board(char []);
    bool valid_move(char [], int);
    bool check_win(char []);
    bool check_draw(char []);
    void switch_player(char &);
    void play_game();
};

#endif