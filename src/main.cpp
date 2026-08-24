#include "Game.h"
#include <iostream>

void display_gui();
int get_selection();
void game_selection();

int main(){
    
   game_selection();
    
    
    
    return  0;
    
}

void display_gui(){
    std::cout << "\n";
    std::cout << "Game options:" << "\n";
    std::cout << "1. Player vs Player" << "\n";
    std::cout << "2. Player vs Computer" << "\n";
    std::cout << "3. Quit" << "\n";
    std:: cout << "Enter game mode: ";
}

int get_selection(){
    int selection{};
    std::cin >> selection;
    return selection;
}

void game_selection(){
    while(true){
        display_gui();
        int selection = get_selection();

        if(selection == 1){
            Game game;
            game.player_vs_player();
        }
        else if(selection == 2){
            Game game;
            game.player_vs_computer();
        }
        else if(selection == 3){
            std::cout << "Are you sure you want to quit?(Y/N)";
            char confirmation{};
            std::cin >> confirmation;
            if(confirmation == 'Y' || confirmation == 'y'){
                std::cout << "Quitting game...";
                break;
            }
            else if(confirmation == 'N' || confirmation == 'n'){
                continue;
            }
        }
        else{
            std::cout << "Please pick a valid game mode.";
        }
    }     
}