#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "game.hpp"

#include <vector>

//Lista de índices dos jogos cadastrados no projeto
const int REVERSI = 0;
const int LIG4 = 1;
const int TIC_TAC_TOE = 2;
const int MINESWEEPER = 3;

class GameController {
private:
    vector<Game> _games;

public:
    GameController();
    vector<Game> getGames();
};

#endif //GAME_CONTROLLER_H