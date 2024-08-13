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

Player* PlayerController::getPlayerByNickname(string nickname) {
    int playerIndex = findIndexOfPlayer(nickname);

    if (playerIndex == -1) {
        cout << "Jogador com apelido " << nickname << " nao encontrado!" << endl;
        return nullptr;
    }
    else
        return &_players[playerIndex];
}

void PlayerController::insertNewPlayer(Player player) {
    int playerIndex = findIndexOfPlayer(player.getNickname());

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
            //Conversão local dos nomes dos jogadores para UPPERCASE para fins de comparação (a == A)
            string nameI = _players[min_idx].getName();
            transform(nameI.begin(), nameI.end(), nameI.begin(), ::toupper);
            string nameJ = _players[j].getName();
            transform(nameJ.begin(), nameJ.end(), nameJ.begin(), ::toupper);

            if (nameJ < nameI)
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
            //Conversão local dos nomes dos jogadores para UPPERCASE para fins de comparação (a == A)
            string nicknameI = _players[min_idx].getNickname();
            transform(nicknameI.begin(), nicknameI.end(), nicknameI.begin(), ::toupper);
            string nicknameJ = _players[j].getNickname();
            transform(nicknameJ.begin(), nicknameJ.end(), nicknameJ.begin(), ::toupper);

            if (nicknameJ < nicknameI)
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
int PlayerController::findIndexOfPlayer(string nickname) {
    int size = _players.size();

    for (int i = 0; i < size; i++) {
        if (nickname == _players[i].getNickname())
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