#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "board.hpp"

class Reversi : public Board {
public:
    Reversi(int line, int column);

    void makeMove(int line, int column, int player);
    bool checkVictory(int player);
    // void printBoard();
};

#endif //REVERSI_HPP