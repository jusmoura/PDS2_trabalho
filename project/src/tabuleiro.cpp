#include "tabuleiro.hpp"

tabuleiro::tabuleiro(int lin, int col) : lines(lin), columns(col), Tabuleiro(std::vector<std::vector<char>>(lin, std::vector<char>(col, ' '))) {}

bool tabuleiro::validateMove(int line, int column) {
    if (line < 0 || line >= lines || column < 0 || column >= columns)
        return false;
    if (Tabuleiro[line][column] != ' ')
        return false;
    return true;
}
