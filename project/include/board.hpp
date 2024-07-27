#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"

#include <iostream>
#include <vector>

/*Abstract Class*/
class Board {
private:
    void initBoard();

protected:
    /*Constantes*/
    const int EMPTY = 0;
    const int PLAYER_X = 1;
    const int PLAYER_O = 2;

    /*Variáveis*/
    int linesSize;
    int columnsSize;
    std::vector<std::vector<Cell>> _board;

    /*Métodos*/
    virtual bool validateMove(int line, int column);
    virtual bool checkVictory() = 0;

public:
    Board(int line, int column);
    virtual void printBoard();
};

#endif //BOARD_HPP