#ifndef LIG4_HPP
#define LIG4_HPP

#include "board.hpp"

class Lig4 : public Board {
public:
    Lig4(int lin, int col);

    void makeMove(int line, int column, int player);
    bool checkVictory(int player);
    // void printBoard();
};

#endif //LIG4_HPP