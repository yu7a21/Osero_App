#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
  int playerID;

public:
  Player();
  Player(int ID);
  void set_PlayerID(int ID);
  int get_PlayerID();
  bool playerInput(int N_player);
}
