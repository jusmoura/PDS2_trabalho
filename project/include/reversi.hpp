#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "tabuleiro.hpp"

class reversi : public tabuleiro {
public:
    reversi(int lin, int col);

    void makeMove(int line, int column, char player);
    bool checkVictory(char player);
    void printBoard();
};

#endif 
