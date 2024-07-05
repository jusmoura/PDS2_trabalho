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
    //Lista de jogos cadastrados
    /*Para cadastrar um novo jogo, basta adicionar o nome no vetor de nomes abaixo e criar uma nova const*/
    vector<string> _NameGames = { "Reversi", "Lig4", "Jogo da Velha", "Campo Minado" };
    vector<Game> _availableGames;

public:
    GameController();
    vector<Game> getAvailableGames();
};

#endif //GAME_CONTROLLER_H