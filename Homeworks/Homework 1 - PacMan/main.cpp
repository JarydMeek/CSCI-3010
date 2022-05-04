/**
Jaryd Meek
HW 1
This program creates and runs a command line pacman game.
*/


#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    //I CHOSE TO IMPLEMENT RANDOMLY RESPAWNING GHOSTS FOR PT 2


    //Handles player name
    cout << "Please enter a name" << endl;
    string input;
    getline(cin, input);

    //create player, storage for enemies and game
    Player currentPlayer(input, false);
    vector<Player*> enemies;
    Game mainGame;

    //start game
    mainGame.NewGame(&currentPlayer, &enemies, 2);
    mainGame.TakeTurn(&currentPlayer, &enemies);
}