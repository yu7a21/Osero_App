#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
private:
  int playerID;

public:
  Player();
  Player(int ID);
  void set_PlayerID(int ID);
  int get_PlayerID();
  bool playerInput();
};

#endif /*PLAYER_H_*/
