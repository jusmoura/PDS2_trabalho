#include "reversi.hpp"
#include <iostream>

reversi::reversi(int lin, int col) : tabuleiro(lin, col) {}

void reversi::makeMove(int line, int column, char player) {
    if (validateMove(line, column)) {
        Tabuleiro[line][column] = player;
    }
}

bool reversi::checkVictory(char player) {
    return false;
}

void reversi::printBoard() {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << Tabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
