#include "Board.h"
#include "Player.h"
#include <iostream>
//using namespace std;
class Board;
class Player;

void nextWay(int *i,int *j, int count){
    if(  (count==1) || (count==2) ){
        *i=*i+1;
    }else if( (count==3) || (count==4) ){
        *j=*j+1;  
    }else if( (count==5) || (count==6) ){
        *i=*i-1;
    }else{
        *j=*j-1;
    }
}

int errorCheckRange(int x,int y){
    if( (x==-1) || (x==8) || (y==-1) || (y==8) ){
       return -1;
    }else{
       return 1;
    }
}

/****************/
/*コンストラクタ*/
/****************/
Board::Board()
{
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            board[x][y]=0;
        }
    }

    board[3][3]=1;
    board[3][4]=2;
    board[4][3]=2;
    board[4][4]=1;
}

/**************/
/*デストラクタ*/
/**************/
Board::~Board()
{
}

/**********************************/
/*入力可能なマスが存在するか調べる*/
/**********************************/
bool Board::judgeInput(Player currentPlayer){
    int countMyStone[8]={0,0,0,0,0,0,0,0};
    int countOtherStone[8]={0,0,0,0,0,0,0,0};
    int mycolor=currentPlayer.get_PlayerID();
    int countWayCheck=1;
    int judgeBoard[8][8];
    int a=0;
    int *i;
    int *j;
    int tmpi;
    int tmpj;
    int i0=0;
    int j0=0;
    int k;
    int l;

    i=&i0;
    j=&j0;

    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            judgeBoard[x][y]=2;
        }
    }

    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            if(board[x][y]!= 0){

            }else{
                *i=x-1;
                *j=y-1;
                do{       
                    tmpi=*i;
                    tmpj=*j;
                    if( errorCheckRange(*i,*j)==-1 ){
                        nextWay(i,j,countWayCheck);
                        countWayCheck++;              
                    }else if( ((abs(*i-x)==1) && (abs(*j-y)==1)) && board[*i][*j]==mycolor){
                        nextWay(i,j,countWayCheck);
                        countWayCheck++;
                    }else{
                        k=*i-x;
                        l=*j-y;
                        while( (errorCheckRange(*i,*j)==1)){
                            if((board[*i][*j]==0)){
                                break;
                            }else if(board[*i][*j]==mycolor){
                                countMyStone[countWayCheck-1]=countMyStone[countWayCheck-1]+1;
                                break;
                            }else{
                                countOtherStone[countWayCheck-1]=countOtherStone[countWayCheck-1]+1; 
                            }
                            *i=*i+k;
                            *j=*j+l;
                        }
                    *i=tmpi;
                    *j=tmpj;
                    nextWay(i,j,countWayCheck);
                    countWayCheck++;   
                    }
                }while (countWayCheck<=8);
                countWayCheck=1;
            }
          
            for(int n=0;n<8;n++){
                if(countMyStone[n]>=1 && countOtherStone[n]>=1){
                    a++;
                }
                countMyStone[n]=countOtherStone[n]=0;
            }
            if(a>=1){
                judgeBoard[x][y]=1;
            }else{
                judgeBoard[x][y]=0;
            }
            a=0;
        }//roop1
    }//roop2

    bool r=false;
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            if(judgeBoard[x][y]==1){
                r=true;
            }
        }
    }
    return r;    
}

/********************************/
/*入力したマスに意味があるか確認*/
/********************************/
bool Board::judgeInputCin(int x,int y,int mycolor){
    int countMyStone[8]={0,0,0,0,0,0,0,0};
    int countOtherStone[8]={0,0,0,0,0,0,0,0};
    int countWayCheck=1;
    int a=0;
    int *i;
    int *j;
    int i0=0;
    int j0=0;
    int tmpi;
    int tmpj;
    int k;
    int l;
    int judgeBoard[8][8];

    i=&i0;
    j=&j0;

    if(board[x][y]!= 0){
               
    }else{
        *i=x-1;
        *j=y-1;
        do{       
            tmpi=*i;
            tmpj=*j;
            if( errorCheckRange(*i,*j)==-1 ){
                nextWay(i,j,countWayCheck);
                countWayCheck++;              
            }else if( ((abs(*i-x)==1) && (abs(*j-y)==1)) && board[*i][*j]==mycolor){
                nextWay(i,j,countWayCheck);
                countWayCheck++;
            }else{
                k=*i-x;
                l=*j-y;
                while( (errorCheckRange(*i,*j)==1)){
                    if((board[*i][*j]==0)){
                        break;
                    }else if(board[*i][*j]==mycolor){
                        countMyStone[countWayCheck-1]=countMyStone[countWayCheck-1]+1;
                        break;
                    }else{
                        countOtherStone[countWayCheck-1]=countOtherStone[countWayCheck-1]+1; 
                    }
                    *i=*i+k;
                    *j=*j+l;
                }
                *i=tmpi;
                *j=tmpj;
                nextWay(i,j,countWayCheck);
                countWayCheck++;   
                }
        }while (countWayCheck<=8);
        countWayCheck=1;
    }
          
    for(int n=0;n<8;n++){
        if(countMyStone[n]>=1 && countOtherStone[n]>=1){
            a++;
        }
            countMyStone[n]=countOtherStone[n]=0;
    }
    if(a>=1){
        judgeBoard[x][y]=1;
    }else{
        judgeBoard[x][y]=0;
    }
       
    bool r=false;
   
    if(judgeBoard[x][y]==1){
        r=true;
    }
    
    return r;    
}

