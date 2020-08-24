#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;
class Board;
class Player;

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

bool Board::judgeInput(){
    int i=inputX-1;
    int j=inputY-1;//配置した場所の左上
    int k,l;//増分
    int count=0;
    int flag[8];//周りの分のフラグ
    bool Flag=0;//OK:1 NO:0 //周りがすべて0なら0
    int mycolor;//=getplayerID //1:black 2:white

    Player exPlayer=new Player();
    mycolor=exPlayer.get_PlayerID;
    
    do{
        if(i==-1 || i==8 || j==-1 || j==8 || board[i][j]==mycolor){
            //何もしない(ひっくり返せない)
            flag[count]=0;
        }else{//延長線上を調べる
            k=i-inputX;
            l=j-inputY;//進む方向
            do{//mycolorが見つかるまで繰り替えす
                if(board[i+k][j+l] != mycolor){
                    i=i+k;
                    j=j+l;
                }else if(i+k==-1 || i+k==8 || j+l==-1 || j+l==8 ){
                    //mycolorが見つからない
                    flag[count]=0;
                    break;
                }else{
                    flag[count]=1;
                    break;//mycolorが見つかった
                }
            } while (1); 
        }
        //i,jの進め方
        if(0<=count && count<=1){
            i++;
        }else if(2<=count && count<=3){
            j--;
        }else if(4<=count && count<=5){
            i--;
        }else{
            i++;
        }
        count++;

    }while(count<=7);//1周分行う

    for(int m=0;m<count;m++){
        if(flag[m]==1){//一箇所でもひっくり返れば良い
            Flag=1;
        }
    }

    return Flag;
}

bool Board::judgePass(){
    return judgeInput;
}

void Board::dispBoard(){
    cout << "+--+--+--+--+--+--+--+--+" <<endl;
        for (int i = 0; i < 8; i++) {
            cout << "|" <<endl;
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 1) {
                    cout<<"○|"<<endl;
                } else if (board[i][j] == 2) {
                    cout<<"●|"<<endl;
                } else {
                    cout<<"  |"<<endl;
                }
            }
          //  System.out.println();
            cout<<"+--+--+--+--+--+--+--+--+"<<endl;
        }
}

void Board::changeColor(){
    int i=inputX-1;
    int j=inputY-1;//配置した場所の左上
    int tmp_i,tmp_j;
    int k,l;//増分
    int count=0;
    int flag[8];//周りの分のフラグ
    bool Flag=0;//OK:1 NO:0 //周りがすべて0なら0
    int mycolor;//=getplayerID //1:black 2:white
    
    Player exPlayer=new Player();
    mycolor=exPlayer.get_PlayerID;

    do{
        tmp_i=i;
        tmp_j=j;

        if(i==-1 || i==8 || j==-1 || j==8 || board[i][j]==mycolor){
            //何もしない(ひっくり返せない)
            flag[count]=0;
        }else{//延長線上を調べる
            k=i-inputX;
            l=j-inputY;//進む方向
            do{//mycolorが見つかるまで繰り替えす
                if(board[i+k][j+l] != mycolor){
                    i=i+k;
                    j=j+l;
                }else if(i+k==-1 || i+k==8 || j+l==-1 || j+l==8 ){
                    //mycolorが見つからない
                    flag[count]=0;
                    break;
                }else{
                    flag[count]=1;
                    break;//mycolorが見つかった
                }
            } while (1); 
        }
        //inputX,Yへ、 ひっくり返しながら戻る
        do{
        board[i][j]==mycolor;
        i=i-k;
        j=j-l;
        }while(inputX==i && inputY==j);

        i=tmp_i;
        j=tmp_j;

        //i,jの進め方
        if(0<=count && count<=1){
            i++;
        }else if(2<=count && count<=3){
            j--;
        }else if(4<=count && count<=5){
            i--;
        }else{
            i++;
        }
        count++;

    }while(count<=7);//1周分行う
}

void Board::changeBoard(int length,int width){
    int mycolor;//ID取得しないとダメ

    inputX=length;
    inputY=width;

    board[inputX][inputY]=mycolor;
}

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

    if(p1>p2){
        cout << "Player1の勝利" << endl;
    }else if(p1<p2){
        cout << "Player2の勝利" << endl;
    }else{
        cout << "引き分け" << endl;
    }
}