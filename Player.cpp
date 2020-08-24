#include "Player.h"
#include "Board.h"

Player::Player(){
    set_PlayerID(0);
}

Player::Player(int ID){
    set_PlayerID(ID);
}

void Player::set_PlayerID(int ID){
  this.PlayerID = ID;
}

int Player::get_PlayerID(){
  return this.PlayerID;
}

bool Player::playerInput(){
  int length,width;
  printf("縦の入力\n");
  cin >> length;
  printf("横の入力\n");
  cin >> width;
  if(!(0<=length<=7 || 0<=width<=7)){
    printf("0以上7以下の数字で入力してください\n");
    return false;
  }
  changeBoard(length,width,this.get_PlayerID);
  return true;
}
