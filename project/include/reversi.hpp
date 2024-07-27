#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <sstream>
#include <iostream>

#include "board.hpp"

class ReversiGame : public Board {
private:
    const int BOARD_SIZE = 8;
    int sumX;
    int sumO;
    int hintsO;
    int hintsX;
    char currentPlayer;

    /*Metodos*/
    void switchPlayer();
    int validMove(int x, int y);
    std::vector<std::pair<int, int>> help();
    std::vector<std::pair<std::pair<int, int>, int>> hint();
    void makeMove(int x, int y);
    void calculateScore();

public:
    ReversiGame();
    void play();
};

#endif // REVERSI_HPP