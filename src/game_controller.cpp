#include "../include/game_controller.hpp"

//Instancia todos os jogos disponíveis no projeto
GameController::GameController() {
    for (auto name : _NameGames) {
        Game newGame(name);
        _availableGames.push_back(newGame);
    }
}

std::vector<Game> GameController::getAvailableGames() {
    return this->_availableGames;
}