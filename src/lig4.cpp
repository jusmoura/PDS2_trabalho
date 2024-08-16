#include "LIG4.hpp"
#include <iostream>


void setBoard(int board[6][7]){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            board[i][j]=0;
        }
    }
}

void printBoard(int board[6][7]){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            std::cout<<"|"<<board[i][j]<<"|";
        }
       std::cout<<std::endl;
    }
}

void Lig4::switchPlayer(int currentPlayer,int playerX,int playerO){
    if(currentPlayer==playerX)
        currentPlayer=playerO;
    else
        currentPlayer=playerX;
}

void Lig4::makeMove(int currentPlayer, int board[6][7], int column) {
    std::cin>>column;
    if(board[0][column]==0)
        board[0][column]=currentPlayer;
    else if(board[1][column]==0)
        board[1][column]=currentPlayer;
    else if(board[2][column]==0)
        board[2][column]=currentPlayer;
    else if(board[3][column]==0)
        board[3][column]=currentPlayer;
    else if(board[4][column]==0)
        board[4][column]=currentPlayer;
    else if(board[5][column]==0)
        board[5][column]=currentPlayer;
    else
        makeMove(currentPlayer,board,column);
}

bool Lig4::checkTie(int board[6][7]){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(board[i][j]==0)
                return false;
        }
    }
    return true;
}

bool Lig4::checkVictory(int currentPlayer, int board[6][7]){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(board[i][j]==currentPlayer && board[i][j]==board[i][j+1] && board[i][j+1]==board[i][j+2] && board[i][j+2]==board[i][j+3])
                return true;
            else if(board[i][j]==currentPlayer && board[i][j]==board[i+1][j] && board[i+1][j]==board[i+2][j] && board[i+2][j]==board[i+3][j])
                return true;
            else if(board[i][j]==currentPlayer && board[i][j]==board[i+1][j+1] && board[i+1][j+1]==board[i+2][j+2] && board[i+2][j+2]==board[i+3][j+3])
                return true;
            else if(board[i][j]==currentPlayer && board[i][j]==board[i-1][j+1] && board[i-1][j+1]==board[i-2][j+2] && board[i-2][j+2]==board[i-3][j+3])
                return true;
        }
    }
    return false;
}

void Lig4::play(int board[6][7]) {
    setBoard(board);
    printBoard(board);
    int column;
    int playerX=1;
    int playerO=2;
    currentPlayer=playerX;
    while(!checkVictory(currentPlayer,board)&&!checkTie(board)){
        std::cout<<currentPlayer<<" play: "<<std::endl;
        makeMove(currentPlayer,board,column);
        printBoard(board);
        if(checkVictory(currentPlayer,board))
            break;
        if(checkTie(board))
            break;
        switchPlayer(currentPlayer,playerX,playerO);
    }
}






