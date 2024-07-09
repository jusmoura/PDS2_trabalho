#include "lig4.hpp"
#include <iostream>

Lig4::Lig4(int line, int column) : Board(line, column) {
}

void Lig4::makeMove(int line, int column, int player) {
    if (validateMove(line, column)) {
        _board[line][column].setValue(player);
    }
}

bool Lig4::checkVictory(int player) {
    return false;
}

// void Lig4::printBoard() {
//     for (int i = 0; i < linesSize; ++i) {
//         for (int j = 0; j < columnsSize; ++j) {
//             std::cout << _board[i][j].getValue() << " ";
//         }
//         std::cout << std::endl;
//     }
// }