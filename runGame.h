#ifndef RUNGAME_H_
#define RUNGAME_H_

#include "Player.h"

class runGame{
  private:
     Player currentPlayer; //ターン中のプレイヤー

  public:
    /*currentPlayerのアクセサ*/
    Player getCurrentPlayer();
    void setCurrentPlayer(Player player);


    void run(); //実行

}

#endif /*RUNGAME_H_*/
