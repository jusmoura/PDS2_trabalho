#include <iostream>
#include "jogodavelha.hpp"
using namespace std;


void printBoard(int board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"|"<<board[i][j]<<"|";
        }
        cout<<endl;
    }

}

bool JogoDaVelha::checkVictory(int board[3][3], int currentPlayer) {
    for(int i=0;i<3;i++){
        if(board[i][0]==currentPlayer && board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;
        else if(board[0][i]==currentPlayer && board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
        else if(board[0][0]==currentPlayer && board[0][0]==board[1][1] && board[1][1]==board[2][2])
            return true;
        else if(board[0][2]==currentPlayer && board[0][2]==board[1][1] && board[1][1]==board[2][0])
            return true;
        else
            return false;
    }
}

bool JogoDaVelha::checkTie(int board [3][3]) {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==0)
                return false;
        }
    }
    return true;
}

bool JogoDaVelha::validMove(int board[3][3],int line, int column) {
    if(board[line][column]==0)
        return true;
    else
        return false;
}

void JogoDaVelha::switchPlayer(int currentPlayer,int playerX,int playerO){
    if(currentPlayer==playerX)
        currentPlayer=playerO;
    else
        currentPlayer=playerX;
}

void JogoDaVelha:: makeMove(int board[3][3],int currentPlayer,int line,int column){
    cin>>line;
    cin>>column;
    if(validMove(board,line,column))
        board[line][column]=currentPlayer;
    else
        makeMove(board,currentPlayer,line,column);
}

void JogoDaVelha::play(int board[3][3]){
    int line;
    int column;
    printBoard(board);
    int playerX,playerO;
    currentPlayer=playerX;
    while(!checkVictory(board,currentPlayer)&&!checkTie(board)) {
        makeMove(board, currentPlayer,line,column);
        printBoard(board);
        if (checkVictory(board,currentPlayer)) {
            break;
        }
        else if (checkTie(board)) {
            break;
        }
        switchPlayer(currentPlayer,playerX,playerO);
    }
    cout<<"game over"<<endl;
}
