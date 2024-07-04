#include "../include/player_controller.hpp"

PlayerController::PlayerController() {
    databaseController = new DatabaseController();
    databaseController->readFile(this);
}

void PlayerController::insertPlayer(Player player) {
    _players.push_back(player);
}

int PlayerController::getTotalNumberOfPlayers() {
    return _players.size();
}

Player PlayerController::getPlayerByIndex(int index) {
    return _players[index];
}

void PlayerController::printPlayers() {
    cout << "\nExibindo jogadores...\n" << endl;

    for (auto player : _players) {
        cout << "Nome: " << player.getName() << endl;
        cout << "Apelido: " << player.getNickname() << endl;

        cout << "-- Estatisticas dos Jogos --" << endl;

        for (auto game : player.getGamesStats())
            cout << game.getName() << " - V: " << game.getNumWins() << ", D: " << game.getNumDefeats() << endl;

        cout << "\n";
    }
}

void PlayerController::endProcess() {
    databaseController->writeFile(this);
}