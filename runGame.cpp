#include<iostream>
using namespace std;

#include "runGame.h"
#include "Player.h"
#include "Board.h"

Player runGame::getCurrentPlayer(){
  return this.currentPlayer;
}

void runGame::setCurrentPlayer(Player:player){
  return this.currentPlayer = player;
}


void runGame::run(){
  Board board = new Board();
  board.makeBoard(); //盤の状態を作成
  Player player1 = new Player(1);
  Player Player2 = new Player(2);
  int passCount = 0;
  setCurrentPlayer(player1); //先手プレイヤーをplayer1に設定

  //メインループ
  while(){
    if((board.judgePass() == true){
      passCount=0; //パスカウントを初期化
      board.dispBoard(); //盤の状態を表示
      while(currentPlayer.playerInput()==false){ //置けない場所に入力されたら進まない
      }
      board.changeColor();
      board.dispBoard();
      if(currentPlayer.GetPlayerId() = 1){
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
        if(currentPlayer.get_PlayerId() = 1){
         setCurrentPlayer(player2);
        }else{
         setCurrentPlayer(player1);
        }
      }
    }
  }
  printf("お疲れさまでした\n");
}
