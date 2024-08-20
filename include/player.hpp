/**
 * @file player.hpp
 * @brief Declaração da classe Player, responsável por representar e gerenciar as estatísticas de um jogador.
 *
 * Este arquivo contém a definição da classe Player, que gerencia informações como nome, apelido e
 * estatísticas de jogos (vitórias, derrotas, empates) para cada jogador.
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "game_controller.hpp"
#include "colors.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

 /**
  * @brief Representa um jogador com estatísticas de jogos.
  *
  * A classe Player armazena informações como nome, apelido e estatísticas de desempenho
  * em diferentes jogos, permitindo o gerenciamento e exibição dessas informações.
  */

class Player {
private:
    /**
    * @brief Nome do jogador
    *
    */
    std::string _name;
    /**
    * @brief Apelido do jogador
    *
    */
    std::string _nickname;
    /**
    * @brief Jogos disponíveis, obtidos por meio da classe GameController
    *
    */
    std::vector<Game> _gamesStats;

public:
    /**
     * @brief Construtor da classe Player.
     *
     * @param name Nome do jogador.
     * @param nickname Apelido do jogador.
     */
    Player(std::string name, std::string nickname);

    /**
     * @brief Define o nome do jogador.
     *
     * @param name Novo nome do jogador.
     */
    void setName(std::string name);

    /**
     * @brief Obtém o nome do jogador.
     *
     * @return Nome do jogador.
     */
    std::string getName();

    /**
     * @brief Define o apelido do jogador.
     *
     * @param nickname Novo apelido do jogador.
     */
    void setNickname(std::string name);

    /**
     * @brief Obtém o apelido do jogador.
     *
     * @return Apelido do jogador.
     */
    std::string getNickname();

    /**
     * @brief Obtém as estatísticas de jogos do jogador.
     *
     * @return Ponteiro para o vetor de estatísticas de jogos.
     */
    std::vector<Game>* getGamesStats();

    /**
     * @brief Adiciona uma vitória para o jogador em um determinado jogo.
     *
     * @param game Índice do jogo.
     */
    void addWin(int game);

    /**
     * @brief Adiciona uma derrota para o jogador em um determinado jogo.
     *
     * @param game Índice do jogo.
     */
    void addDefeat(int game);

    /**
     * @brief Adiciona um empate para o jogador em um determinado jogo.
     *
     * @param game Índice do jogo.
     */
    void addDraw(int game);

    /**
     * @brief Define o número de vitórias do jogador em um determinado jogo.
     *
     * @param game Índice do jogo.
     * @param numWins Número de vitórias a ser definido.
     */
    void setNumWins(int game, int numWins);

    /**
     * @brief Obtém o número de vitórias do jogador em um determinado jogo.
     *
     * @param index Índice do jogo.
     * @return Número de vitórias.
     */
    int getNumWins(int index);

    /**
     * @brief Define o número de derrotas do jogador em um determinado jogo.
     *
     * @param game Índice do jogo.
     * @param numDefeats Número de derrotas a ser definido.
     */
    void setNumDefeats(int game, int numDefeats);

    /**
     * @brief Obtém o número de derrotas do jogador em um determinado jogo.
     *
     * @param index Índice do jogo.
     * @return Número de derrotas.
     */
    int getNumDefeats(int index);

    /**
     * @brief Define o número de empates do jogador em um determinado jogo.
     *
     * @param game Índice do jogo.
     * @param numDraws Número de empates a ser definido.
     */
    void setNumDraws(int game, int numDraws);

    /**
     * @brief Obtém o número de empates do jogador em um determinado jogo.
     *
     * @param index Índice do jogo.
     * @return Número de empates.
     */
    int getNumDraws(int index);


    //Sobrecarga do operador <<
    /**
     * @brief Sobrecarga do operador de inserção de stream para exibir informações do jogador.
     *
     * @param os O stream de saída.
     * @param player O jogador cujas informações serão exibidas.
     * @return O stream de saída.
     */
    friend std::ostream& operator << (std::ostream& os, Player& player);
};

#endif //PLAYER_H