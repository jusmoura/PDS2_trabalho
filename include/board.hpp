#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"
#include "player.hpp"
#include "colors.hpp"

#include <iostream>
#include <vector>
#include <string>

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
    virtual Player* play(Player* player1, Player* player2) = 0;

public:
    Board(int line, int column);
    virtual void printBoard();
};

#endif //BOARD_HPP