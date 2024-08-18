#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>
#include "board.hpp"

class TicTacToe:public Board {
private:
    int currentPlayer;
    const int BOARD_SIZE=3;
public:
    TicTacToe();
    void makeMove(int line, int column);
    bool validMove(int line, int column);
    Player* play(Player* player1,Player* player2) override;
    bool checkVictory();
    bool checkTie();
    void switchPlayer();
};

#endif