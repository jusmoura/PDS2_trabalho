#ifndef PLAYER_H
#define PLAYER_H

#include "game.hpp"
#include "game_controller.hpp"

#include <string>
#include <vector>

using namespace std;

class Player {
private:
    string _name;
    string _nickname;
    vector<Game> _gamesStats;

public:
    Player(string name, string nickname);
    void setName(string name);
    string getName();
    void setNickname(string name);
    string getNickname();
    void setNumWins(int game, int numWins);
    int getNumWins(int index);
    void setNumDefeats(int game, int numDefeats);
    int getNumDefeats(int index);
};

#endif //PLAYER_H