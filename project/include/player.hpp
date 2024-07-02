#ifndef PLAYER_H
#define PLAYER_H

#include "games.hpp"

#include <string>
#include <vector>

using namespace std;

class Player {
private:
    string _name;
    string _nickname;
    vector<Games> _gamesStats;

public:
    Player(string name, string nickname);
    string getName();
    string getNickname();
    void setName(string name);
    void setNickname(string name);
};

#endif //PLAYER_H