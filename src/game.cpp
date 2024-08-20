#include "../include/game.hpp"

using namespace std;

//Construtor inicial - player recém cadastrado
Game::Game(string name) {
    this->_name = name;
    this->_numWins = 0;
    this->_numDefeats = 0;
    this->_numDraws = 0;
}

string Game::getName() {
    return this->_name;
}

void Game::setName(string name) {
    this->_name = name;
}

int Game::getNumWins() {
    return this->_numWins;
}

void Game::setNumWins(int numWins) {
    this->_numWins = numWins;
}

int Game::getNumDefeats() {
    return this->_numDefeats;
}

void Game::setNumDefeats(int numDefeats) {
    this->_numDefeats = numDefeats;
}

int Game::getNumDraws() {
    return this->_numDraws;
}

void Game::setNumDraws(int numDraws) {
    this->_numDraws = numDraws;
}