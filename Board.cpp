#include "Board.h"
class Board;

Board::Board(/* args */)
{
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            board[x][y]=0;
        }
    }

    board[3][3]=1;
    board[3][4]=2;
    board[4][3]=1;
    board[4][4]=2;
}

Board::~Board()
{
}
