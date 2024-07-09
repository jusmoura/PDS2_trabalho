#ifndef PLAYER_H
#define PLAYER_H

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
    vector<Game>* getGamesStats();
    void addWin(int game);
    void addDefeat(int game);
    void setNumWins(int game, int numWins);
    int getNumWins(int index);
    void setNumDefeats(int game, int numDefeats);
    int getNumDefeats(int index);
};

#endif //PLAYER_H