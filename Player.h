#ifndef PLAYER_H_
#define PLAYER_H_
class Board;
class Player
{
private:
  int playerID;
  int inputX;
  int inputY;
public:
  Player();
  Player(int ID);
  void set_PlayerID(int ID);
  int get_PlayerID();
  int get_inputX();
  int get_inputY();
  bool playerInput(Board board);
};

#endif /*PLAYER_H_*/
