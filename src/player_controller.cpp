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

bool PlayerController::insertNewPlayer(Player player) {
    int playerIndex = findIndexOfPlayer(player.getNickname());

    //Verifica se o player não existe
    if (playerIndex == -1) {
        _players.push_back(player);
        return true;
    }

    else
        return false;
}

int PlayerController::removePlayer(string nickname) {
    if (_players.empty())
        return 0;

    int playerIndex = findIndexOfPlayer(nickname);

    if (playerIndex == -1 || playerIndex >= _players.size())
        return -1;

    else {
        _players.erase(_players.begin() + playerIndex);
        return 1;
    }
}


void PlayerController::printPlayersByName() {
    if (_players.empty()) {
        cout << "\n" << RED_COLOR << "Nenhum jogador cadastrado!" << RESET_ALL << endl;
        return;
    }

    cout << "\n" << BLUE_COLOR << "Exibindo jogadores ordenados pelo NOME...\n" << RESET_ALL << endl;

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
        cout << "\n" << RED_COLOR << "Nenhum jogador cadastrado!" << RESET_ALL << endl;
        return;
    }

    cout << "\n" << BLUE_COLOR << "Exibindo jogadores ordenados pelo APELIDO...\n" << RESET_ALL << endl;

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
    //Caso o jogador não seja encontrado
    return -1;
}

void PlayerController::printPlayers() {
    for (auto player : _players)
        cout << player;
}