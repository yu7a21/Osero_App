#include "Player.h"
#include "Board.h"

Player::Player(){
    set_PlayerID(0);
}

Player::Player(int ID){
    set_PlayerID(ID);
}

void Player::set_PlayerID(int ID){
  PlayerID = ID;
}

int Player::get_PlayerID(){
  return PlayerID;
}

bool Player::playerInput(int N_player){
  int length,width;
  printf("縦の入力\n");
  cin >> length;
  printf("横の入力\n");
  cin >> width;
  changeBoard(length,width);
  return true;
}
