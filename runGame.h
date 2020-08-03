#ifndef RUNGAME_H_
#define RUNGAME_H_

#include "Player.h"

class runGame{
  private:
     Player currentPlayer; //ターン中のプレイヤー

  public:
    Player();
    virtual ~Player()
    void run(); //実行
    Player getCurrentPlayer();
    void setCurrentPlayer(Player player);
}

#endif /*RUNGAME_H_*/
