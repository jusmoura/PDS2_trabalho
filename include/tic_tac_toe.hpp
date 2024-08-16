#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>

class TicTacToe {
private:
    int currentPlayer;
public:
    TicTacToe();
    void printBoard(int board[3][3]);
    void makeMove(int board[3][3], int currentPlayer, int line, int column);
    bool validMove(int board[3][3], int line, int column);
    void play(int board[3][3]);
    bool checkVictory(int board[3][3], int currentPlayer);
    bool checkTie(int board[3][3]);
    void switchPlayer(int currentPlayer, int playerX, int playerO);
};

#endif