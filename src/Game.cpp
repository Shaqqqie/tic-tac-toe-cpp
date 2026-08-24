#include "Game.h"
#include <iostream>
#include <array>
#include <vector>
#include <random>

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
    else if(board.get_cell(current_player_move - 1) == 'X' || board.get_cell(current_player_move - 1) == 'O'){
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

bool Game::check_draw(){
        int win_condition[8][3]{
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {6,4,2},
        {0,4,8}
    };

    for(int row{0}; row < 8; ++row){
        int a = win_condition[row][0];
        int b = win_condition[row][1];
        int c = win_condition[row][2];

        bool x_can_win = board.get_cell(a) != 'O' && board.get_cell(b) != 'O' && board.get_cell(c) != 'O';
        bool o_can_win = board.get_cell(a) != 'X' && board.get_cell(b) != 'X' && board.get_cell(c) != 'X';

        if(x_can_win || o_can_win){
            return false;
        }
    }
    return true;
}

void Game::play_game(){
    char current_player = 'X';
    board.display_board();
    while(true){
        
        int current_player_move{};
        
        if(current_player == 'X'){
            std::cout << "Player " << current_player << ", pick a number on the board(1-9): ";
            std::cin >> current_player_move;
        }
        else if(current_player == 'O'){
            current_player_move = computer_move();
        }

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
        else if(check_draw() == true){
            std::cout << "It's a draw!";
            break;
        }
        else{
            switch_player(current_player);
        }
    }
}



int Game::computer_move(){
    std::vector<int> available_moves{};
    int random_move{};

    for(size_t i{0}; i < 9; ++i){
        if(board.get_cell(i) != 'X' && board.get_cell(i) != 'O'){
            available_moves.push_back(i);
        }
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<std::size_t> distribution(0, available_moves.size() - 1
    );

    std::size_t random_index = distribution(generator);

    if(!available_moves.empty()){
        int random_move = available_moves[distribution(generator)]; 
        return random_move;
    }
    else{
        return 1;
    }
    
}