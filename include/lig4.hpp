#ifndef LIG4_HPP
#define LIG4_HPP

#include "board.hpp"

class Lig4 : public Board {
private:
    int currentPlayer;
    bool checkVictory();
    bool checkTie();
    void makeMove(int column);
    void switchPlayer();
    void printBoard() override;
public:
    Lig4();
    Player* play(Player* player1, Player* player2);
};

#endif //LIG4_HPP
