#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game {
private:
    string _name;
    int _numWins;
    int _numDefeats;
    int _numDraws;

public:
    Game(string name);
    void setName(string name);
    string getName();
    void setNumWins(int numWins);
    int getNumWins();
    void setNumDefeats(int numDefeats);
    int getNumDefeats();
    void setNumDraws(int numDraws);
    int getNumDraws();
};

#endif //GAME_H