#include "../include/player_controller.hpp"

PlayerController::PlayerController() {
    databaseController = new DatabaseController();
    databaseController->readFile(this);
}

int PlayerController::getTotalNumberOfPlayers() {
    return _players.size();
}

Player* PlayerController::getPlayerByIndex(int index) {
    return _players[index];
}

Player* PlayerController::getPlayerByNickname(string nickname) {
    int playerIndex = findIndexOfPlayer(nickname);

    if (playerIndex == -1)
        return nullptr;

    else
        return _players[playerIndex];
}

bool PlayerController::insertNewPlayer(Player* player) {
    int playerIndex = findIndexOfPlayer(player->getNickname());

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
        Player* player = _players[playerIndex];
        _players.erase(_players.begin() + playerIndex);
        delete player;
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
            string nameI = _players[min_idx]->getName();
            transform(nameI.begin(), nameI.end(), nameI.begin(), ::toupper);
            string nameJ = _players[j]->getName();
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
            string nicknameI = _players[min_idx]->getNickname();
            transform(nicknameI.begin(), nicknameI.end(), nicknameI.begin(), ::toupper);
            string nicknameJ = _players[j]->getNickname();
            transform(nicknameJ.begin(), nicknameJ.end(), nicknameJ.begin(), ::toupper);

            if (nicknameJ < nicknameI)
                min_idx = j;
        }

        if (min_idx != i)
            swap(_players[min_idx], _players[i]);
    }

    printPlayers();
}

int PlayerController::findIndexOfPlayer(string nickname) {
    int size = _players.size();

    for (int i = 0; i < size; i++) {
        if (nickname == _players[i]->getNickname())
            return i;
    }
    //Caso o jogador não seja encontrado
    return -1;
}

void PlayerController::victoryAndDefeatManagement(Player* winner, Player* player1, Player* player2, int selectedGame) {
    if (winner == player1) {
        player1->addWin(selectedGame);
        player2->addDefeat(selectedGame);
    }
    else if (winner == player2) {
        player2->addWin(selectedGame);
        player1->addDefeat(selectedGame);
    }
    else {
        if (selectedGame != CHECKERS) {
            player1->addDraw(selectedGame);
            player2->addDraw(selectedGame);
        }
    }
}

void PlayerController::printPlayers() {
    for (auto player : _players)
        cout << *player;
}

PlayerController::~PlayerController() {
    databaseController->writeFile(this);
    delete databaseController;

    for (auto player : _players)
        delete player;
}