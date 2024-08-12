#ifndef INTERFACE_H
#define INTERFACE_H

#include "player_controller.hpp"
#include "minesweeper.hpp"
#include "reversi.hpp"
#include "lig4.hpp"
#include "tic_tac_toe.hpp"
#include "checkers.hpp"

#include <iostream>

class Interface {
private:
    PlayerController* controller = new PlayerController();
public:
    void mainMenu();
    void playersMenu();
    void gamesMenu();
    void endProcess();
};

#endif //INTERFACE_H