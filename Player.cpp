#include "Player.h"
#include "Board.h"
#include<iostream>
#include<cstdio>

Player::Player(){
    set_PlayerID(0);
}

Player::Player(int ID){
    set_PlayerID(ID);
}

void Player::set_PlayerID(int ID){
  this->playerID = ID;
}

int Player::get_PlayerID(){
  return this->playerID;
}

bool Player::playerInput(){
  Board board;
  int length,width;
  printf("縦の入力\n");
  cin >> length;
  printf("横の入力\n");
  cin >> width;
  if(!(0<=length<=7 || 0<=width<=7)){
    printf("0以上7以下の数字で入力してください\n");
    return false;
  }
  board.changeBoard(length,width,this->get_PlayerID());
  return true;
}
