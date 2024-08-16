/**
 * @file game_controller.hpp
 * @brief Declaração da classe GameController para gerenciar jogos disponíveis no projeto.
 * 
 * Este arquivo define a classe `GameController`, que gerencia a lista de jogos disponíveis no projeto.
 * A classe mantém uma lista de jogos cadastrados e fornece métodos para acessar esses jogos.
 */
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "game.hpp"

#include <vector>

//Lista de índices dos jogos cadastrados no projeto
/** 
 * @brief Índice para o jogo Reversi.
 */
const int REVERSI = 0;

/** 
 * @brief Índice para o jogo Lig4 (Conecte 4).
 */
const int LIG4 = 1;

/** 
 * @brief Índice para o jogo Jogo da Velha (Tic Tac Toe).
 */
const int TIC_TAC_TOE = 2;

/** 
 * @brief Índice para o jogo Campo Minado (Minesweeper).
 */
const int MINESWEEPER = 3;

/** 
 * @brief Índice para o jogo Damas (Checkers).
 */
const int CHECKERS = 4;

/**
 * @class GameController
 * @brief Gerencia a lista de jogos disponíveis no projeto.
 * 
 * A classe `GameController` é responsável por manter uma lista de jogos disponíveis e fornecer
 * acesso a esses jogos. A lista de jogos é gerenciada internamente e pode ser expandida com novos
 * jogos adicionados à lista.
 */
class GameController {
private:
    /** 
     * @brief Lista de nomes dos jogos cadastrados.
     * 
     * Esta lista contém os nomes dos jogos disponíveis no projeto. Para adicionar um novo jogo,
     * basta adicionar o nome correspondente a esta lista e criar uma nova constante para o índice.
     */
    //Lista de jogos cadastrados
    /*Para cadastrar um novo jogo, basta adicionar o nome no vetor de nomes abaixo e criar uma nova const*/
    vector<string> _NameGames = { "Reversi", "Lig4", "Jogo da Velha", "Campo Minado", "Damas" };

    /** 
     * @brief Lista de jogos disponíveis.
     * 
     * Esta lista contém objetos da classe `Game` que representam os jogos disponíveis no projeto.
     */
    vector<Game> _availableGames;

public:

    /**
     * @brief Construtor da classe GameController.
     * 
     * Inicializa uma instância de `GameController` e configura a lista de jogos disponíveis.
     */
    GameController();

    /**
     * @brief Obtém a lista de jogos disponíveis.
     * 
     * @return Um vetor de objetos `Game` representando os jogos disponíveis no projeto.
     */
    vector<Game> getAvailableGames();
};

#endif //GAME_CONTROLLER_H