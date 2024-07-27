#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "board.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

class Minesweeper : public Board {
private:
    const int IS_BOMB = 50; // Número arbitrário escolhido para representar uma bomba
    void printBoard() override;
    void setBombsPositions();
    bool checkDefeat(int line, int column);
    bool checkVictory() override;
    void checkAndShowAdjacentsCells(int row, int column);

public:
    Minesweeper(int line, int column);
    bool play();
};

#endif //MINESWEEPER_H