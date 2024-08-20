/**
 * @file player_controller.hpp
 * @brief Declaração da classe PlayerController, responsável pelo gerenciamento de todos os jogadores.
 *
 * Este arquivo contém a definição da classe PlayerController, que é responsável por
 * realizar operações relacionadas aos jogadores, como inserção, remoção, listagem e atribuição de estatísticas dos jogos.
 */
#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "player.hpp"
#include "database_controller.hpp"
#include "colors.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

class DatabaseController;
/**
 * @brief Controlador responsável por gerenciar operações relacionadas aos jogadores.
 *
 * A classe `PlayerController` lida com a adição, remoção, e acesso de jogadores dentro do sistema.
 * Ela também fornece métodos para listar jogadores, tanto por nome quanto por apelido (nickname).
 */
class PlayerController {
private:
    /**
    * @brief Instancia o DatabaseController para possibilitar a persistência de informações entre execuções.
    *
    */
    DatabaseController* databaseController;
    /**
    * @brief Vetor de ponteiros para todos os jogadores existentes, tanto os pré-salvos e buscados via arquivo, quando para os novos.
    *
    */
    std::vector<Player*> _players;

    /**
     * @brief Encontra o índice de um jogador no vetor `_players`.
     *
     * @param nickname O apelido do jogador a ser encontrado.
     * @return O índice do jogador se encontrado, ou -1 se não encontrado.
     */
     /* Métodos */
    int findIndexOfPlayer(std::string nickname);

    /**
     * @brief Imprime uma lista de todos os jogadores.
     *
     * Função auxiliar que exibe os detalhes de todos os jogadores armazenados.
     */
    void printPlayers();

public:
    /**
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
     * @return Ponteiro para o jogador correspondente ao índice ou nullptr se não encontrado.
     */
    Player* getPlayerByIndex(int index);

    /**
     * @brief Obtém um jogador pelo apelido.
     *
     * @param nickname O apelido do jogador a ser obtido.
     * @return Ponteiro para o jogador correspondente ao apelido ou nullptr se não encontrado..
     */
    Player* getPlayerByNickname(std::string nickname);

    /**
     * @brief Insere um novo jogador no vetor de players.
     *
     * @param player Ponteiro para o jogador a ser inserido.
     * @return `true` se a inserção for bem-sucedida, `false` caso contrário.
     */
    bool insertNewPlayer(Player* player);

    /**
     * @brief Remove um jogador do vetor de players.
     *
     * @param nickname O apelido do jogador a ser removido.
     * @return 1 caso o jogador tenha sido removido, -1 se o jogador não for encontrado,
     * ou 0 caso o vetor de players esteja vazio (nenhum player cadastrado).
     */
    int removePlayer(std::string nickname);

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
    * @brief Gerenciador de atribuição de vitórias, derrotas e empates em jogos.
    *
    * Atribui vitória, derrota ou empate para os jogadores após o término de uma partida.
    */
    void victoryAndDefeatManagement(Player* winner, Player* player1, Player* player2, int selectedGame);

    /**
     * @brief Destrutor da classe `PlayerController`.
     *
     * Libera os recursos alocados pelo controlador de jogadores.
     */
    ~PlayerController();
};

#endif //PLAYER_CONTROLLER_H