/******************/
/*パスの判断を行う*/
/******************/
bool Board::judgePass(Player currentPlayer){
    return judgeInput(currentPlayer);
}

/**********/
/*盤の表示*/
/**********/
void Board::dispBoard(){
    cout << "   +  0  +  1  +  2  +  3  +  4  +  5  +  6  +  7  +" <<endl;
    cout << "+  +-----+-----+-----+-----+-----+-----+-----+-----+" <<endl;
        for (int i = 0; i < 8; i++) {
            cout <<i<<"  "<<"|" ;
            for (int j = 0; j < 8; j++) {
                if (board[j][i] == 1) {
                    cout<<"  ○  |";
                } else if (board[j][i] == 2) {
                    cout<<"  ●  |";
                } else {
                    cout<<"     |";
                }
            }
            cout<<""<<endl;
            cout<<"+  +-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;
        }
}

/**********/
/*石の反転*/
/**********/
void Board::changeColor(Player currentPlayer){
    int countMyStone[8]={0,0,0,0,0,0,0,0};
    int countOtherStone[8]={0,0,0,0,0,0,0,0};
    int mycolor=currentPlayer.get_PlayerID();
    int x=currentPlayer.get_inputX();
    int y=currentPlayer.get_inputY();
    int othercolor;
    int countWayCheck=1;
    int a=0;
    int *i;
    int *j;
    int i0=0;
    int j0=0;
    int tmpi;
    int tmpj;
    int k;
    int l;
    int judgeBoard[8][8];
    int flag=0;

    i=&i0;
    j=&j0;

    if(board[x][y]== 0){
               
    }else{
        *i=x-1;
        *j=y-1;
        do{       
            tmpi=*i;
            tmpj=*j;
            if( errorCheckRange(*i,*j)==-1 ){
                nextWay(i,j,countWayCheck);
                countWayCheck++;              
            }else if( ((abs(*i-x)==1) && (abs(*j-y)==1)) && board[*i][*j]==mycolor){
                nextWay(i,j,countWayCheck);
                countWayCheck++;
            }else{
                a=0;
                flag=0;
                k=*i-x;
                l=*j-y;
                while( (errorCheckRange(*i,*j)==1)){
                    if((board[*i][*j]==0)){
                        break;
                    }else if(board[*i][*j]==mycolor){
                        countMyStone[countWayCheck-1]=countMyStone[countWayCheck-1]+1;
                        a++;
                        flag=1;
                        break;
                    }else{
                        countOtherStone[countWayCheck-1]=countOtherStone[countWayCheck-1]+1; 
                        a++;
                    }
                    *i=*i+k;
                    *j=*j+l;
                }
                if(flag==1){
                    do{
                        *i=*i-k;
                        *j=*j-l;
                        board[*i][*j]=mycolor;
                    }while(*i!=x || *j!=y);
                }
                *i=tmpi;
                *j=tmpj;
                nextWay(i,j,countWayCheck);
                countWayCheck++;   
            }
        }while (countWayCheck<=8);
                countWayCheck=1;
    }
}

/************/
/*入力を反映*/
/************/
void Board::changeBoard(int width,int length,int mycolor){
    board[width][length]=mycolor;
}

/************/
/*勝敗を確認*/
/************/
void Board::countStone(){
    int p1=0,p2=0;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==1){
                p1++;
            }else {
                p2++;
            }
        }
    }
    cout<<"Player1:"<<p1<<"Player2:"<<p2<<endl;
    if(p1>p2){
        cout << "Player1の勝利" << endl;
    }else if(p1<p2){
        cout << "Player2の勝利" << endl;
    }else{
        cout << "引き分け" << endl;
    }
}