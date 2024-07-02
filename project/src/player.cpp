#include "../include/player.hpp"
#include "../include/games.hpp"

Player::Player(string name, string nickname) {
    this->_name = name;
    this->_nickname = nickname;

    Games game1("Reversi");
    Games game2("Lig4");
    Games game3("Jogo da Velha");
    Games game4("Campo Minado");

    _gamesStats.push_back(game1);
    _gamesStats.push_back(game2);
    _gamesStats.push_back(game3);
    _gamesStats.push_back(game4);
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