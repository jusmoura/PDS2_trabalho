#ifndef LIG4_HPP
#define LIG4_HPP

#include "board.hpp"

class Lig4 : public Board {
private:
    int currentPlayer;
    const int BOARD_SIZE=7;
public:
    Lig4();
    bool checkVictory();
    bool checkTie();
    void makeMove(int column);
    void switchPlayer();
    Player* play(Player* player1, Player* player2);
};

#endif //LIG4_HPP
