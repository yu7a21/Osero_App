#ifndef BOARD_H
#define BOARD_H

using namespace std;
class Player;
class Board
{
private:
    /* data */
    /*Null:0 white:2 black:1*/
    int board[8][8];    //盤の状態を保持
    int passBoard[8][8];//置けないマスを管理
    int inputX;         //x座標を保持
    int inputY;         //y座標を保持
public:
    Board(/* args */);//盤の初期化(コンストラクタ)
    ~Board();//デストラクタ
    bool judgePass(Player currentPlayer);//パスの判断 -->judgeInput() ok
    void dispBoard();//盤の状態を表示 ok
    void changeBoard(int length,int width,int id);//入力を反映 ok
    void changeColor(Player currentPlayer);//色をひっくり返す　ok
    void countStone();//石を数える ok
    bool judgeInput(Player currentPlayer);//引数のマスにおけるか判断 ok
};

#endif