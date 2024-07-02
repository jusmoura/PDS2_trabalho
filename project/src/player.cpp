#include "../include/player.hpp"

Player::Player(string name, string nickname) {
    this->_name = name;
    this->_nickname = nickname;

    GameController gameController = GameController();
    this->_gamesStats = gameController.getGames();
}

string Player::getName() {
    return _name;
}

string Player::getNickname() {
    return _nickname;
}

void Player::setName(string name) {
    this->_name = name;
}

void Player::setNickname(string nickname) {
    this->_nickname = nickname;
}

int Player::getNumWins(int game) {
    return _gamesStats[game].getNumWins();
}

int Player::getNumDefeats(int game) {
    return _gamesStats[game].getNumDefeats();
}