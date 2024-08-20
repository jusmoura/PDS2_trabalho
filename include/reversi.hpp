/**
 * @file reversi.hpp
 * @brief Declaração da classe ReversiGame para o jogo Reversi
 *
 * Este arquivo contém a definição da classe `ReversiGame`, que herda da classe `Board` e implementa a lógica e as regras do jogo Reversi. A classe gerencia o estado do jogo, controla a troca de jogadores, valida movimentos, e calcula a pontuação e o resultado final do jogo.
 *
 */

#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "board.hpp"

 /**
  * @brief Classe que implementa o jogo Reversi.
  *
  * A classe `ReversiGame` herda da classe `Board` e implementa as regras e a lógica específicas do jogo Reversi, também conhecido como Othello.
  * Esta classe gerencia o tabuleiro, a troca de jogadores, a validação de movimentos, o cálculo da pontuação, e o resultado final do jogo.
  */
class ReversiGame : public Board {
private:
    /**
    * @brief Tamanho do tabuleiro para o jogo Reversi.
    *
    * O tamanho padrão do tabuleiro de Reversi é 8x8.
    */
    const int BOARD_SIZE = 8;
    /**
    * @brief Número total de peças do jogador X.
    *
    */
    int sumX;
    /**
    * @brief Número total de peças do jogador O.
    *
    */
    int sumO;
    /**
    * @brief Número total de dicas disponíveis para o jogador O.
    *
    */
    int hintsO;
    /**
    * @brief Número total de dicas disponíveis para o jogador O.
    *
    */
    int hintsX;
    /**
    * @brief Jogador que está executando a jogada durante sua iteração.
     */
    int currentPlayer;

    /**
     * @brief Troca o jogador atual.
     *
     * Este método alterna o jogador que está atualmente realizando a jogada. Se o jogador atual é o jogador X, ele se torna o jogador O, e vice-versa.
     *
     * Este método não possui parâmetros e não retorna nenhum valor.
     *
     */
    void switchPlayer();

    /**
     * @brief Verifica se o movimento (x, y) é válido.
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @return Número de peças que serão viradas, ou 0 se o movimento não for válido.
     */
    int validMove(int x, int y);

    /**
     * @brief Retorna as jogadas válidas no formato de coordenadas (linha, coluna).
     * @return Vetor de pares (linha, coluna) representando as jogadas válidas.
     */
    std::vector<std::pair<int, int>> help();

    /**
     * @brief Retorna dicas de jogadas no formato de coordenadas (linha, coluna) e número de peças viradas.
     * @return Vetor de pares (linha, coluna) e número de peças viradas.
     */
    std::vector<std::pair<std::pair<int, int>, int>> hint();

    /**
     * @brief Faz um movimento no tabuleiro na posição (x, y).
     * @param x Coordenada x.
     * @param y Coordenada y.
     */
    void makeMove(int x, int y);

    /**
     * @brief Calcula e exibe a pontuação dos jogadores X e O.
     */
    void calculateScore();

    /**
     * @brief Verifica e exibe o resultado final do jogo.
     * @return O jogador vencedor.
     */
    Player* checkVictory(Player* player1, Player* player2);

public:
    /**
    * @brief Construtor padrão para inicializar o jogo Reversi.
    */
    ReversiGame();

    /**
     * @brief Inicia o jogo entre dois jogadores.
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     * @return Ponteiro para o jogador vencedor.
     */
    Player* play(Player* player1, Player* player2) override;
};

#endif // REVERSI_HPP