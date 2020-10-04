#ifndef BOARD_H
#define BOARD_H

using namespace std;
class Player;
class Board
{
private:
    /*Null:0 white:2 black:1*/
    int board[8][8];    //盤の状態を保持
    int passBoard[8][8];//置けないマスを管理
public:
    Board(/* args */);
    ~Board();
    bool judgePass(Player currentPlayer);
    void dispBoard();
    void changeBoard(int width,int length,int mycolor);
    void changeColor(Player currentPlayer);
    void countStone();
    bool judgeInput(Player currentPlayer);
    bool judgeInputCin(int x,int y,int mycolor);
};

#endif