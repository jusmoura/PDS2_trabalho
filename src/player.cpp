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

void Player::setNumDraws(int game, int numDraws) {
    this->_gamesStats[game].setNumDraws(numDraws);
}

int Player::getNumDraws(int game) {
    return _gamesStats[game].getNumDraws();
}

ostream& operator << (ostream& os, Player& player) {
    os << CYAN_COLOR;
    os << "Nome: " << player.getName() << endl;
    os << "Apelido: " << player.getNickname() << endl;

    os << GRAY_COLOR;
    os << " ------- Estatisticas dos Jogos -------" << endl;
    os << RESET_ALL;

    vector<Game>* games = player.getGamesStats();
    int gamesSize = games->size();

    for (int i = 0; i < gamesSize; i++) {
        string gameName = games->at(i).getName();

        os << GRAY_COLOR << "| " << RESET_ALL;
        os << setw(13) << left << gameName << " - ";
        os << GREEN_COLOR << "V: " << setw(3) << left << games->at(i).getNumWins() << RESET_ALL << "| ";
        os << RED_COLOR << "D: " << setw(3) << left << games->at(i).getNumDefeats() << RESET_ALL << "| ";

        if (gameName != "Campo Minado" && gameName != "Damas") {
            os << YELLOW_COLOR << "E: " << setw(2) << left << games->at(i).getNumDraws();
            os << GRAY_COLOR << "|" << RESET_ALL;
        }
        else
            os << setw(10) << left << GRAY_COLOR << "|" << RESET_ALL;

        os << endl;
    }
    os << GRAY_COLOR << " --------------------------------------\n\n" << RESET_ALL;

    return os;
}