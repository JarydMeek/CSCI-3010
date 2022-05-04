#include "Game.h"
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;


/*
  Function: Converts SquareType Enum to string for printing
  Input: SquareType of a square
  Returns: String of emoji matching squaretype
*/
string SquareTypeStringify(SquareType sq) {
 switch (sq) {
     case SquareType::Wall:
        return "❎";
     case SquareType::Dots:
        return "🟨";
     case SquareType::Pacman:
        return "😁";
     case SquareType::Treasure:
        return "🎁";
     case SquareType::Enemies:
        return "👻";
     case SquareType::Empty:
        return "⬜";
     case SquareType::PowerfulPacman:
        return "😇";
     case SquareType::Trap:
        break;
     case SquareType::EnemySpecialTreasure:
        break;
 }
 return "";
}


/*
  Function: Default Initializer for Board
  Handles creation of board, and generation of treasure on board.
  Input: None
  Returns: None
*/
Board::Board() {
    srand(time(NULL));
    rows_ = 10;
    cols_ = 10;
    SquareType arr2[10][10] = { {SquareType::Pacman, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Dots},
                                {SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Dots, SquareType::Wall, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Dots},
                                {SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Dots, SquareType::Wall, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Dots},
                                {SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Dots, SquareType::Wall, SquareType::Dots},
                                {SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots},
                                {SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots},
                                {SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots},
                                {SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Dots, SquareType::Dots, SquareType::Dots},
                                {SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall},
                                {SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Dots, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall, SquareType::Wall}};
    
    memcpy(arr_, arr2, rows_*cols_*sizeof(SquareType));
    for (int x = 0; x < rows_; x++){ 
        for (int y = 0; y < cols_; y++){ 
            if (arr_[x][y] == SquareType::Dots && (x != 0 && y != 0) && rand() % 10 == 0) {
                arr_[x][y] = SquareType::Treasure;
            }
        }
     }
}

/*
  Function: Getter For squaretype at a specific position
  Input: position to get squaretype of
  Returns: squaretype at position
*/
SquareType Board::get_square_value(Position pos) const {
    return arr_[pos.row][pos.col];
}

/*
  Function: Setter For squaretype at a specific position
  Input: position to set squaretype of, squaretype to set at position
  Returns: nothing
*/
void Board::SetSquareValue(Position pos, SquareType value) {
    arr_[pos.row][pos.col] = value;
}

/*
  Function: Calculates all valid moves for the player passed to the function
  Input: player to calculate valid moves for, output vector to put a string of the valid directions.
  Returns: vector of positions for all valid moves
*/
vector<Position> Board::GetMoves(Player *p, vector<string> *outputArr) {
    Position pos = p->get_position();
    vector<Position> output;
    //Each cardinal direction
    //North
    if (pos.row-1 >= 0 && arr_[pos.row-1][pos.col] != SquareType::Wall) {
        Position North;
        North.row = pos.row-1;
        North.col = pos.col;
        output.push_back(North);
        outputArr->push_back("Up");
    }
    //East
    if (pos.col+1 < get_cols() && arr_[pos.row][pos.col+1] != SquareType::Wall) {
        Position East;
        East.row = pos.row;
        East.col = pos.col+1;
        output.push_back(East);
        outputArr->push_back("Right");
    }
    //West
    if (pos.col-1 >= 0 && arr_[pos.row][pos.col-1] != SquareType::Wall) {
        Position West;
        West.row = pos.row;
        West.col = pos.col-1;
        output.push_back(West);
        outputArr->push_back("Left");
    }
    //South
    if (pos.row+1 < get_rows() && arr_[pos.row+1][pos.col] != SquareType::Wall) {
        Position South;
        South.row = pos.row+1;
        South.col = pos.col;
        output.push_back(South);
        outputArr->push_back("Down");
    }
    return output;
}


/*
  Function: Moves player to given position. handles treasure, board changes and ghost collisions.
  Input: player to move, position to move to, list of enemies to check for collisions
  Returns: true  if player could move without dying, false if player dies.
*/
bool Board::MovePlayer(Player *p, Position pos, std::vector<Player*> *enemylist) {
    if (arr_[pos.row][pos.col] == SquareType::Treasure) {
        p->setHasTreasure(p->hasTreasure()+1);
        p->ChangePoints(p->get_points() + 100);
    } if (arr_[pos.row][pos.col] == SquareType::Dots) {
        p->ChangePoints(p->get_points()+1);
    } 
    arr_[p->get_position().row][p->get_position().col] = SquareType::Empty;
    p->SetPosition(pos);
    
    for (int x = 0; (unsigned)x < enemylist->size(); x++) {
        if ((*enemylist)[x]->get_position() == pos) {
            if (p->hasTreasure() > 0) {
                p->setHasTreasure(p->hasTreasure()-1);
                enemylist->erase(enemylist->begin()+x);
            } else{
                return false;
            }
        }
    }
    if (p->hasTreasure() > 0) {
        arr_[p->get_position().row][p->get_position().col] = SquareType::PowerfulPacman;
    } else {
        arr_[p->get_position().row][p->get_position().col] = SquareType::Pacman;
    }
    return true;
}

/*
  Function: Moves single enemy to given position, checks to see if it would collide with player, updates board.
  Input: enemy to move, position to move enemy to, the current player to see if the player would collide (and if they would, whether or not it should kill them)
  Returns: true if enemy moved and player not killed, false if player killed.
*/
bool Board::MoveEnemy(Player *p, Position pos, Player* actualPlayer) {
    if (p->prevSquareType == SquareType::Enemies) {
        arr_[p->get_position().row][p->get_position().col] = SquareType::Empty;
    } else{
        arr_[p->get_position().row][p->get_position().col] = p->prevSquareType;
    }
    p->SetPosition(pos);
    p->prevSquareType = arr_[p->get_position().row][p->get_position().col];
    arr_[p->get_position().row][p->get_position().col] = SquareType::Enemies;
    if (p->get_position() == actualPlayer->get_position()) {
        return false;
    }
    return true; 
}


