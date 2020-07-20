#ifndef BOARD_H
#define BOARD_H

using namespace std;
class Board
{
private:
    /* data */
    /*Null:0 white:1 black:2*/
    int board[8][8];    //盤の状態を保持
    int passBoard[8][8];//置けないマスを管理
    int inputX;         //x座標を保持
    int inputY;         //y座標を保持
public:
    Board(/* args */);//盤の初期化(コンストラクタ)
    ~Board();//デストラクタ
    bool judgePass();//パスの判断 -->judgeInput()
    void dispBoard();//盤の状態を表示
    void changeBoard();//入力を反映
    void changeColor();//色をひっくり返す
    void  countStone();//石を数える
    bool judgeInput();//引数のマスにおけるか判断
};

#endif