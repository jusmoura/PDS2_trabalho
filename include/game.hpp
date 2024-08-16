/**
 * @file game.hpp
 * @brief Declaração da classe Game para representar um jogo.
 * 
 * Este arquivo define a classe `Game`, que é usada para representar um jogo com informações
 * sobre o nome do jogo e suas estatísticas, como o número de vitórias, derrotas e empates.
 */
#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;
/**
 * @class Game
 * @brief Representa um jogo com estatísticas de desempenho.
 * 
 * A classe `Game` armazena informações sobre um jogo específico, incluindo seu nome e estatísticas
 * relacionadas ao desempenho, como o número de vitórias, derrotas e empates.
 */
class Game {
private:
    /** 
     * @brief Nome do jogo.
     * 
     * Armazena o nome do jogo.
     */
    string _name;
    /** 
     * @brief Número de vitórias no jogo.
     * 
     * Armazena o total de vitórias obtidas.
     */
    int _numWins;
    /** 
     * @brief Número de derrotas no jogo.
     * 
     * Armazena o total de derrotas sofridas.
     */
    int _numDefeats;
    /** 
     * @brief Número de empates no jogo.
     * 
     * Armazena o total de empates ocorridos.
     */
    int _numDraws;

public:
    /**
     * @brief Construtor da classe Game.
     * 
     * Inicializa uma instância de `Game` com o nome especificado. O número de vitórias, derrotas e empates
     * é inicializado com zero.
     * 
     * @param name O nome do jogo.
     */
    Game(string name);
    /**
     * @brief Define o nome do jogo.
     * 
     * @param name O novo nome do jogo.
     */
    void setName(string name);
    /**
     * @brief Obtém o nome do jogo.
     * 
     * @return O nome do jogo.
     */
    string getName();
    /**
     * @brief Define o número de vitórias no jogo.
     * 
     * @param numWins O novo número de vitórias.
     */
    void setNumWins(int numWins);
    /**
     * @brief Obtém o número de vitórias no jogo.
     * 
     * @return O número de vitórias.
     */
    int getNumWins();
    /**
     * @brief Define o número de derrotas no jogo.
     * 
     * @param numDefeats O novo número de derrotas.
     */
    void setNumDefeats(int numDefeats);
    /**
     * @brief Obtém o número de derrotas no jogo.
     * 
     * @return O número de derrotas.
     */
    int getNumDefeats();
    /**
     * @brief Define o número de empates no jogo.
     * 
     * @param numDraws O novo número de empates.
     */
    void setNumDraws(int numDraws);
    /**
     * @brief Obtém o número de empates no jogo.
     * 
     * @return O número de empates.
     */
    int getNumDraws();
};

#endif //GAME_H