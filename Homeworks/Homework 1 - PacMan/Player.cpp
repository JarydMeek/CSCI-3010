#include "Player.h"

using namespace std;


/*
  Function: Default initializer for player
  Input: Name for player, boolean to determine if the player is human or not.
  Returns: None
*/
Player::Player(const std::string name, const bool is_human) {
    name_ = name;
    is_human_ = is_human;
    Position temp;
    temp.row = 0;
    temp.col = 0;
    pos_ = temp;
    points_ = 0;
}

/*
  Function: setter for points of current player
  Input: int for number of points to set for current player.
  Returns: none
*/
void Player::ChangePoints(const int x) {
    points_ = x;
}

/*
  Function: Setter for player's current position
  Input: new position for player
  Returns: none
*/
void Player::SetPosition(Position pos) {
    pos_ = pos;
}

/*
  Function: Setter for player's treasure count
  Input: new treasure amount for player
  Returns: none
*/
void Player::setHasTreasure(int treasure) {
    has_Treasure_ = treasure;
}

/*
  Function: Setter for player's dead state
  Input: new state for player
  Returns: none
*/
void Player::setIsDead(bool isdead) {
    isDead_ = isdead;
}

/*
  Function: Converts players name and points to string for printing
  Input: none
  Returns: string of name and points
*/
string Player::Stringify() {
    return name_ + ": " + to_string(points_);
}