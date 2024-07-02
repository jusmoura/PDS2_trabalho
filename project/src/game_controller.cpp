#include "../include/game_controller.hpp"

GameController::GameController() {
    Game gameReversi("Reversi");
    Game gameLig4("Lig4");
    Game gameTicTacToe("Jogo da Velha");
    Game gameMinesweeper("Campo Minado");

    _games.push_back(gameReversi);
    _games.push_back(gameLig4);
    _games.push_back(gameTicTacToe);
    _games.push_back(gameMinesweeper);
}

vector<Game> GameController::getGames() {
    return this->_games;
}