#include <iostream>

void display_board(char []);
bool valid_move(char [], int);
bool check_win(char []);
bool check_draw(char[]);
void play_game();
void switch_player(char &);


int main(){
    play_game();
}
    
void display_board(char board[]){
    std::cout << "\n";
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---+---+---" << "\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool valid_move(char board[], int current_player_move){
    if(current_player_move < 1 || current_player_move > 9){
        std::cout << "Invalid move, number must be between 1 and 9";
        return false;
    }
    else if(board[current_player_move - 1] == 'X' || board[current_player_move - 1] == 'O'){
        std::cout << "Invalid move, please choose one of the remaining numbers";
        return false;
    }
    else{
        return true;
    }
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

bool check_draw(char board[]){
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

        bool x_can_win = board[a] != 'O' && board[b] != 'O' && board[c] != 'O';
        bool o_can_win = board[a] != 'X' && board[b] != 'X' && board[c] != 'X';

        if(x_can_win || o_can_win){
            return false;
        }
    }
    return true;
}

void play_game(){
    char board[9] {'1','2','3','4','5','6','7','8','9'};
    char current_player = 'X';

    while(true){
        
        display_board(board);

        int current_player_move{};
        std::cout << "Player " << current_player << ", enter your choice(1-9): ";
        std::cin >> current_player_move;
        
        if(valid_move(board, current_player_move) == true){
            board[current_player_move - 1] = current_player;
        }
        else{
            continue;
        }
        
        if(check_win(board) == true){
            std::cout << "We have a winner!!!";
            break;
        }
        else if(check_draw(board) == true){
            std::cout << "It's a draw!";
            break;
        }
        else{
            switch_player(current_player);
        }
    }
}

void switch_player(char &player){
    if(player == 'X'){
        player = 'O';
    }
    else if(player == 'O'){
        player = 'X';
    }
}