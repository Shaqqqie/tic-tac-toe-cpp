#include <iostream>

void display_board(char board[]);

int main(){
    char board[9] {'1','2','3','4','5','6','7','8','9'};
    char player1 = 'X'; 

    //initial board display
    display_board(board);
}

void display_board(char board[]){
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}
