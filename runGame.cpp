#include<iostream>
#include "runGame.h"
#include "Player.h"
#include "Board.h"
using namespace std;

Player runGame::getCurrentPlayer(){
  return this->currentPlayer;
}

void runGame::setCurrentPlayer(Player player){
  this->currentPlayer = player;
}


void runGame::run(){
  Board board;
 // board.makeBoard(); //盤の状態を作成
  Player player1(1);
  Player player2(2);
  int passCount = 0;
  setCurrentPlayer(player1); //先手プレイヤーをplayer1に設定

  board.dispBoard(); //盤の状態を表示
  //メインループ
   while(1){
   
    if(board.judgePass(currentPlayer) == true){
      passCount=0; //パスカウントを初期化
      while(currentPlayer.playerInput(board)==false){ //置けない場所に入力されたら進まない
      }
      board.changeBoard(currentPlayer.get_inputX(),currentPlayer.get_inputY(),currentPlayer.get_PlayerID());
      board.changeColor(currentPlayer);
      board.dispBoard();
      if(currentPlayer.get_PlayerID() == 1){
       setCurrentPlayer(player2);
      }else{
       setCurrentPlayer(player1);
      }
    }else{
      passCount++; //パスカウントをインクリメント
      if(passCount>=2){ //パスが2回続いたら石を数えて終了
        board.countStone();
        break;
      }else{ //パスが連続でない時はプレイヤー交代
        if(currentPlayer.get_PlayerID() == 1){
         setCurrentPlayer(player2);
        }else{
         setCurrentPlayer(player1);
        }
      }
    }
  }
  printf("お疲れさまでした\n");
}
