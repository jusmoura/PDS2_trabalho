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
    for (auto player : _players) {
        cout << "Nome: " << player.getName() << endl;
        cout << "Apelido: " << player.getNickname() << endl;
        cout << "REVERSI -- Numero de Vitorias: " << player.getNumWins(REVERSI) << endl;
        cout << "REVERSI -- Numero de Derrotas: " << player.getNumDefeats(REVERSI) << endl;
        cout << "LIG4 -- Numero de Vitorias: " << player.getNumWins(LIG4) << endl;
        cout << "LIG4 -- Numero de Derrotas: " << player.getNumDefeats(LIG4) << endl;
        cout << "TIC_TAC_TOE -- Numero de Vitorias: " << player.getNumWins(TIC_TAC_TOE) << endl;
        cout << "TIC_TAC_TOE -- Numero de Derrotas: " << player.getNumDefeats(TIC_TAC_TOE) << endl;
        cout << "MINESWEEPER -- Numero de Vitorias: " << player.getNumWins(MINESWEEPER) << endl;
        cout << "MINESWEEPER -- Numero de Derrotas: " << player.getNumDefeats(MINESWEEPER) << endl;
        cout << "\n";
    }
}

void PlayerController::endProcess() {
    databaseController->writeFile(this);
}