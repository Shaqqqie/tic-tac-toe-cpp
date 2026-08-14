#include <iostream>

void display_board(char board[]);
bool check_win(char board[]);

int main(){
    char board[9] {'1','2','3','4','5','6','7','8','9'};
    char current_player = 'X';

    //initial board display
    while(true){
        display_board(board);

        int current_player_move{};
        std::cout << "Player 1, enter your choice: ";
        std::cin >> current_player_move;
        //update board
        board[current_player_move - 1] = current_player;
        display_board(board);
        if(check_win(board) == true){
            std::cout << "We have a winner!!!";
            break;
        }
    }
    
    // switch to player 
}

void display_board(char board[]){
    std::cout << "\n";
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool check_win(char board[]){
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

        if(board[a] == board[b] && board[b] == board[c]){
            return true;
        }
    }
    return false;
}