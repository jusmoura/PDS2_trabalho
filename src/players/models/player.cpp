#include "../include/player.hpp"

Player::Player(string name, string nickname) {
    this->_name = name;
    this->_nickname = nickname;

    GameController gameController = GameController();
    this->_gamesStats = gameController.getAvailableGames();
}

void Player::setName(string name) {
    this->_name = name;
}

string Player::getName() {
    return _name;
}

void Player::setNickname(string nickname) {
    this->_nickname = nickname;
}

string Player::getNickname() {
    return _nickname;
}

void Player::addWin(int game) {
    int numWins = this->getNumWins(game);
    this->setNumWins(game, ++numWins);
}

void Player::addDefeat(int game) {
    int numDefeats = this->getNumDefeats(game);
    this->setNumDefeats(game, ++numDefeats);
}

vector<Game>* Player::getGamesStats() {
    return &_gamesStats;
}

void Player::setNumWins(int game, int numWins) {
    this->_gamesStats[game].setNumWins(numWins);
}

int Player::getNumWins(int game) {
    return _gamesStats[game].getNumWins();
}

void Player::setNumDefeats(int game, int numDefeats) {
    this->_gamesStats[game].setNumDefeats(numDefeats);
}

int Player::getNumDefeats(int game) {
    return _gamesStats[game].getNumDefeats();
}