/*
  Function: Overload the << operator to print out board.
  Input: board
  Returns: output stream of board.
*/
 std::ostream& operator<<(std::ostream& os, const Board &b){
     for (int x = 0; x < b.get_rows(); x++){ 
        for (int y = 0; y < b.get_cols(); y++){ 
            Position temp;
            temp.col = y;
            temp.row = x;
            os << SquareTypeStringify(b.get_square_value(temp));
        }
        os << "\n";
     }
     return os;
}


//BEGIN GAME FUNCTIONS

/*
  Function: Default initializer for Game. Creates board.
  Input: None
  Returns: None
*/
Game::Game() {
    board_ = new Board();
}

/*
  Function: Creates new game, creates list of enemies and adds the player to the list of players.
  Input: the current player, an output parameter for the enemylist, a number of enemies to create.
  Returns: None
*/
void Game::NewGame(Player *human,std::vector<Player*> *enemylist, const int enemies) {
    for (int x = 0; x < enemies; x++) {
        enemylist->push_back(generateEnemy());
    }
    players_.push_back(human);
}


/*
  Function: Main running function, handles entire game including turns.
  Input: Current player, list of enemies
  Returns: Nothing
*/
void Game::TakeTurn(Player *p,std::vector<Player*> *enemylist) {
    int numGhosts = enemylist->size();
    //Main loop
    while (true) {
        cout << *board_ << endl;
        vector<string> directionArr;
        vector<Position> directions = board_->GetMoves(p, &directionArr);

        //Print tirections
        cout << "Pacman can move: "; 
        for (int x = 0; (unsigned)x < directionArr.size(); x++) {
            if (directionArr[x].length() > 0) {
                cout << directionArr[x] << " ";
            }
        }
        cout << endl;

        //Handle input
        cout << "Please enter a direction to move" << endl;
        string input;
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        bool result = true;

        //find the direction that matches the input and try to move there
        for (int x = 0; (unsigned)x < directionArr.size(); x++) {
            string tempStr = directionArr[x];
            transform(tempStr.begin(), tempStr.end(), tempStr.begin(), ::tolower);
            if (input.length() > 0 && input == tempStr){
                //Attempt to move in that direction
                if (!board_->MovePlayer(p, directions[x], enemylist)) {
                    result = false;
                    break;
                }
                //If we killed a ghost, make a new one.
                if ((unsigned)numGhosts != enemylist->size()) {
                    enemylist->push_back(generateEnemy());
                }
                //Try to move all ghosts.
                for (int x = 0; (unsigned)x < enemylist->size(); x++) {
                    if (!TakeTurnEnemy((*enemylist)[x], p, enemylist)) {
                        result = false;
                        break;
                    }
                }
            }
        }
        //handle game over condition
        if (!result || CheckifdotsOver()) {
            break;
        }
        
    }
    //End of game prints
    cout << *board_ << endl;
    cout << "GAME OVER" << endl;
    cout << GenerateReport(p) << endl;
    
}


/*
  Function: Generates enemy and places them on the board.
  Input: None
  Returns: generated enemy (in player type)
*/
Player* Game::generateEnemy() {
    Position tempPosition;
    //loop to try and find valid location on the board.
        while (true) {
            int x = rand() % 11;
            int y = rand() % 11;
            tempPosition.col = x;
            tempPosition.row = y;
            if (board_->get_square_value(tempPosition) == SquareType::Dots) {
                break;
            }
        }
        Player *tempEnemy = new Player("Enemy",false);
        tempEnemy->SetPosition(tempPosition);
        board_->SetSquareValue(tempPosition, SquareType::Enemies);
        return(tempEnemy);
}


/*
  Function: Generates report for end of game
  Input: player
  Returns: string of report
*/
string Game::GenerateReport(Player *p) {
    return p->get_name() + ": "+ to_string(p->get_points());
}

/*
  Function: Handles the enemies turns including moving and checking if it would kill player.
  Input: enemy, the actual current player, and the list of enemies (to delete enemy when killed)
  Returns: true if enemy moved and game continues, false if player killed.
*/
bool Game::TakeTurnEnemy(Player *p, Player* actualPlayer, vector<Player*> *enemylist) {
    vector<string> directionArr;
    vector<Position> directions = board_->GetMoves(p, &directionArr);
    int randir = rand() % directions.size();
    if (!board_->MoveEnemy(p, directions[randir], actualPlayer)) {
        if (actualPlayer->hasTreasure() > 0) {
                actualPlayer->setHasTreasure(actualPlayer->hasTreasure()-1);
                board_->SetSquareValue(directions[randir], SquareType::Pacman);
                enemylist->erase(remove(enemylist->begin(), enemylist->end(), p), enemylist->end());
                enemylist->push_back(generateEnemy());
            } else {
                return false;
            }
    }
    return true;
}

/*
  Function: Checks to see if all dots on board have been collected
  Input: None
  Returns: true if all dots collected, false if there are still dots on the board.
*/
bool Game::CheckifdotsOver() {
    for (int x = 0; x < board_->get_rows(); x++){ 
        for (int y = 0; y < board_->get_cols(); y++){ 
            Position temp;
            temp.col = y;
            temp.row = x;
            if(board_->get_square_value(temp) == SquareType::Dots) {
                return false;
            }
        }
        
     }
     return true;
}