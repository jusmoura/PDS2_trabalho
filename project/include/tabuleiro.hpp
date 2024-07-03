#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>

class tabuleiro {
protected:
    int lines;
    int columns;
    std::vector<std::vector<char>> Tabuleiro;

public:
    tabuleiro(int lin, int col);

    bool validateMove(int line, int column);
};

#endif
