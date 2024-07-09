#include "../include/reversi.hpp"

Reversi::Reversi(int line, int column) : Board(line, column) {
}

void Reversi::makeMove(int line, int column, int player) {
    if (validateMove(line, column)) {
        _board[line][column].setValue(player);
    }
}

bool Reversi::checkVictory(int player) {
    return false;
}

// void Reversi::printBoard() {
//     for (int i = 0; i < linesSize; ++i) {
//         for (int j = 0; j < columnsSize; ++j) {
//             std::cout << _board[i][j].getValue() << " ";
//         }
//         std::cout << std::endl;
//     }
// }