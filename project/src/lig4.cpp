#include "lig4.hpp"
#include <iostream>

lig4::lig4(int lin, int col) : tabuleiro(lin, col) {}

void lig4::makeMove(int line, int column, char player) {
    if (validateMove(line, column)) {
        Tabuleiro[line][column] = player;
    }
}

bool lig4::checkVictory(char player) {
    return false;
}

void lig4::printBoard() {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << Tabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
