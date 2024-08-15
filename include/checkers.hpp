#ifndef CHECKERS_HPP
#define CHECKERS_HPP

#include <iostream>
#include <string>
#include "board.hpp"

class CheckersGame : public Board {
private:
    void printBoard() override;
    void setDefaults(int board[8][8]);
    int Enemy(int piece);
    void CheckIfBecameQueen(int x, int y, int board[8][8], int turn);
    void readMove(int coordenadas[]);
    bool validMove(int board[8][8], int x[4]);
    int nextChainValid(int board[8][8], int x[4]);
    bool simpleMove(int x[4], int turn);
    bool captureMove(int board[8][8],int x[4], int turn);
    void updateBoard(int board[8][8], int x[4], int turn, int peshka[2]);
    void getCo(int board[8][8], int turn, int peshka[2]);
    int Winner(int x, int o);

public:
    CheckersGame();
    Player* play(Player* player1, Player* player2) override;
};

#endif