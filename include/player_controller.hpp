/**
 * @file player_controller.hpp
 * @brief Declaração da classe PlayerController responsável pelo gerenciamento dos jogadores.
 * 
 * Este arquivo contém a definição da classe PlayerController, que é responsável por 
 * realizar operações relacionadas aos jogadores, como inserção, remoção, e listagem de jogadores.
 */
#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "player.hpp"
#include "database_controller.hpp"
#include "colors.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class DatabaseController;
/**
 * @brief Controlador responsável por gerenciar operações relacionadas aos jogadores.
 * 
 * A classe `PlayerController` lida com a adição, remoção, e acesso de jogadores dentro do sistema. 
 * Ela também fornece métodos para listar jogadores, tanto por nome quanto por apelido (nickname).
 */
class PlayerController {
private:
    DatabaseController* databaseController;
    vector<Player*> _players;

    /**
     * @brief Encontra o índice de um jogador no vetor `_players`.
     * 
     * @param nickname O apelido do jogador a ser encontrado.
     * @return O índice do jogador se encontrado, ou -1 se não encontrado.
     */
    /* Métodos */
    int findIndexOfPlayer(string nickname);

    /**
     * @brief Imprime uma lista de todos os jogadores.
     * 
     * Função auxiliar que exibe os detalhes de todos os jogadores armazenados.
     */
    void printPlayers();

public:    /**
     * @brief Construtor da classe `PlayerController`.
     * 
     * Inicializa um novo controlador de jogadores.
     */
    PlayerController();

    /**
     * @brief Retorna o número total de jogadores.
     * 
     * @return Número de jogadores atualmente armazenados.
     */
    int getTotalNumberOfPlayers();

    /**
     * @brief Obtém um jogador pelo índice.
     * 
     * @param index O índice do jogador a ser obtido.
     * @return Ponteiro para o jogador correspondente ao índice.
     */
    Player* getPlayerByIndex(int index);

    /**
     * @brief Obtém um jogador pelo apelido.
     * 
     * @param nickname O apelido do jogador a ser obtido.
     * @return Ponteiro para o jogador correspondente ao apelido.
     */
    Player* getPlayerByNickname(string nickname);

    /**
     * @brief Insere um novo jogador no sistema.
     * 
     * @param player Ponteiro para o jogador a ser inserido.
     * @return `true` se a inserção for bem-sucedida, `false` caso contrário.
     */
    bool insertNewPlayer(Player* player);

    /**
     * @brief Remove um jogador do sistema.
     * 
     * @param nickname O apelido do jogador a ser removido.
     * @return O índice do jogador removido, ou -1 se o jogador não for encontrado.
     */
    int removePlayer(string nickname);

    /**
     * @brief Imprime a lista de jogadores ordenada por nome.
     * 
     * Exibe os jogadores em ordem alfabética pelo nome.
     */
    void printPlayersByName();

    /**
     * @brief Imprime a lista de jogadores ordenada por apelido.
     * 
     * Exibe os jogadores em ordem alfabética pelo apelido.
     */
    void printPlayersByNickname();

    /**
     * @brief Destrutor da classe `PlayerController`.
     * 
     * Libera os recursos alocados pelo controlador de jogadores.
     */
    ~PlayerController();
};

#endif //PLAYER_CONTROLLER_H