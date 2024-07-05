#include "../include/player_controller.hpp"

PlayerController::PlayerController() {
    databaseController = new DatabaseController();
    databaseController->readFile(this);
}

int PlayerController::getTotalNumberOfPlayers() {
    return _players.size();
}

Player* PlayerController::getPlayerByIndex(int index) {
    return &_players[index];
}

void PlayerController::insertNewPlayer(Player player) {
    int playerIndex = findIndexOfPlayer(player);

    //Verifica se o player já existe
    if (playerIndex == -1)
        _players.push_back(player);

    else
        cout << "Jogador com apelido " << player.getNickname() << " já cadastrado!" << endl;
}

void PlayerController::removePlayerByIndex(int index) {
    if (_players.empty()) {
        cout << "Nenhum jogador cadastrado!" << endl;
        return;
    }

    if (index == -1 || index >= _players.size()) {
        cout << "Jogador não encontrado!" << endl;
        return;
    }

    cout << "Jogador " << _players[index].getNickname() << " removido!" << endl;
    _players.erase(_players.begin() + index);
}


void PlayerController::printPlayersByName() {
    if (_players.empty()) {
        cout << "Nenhum jogador cadastrado!" << endl;
        return;
    }

    cout << "\nExibindo jogadores ordenados pelo nome:\n" << endl;

    int size = _players.size();

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (_players[j].getName() < _players[min_idx].getName())
                min_idx = j;
        }

        if (min_idx != i)
            swap(_players[min_idx], _players[i]);
    }

    printPlayers();
}

void PlayerController::printPlayersByNickname() {
    if (_players.empty()) {
        cout << "Nenhum jogador cadastrado!" << endl;
        return;
    }

    cout << "\nExibindo jogadores ordenados pelo apelido:\n" << endl;

    int size = _players.size();

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (_players[j].getNickname() < _players[min_idx].getNickname())
                min_idx = j;
        }

        if (min_idx != i)
            swap(_players[min_idx], _players[i]);
    }

    printPlayers();
}

void PlayerController::endProcess() {
    databaseController->writeFile(this);
}

/* Métodos privados */
int PlayerController::findIndexOfPlayer(Player wantedPlayer) {
    int size = _players.size();

    for (int i = 0; i < size; i++) {
        if (wantedPlayer.getNickname() == _players[i].getNickname())
            return i;
    }

    return -1;
}

void PlayerController::printPlayers() {
    for (auto player : _players) {
        cout << "Nome: " << player.getName() << endl;
        cout << "Apelido: " << player.getNickname() << endl;

        cout << "-- Estatisticas dos Jogos --" << endl;

        vector<Game>* games = player.getGamesStats();
        int gamesSize = games->size();

        for (int i = 0; i < gamesSize; i++)
            cout << games->at(i).getName() << " - V: " << games->at(i).getNumWins() << ", D: " << games->at(i).getNumDefeats() << endl;

        cout << "\n";
    }
}