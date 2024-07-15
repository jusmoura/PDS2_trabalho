#ifndef INTERFACE_H
#define INTERFACE_H

#include "../include/player_controller.hpp"
#include "../include/minesweeper.hpp"
#include "../include/reversi.hpp"
#include "../include/lig4.hpp"
// #include "../include/tic_tac_toe.hpp"
// #include "../include/checkers.hpp"

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