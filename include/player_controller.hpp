#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "player.hpp"
#include "database_controller.hpp"
#include "colors.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class DatabaseController;

class PlayerController {
private:
    DatabaseController* databaseController;
    vector<Player*> _players;
    /* Métodos */
    int findIndexOfPlayer(string nickname);
    void printPlayers();

public:
    PlayerController();
    int getTotalNumberOfPlayers();
    Player* getPlayerByIndex(int index);
    Player* getPlayerByNickname(string nickname);
    bool insertNewPlayer(Player* player);
    int removePlayer(string nickname);
    void printPlayersByName();
    void printPlayersByNickname();
    ~PlayerController();
};

#endif //PLAYER_CONTROLLER_H