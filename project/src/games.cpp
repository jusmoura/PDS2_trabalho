#include "../include/games.hpp"

Games::Games(string name) {
    this->_name = name;
    this->_numWins = 0;
    this->_numDefeats = 0;
}

string Games::getName() {
    return this->_name;
}

void Games::setName(string name) {
    this->_name = name;
}