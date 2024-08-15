#ifndef CHECKERS_HPP
#define CHECKERS_HPP

#include <iostream>
#include <string>
#include "board.hpp"

class CheckersGame : public Board {
private:
    const int BOARD_SIZE = 8;
    int turn = 2;
    int peshka[2] = {12, 12};

    void setDefaults();
    int enemy(int piece);
    void checkIfBecameQueen(int x, int y);
    void readMove(int x[]);
    bool validMove(int x[4]);
    int nextChainValid(int x[4]);
    bool simpleMove(int x[4]);
    bool captureMove(int x[4]);
    void updateBoard(int x[4]);
    void getCo();
    int winner(int x, int o);

public:
    CheckersGame();
    Player* play(Player* player1, Player* player2) override;
};

#endif