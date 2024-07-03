#ifndef LIG4_HPP
#define LIG4_HPP

#include "tabuleiro.hpp"

class lig4 : public tabuleiro {
public:
    lig4(int lin, int col);

    void makeMove(int line, int column, char player);
    bool checkVictory(char player);
    void printBoard();
};

#endif
