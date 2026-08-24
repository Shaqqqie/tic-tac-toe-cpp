#include "Game.h"
#include <iostream>
#include <array>

bool Game::check_win(){
    std::array<std::array<int, 3>, 8> win_condition {{
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {6, 4, 2}
    }};

    for(int i{}; i < 8; ++i){
        int a = win_condition[i][0];
        int b = win_condition[i][1];
        int c = win_condition[i][2];

        if(board.get_cell(a) == board.get_cell(b) && board.get_cell(b) == board.get_cell(c)){
            return true;
        }  
    }
    return false;
}

bool Game::valid_move(int current_player_move){
    if(current_player_move < 1 || current_player_move > 9){
        std::cout << "Pick a number between 1 and 9.";
        return false;
    }
    else if(board.get_cell(current_player_move) == 'X' || board.get_cell(current_player_move) == 'O'){
        std::cout << "Pick a non-occupied number on the grid.";
        return false;
    }
    else{
        return true;
    }
}

void Game::switch_player(char &player){
    player = (player == 'X') ? 'O' : 'X';
}

void Game::play_game(){
    char current_player = 'X';
    while(true){
        board.display_board();
        

        int current_player_move{};
        std::cout << "Player " << current_player << ", pick a number on the board(1-9): ";
        std::cin >> current_player_move;

        if(valid_move(current_player_move) == true){
            board.make_move(current_player, current_player_move);   
        }
        else{
            continue;
        }

        if(check_win() == true){
            std::cout << "We have a winner!!!";
            break;
        }
        else{
            switch_player(current_player);
        }
    }
}