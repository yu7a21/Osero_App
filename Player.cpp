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

int Player::get_inputX(){
  return this->inputX;
}

int Player::get_inputY(){
  return this->inputY;
}

bool Player::playerInput(Board board){
  int length,width;

  if(playerID==1){
    cout<<endl;
    cout<<"Player1(Black):"<<endl;
  }else{
    cout<<endl;
    cout<<"Player2(white):"<<endl;
  }

  printf("縦の入力->");
  cin >> length;
  printf("横の入力->");
  cin >> width;

  if((length<0)||(length>7)||(width<0)||(width>7)){
    printf("0以上7以下の数字で入力してください\n");
    return false;
  }

  if(board.judgeInputCin(width,length,playerID) == false){
    cout<<"その場所には置けません"<<endl;
    return false;
  }

  inputX=width;
  inputY=length;

  cout<<endl;
  
  return true;
}
