#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "player.hpp"
#include "database_controller.hpp"

#include <iostream>
#include <vector>

using namespace std;
class DatabaseController;

class PlayerController {
private:
    DatabaseController* databaseController;
    vector<Player> _players;

public:
    PlayerController();
    void insertPlayer(Player player);
    int getTotalNumberOfPlayers();
    Player getPlayerByIndex(int index);
    void printPlayers();
    void endProcess();
};

#endif //PLAYER_CONTROLLER_H