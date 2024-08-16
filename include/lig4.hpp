#ifndef LIG4_HPP
#define LIG4_HPP

#include "board.hpp"

class Lig4 : public Board {
private:
    int currentPlayer;
public:
    Lig4();
    bool checkVictory(int currentPlayer,int board[6][7]);
    bool checkTie(int board[6][7]);
    void makeMove(int currentPlayer,int board[6][7],int column);
    void switchPlayer(int currentPlayer, int playerX,int playerO);
    void play(int board[6][7]);
};

#endif //LIG4_HPP
