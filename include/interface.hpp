#ifndef INTERFACE_H
#define INTERFACE_H

#include "player_controller.hpp"
#include "minesweeper.hpp"
#include "reversi.hpp"
#include "lig4.hpp"
#include "tic_tac_toe.hpp"
#include "checkers.hpp"

#include <iostream>

const int VOLTAR = 8;
const int SAIR = 9;

class Interface {
private:
    PlayerController* controller = new PlayerController();
public:
    void mainMenu();
    void playersMenu();
    void gamesMenu();
    Player* createPlayer();
    void removePlayer();
    Player* loginPlayer(string playerNumber);
    Player* playerLoginVerification(Player* player1, Player* player2, string playerNumber);
    void clearBuffer();
    void endProcess();
};

#endif //INTERFACE_H