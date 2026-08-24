#include "Game.h"
#include <iostream>
#include <limits>

void display_menu();
int get_selection();
void game_selection();

int main(){
    
    game_selection();
    
    return  0;
}

void display_menu(){
    std::cout << "\n";
    std::cout << "Game options:" << "\n";
    std::cout << "1. PvP" << "\n";
    std::cout << "2. PvComputer" << "\n";
    std::cout << "3. Quit" << "\n";
    std:: cout << "Enter game mode: ";
}

int get_selection(){
    int selection{};
    do{
        
        std::cin >> selection;
        if(std::cin.fail()){
            std::cout << "That's not a number: ";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),'\n'
            );
        }
        else if(selection < 1 || selection > 3){
            std::cout << "Please pick a valid game mode: ";
        }
    }while(selection < 1 || selection > 3);
    return selection;
}

void game_selection(){
    while(true){
        display_menu();
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