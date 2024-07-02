#ifndef GAMES_H
#define GAMES_H

#include <string>

using namespace std;

class Games {
private:
    string _name;
    int _numWins;
    int _numDefeats;

public:
    Games(string name);
    string getName();
    void setName(string name);
};

#endif //GAMES_H