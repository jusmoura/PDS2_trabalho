#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"
#include "player.hpp"

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

    /*Cores*/
    static const std::string RED;
    static const std::string YELLOW;
    static const std::string RESET;
    

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

const std::string Board::RED = "\033[31m";    // Texto vermelho (para jogador X)
const std::string Board::YELLOW = "\033[33m"; // Texto amarelo (para jogador O)
const std::string Board::RESET = "\033[0m";
#endif //BOARD_HPP