#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <sstream>
#include <iostream>

const int BOARD_SIZE = 9;

class Board {
public:
    std::vector<std::vector<char>> grid;

    Board();

    void initialize();

    void display();
};

class ReversiGame {
public:
    Board board;
    int sumX;
    int sumO;
    int hintsO;
    int hintsX;
    char currentPlayer;

    ReversiGame();

    void switchPlayer();

    int validMove(int x, int y);

    std::vector<std::pair<int, int>> help();

    std::vector<std::pair<std::pair<int, int>, int>> hint();

    void makeMove(int x, int y);

    void calculateScore();

    void play();
};

#endif // REVERSI_HPP
