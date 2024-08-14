#include "../include/player.hpp"

using namespace std;

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

ostream& operator << (ostream& os, Player& player) {
    os << "Nome: " << player.getName() << endl;
    os << "Apelido: " << player.getNickname() << endl;

    os << "-- Estatisticas dos Jogos --" << endl;

    vector<Game>* games = player.getGamesStats();
    int gamesSize = games->size();

    for (int i = 0; i < gamesSize; i++)
        os << games->at(i).getName() << " - V: " << games->at(i).getNumWins() << ", D: " << games->at(i).getNumDefeats() << endl;

    os << "\n";

    return os;
}