#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"

#include <iostream>
#include <vector>

class Board {
private:
    void initBoard();

protected:
    int linesSize;
    int columnsSize;
    std::vector<std::vector<Cell>> _board;
    bool validateMove(int line, int column);

public:
    Board(int line, int column);
    virtual void printBoard();
};

#endif //BOARD_HPP