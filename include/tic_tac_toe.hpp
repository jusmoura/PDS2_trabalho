/**
 * @file TicTacToe.hpp
 * @brief Declaração da classe TicTacToe para implementar o jogo da velha (Tic-Tac-Toe).
 */

#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>
#include "board.hpp"

/**
 * @class TicTacToe
 * @brief Classe que implementa o jogo da velha (Tic-Tac-Toe) derivada da classe Board.
 */

class TicTacToe:public Board {
private:
    int currentPlayer;
    const int BOARD_SIZE=3;

    /**
     * @brief Faz uma jogada no tabuleiro.
     * @param line A linha em que o jogador deseja fazer a jogada.
     * @param column A coluna em que o jogador deseja fazer a jogada.
     */
    void makeMove(int line, int column);

    /**
     * @brief Verifica se a jogada é válida.
     * @param line A linha da jogada proposta.
     * @param column A coluna da jogada proposta.
     * @return true se a jogada for válida, false caso contrário.
     */
    bool validMove(int line, int column);

    /**
     * @brief Verifica se algum jogador venceu o jogo.
     * @return true se houver um vencedor, false caso contrário.
     */
    bool checkVictory();

    /**
     * @brief Verifica se o jogo terminou em empate.
     * @return true se o jogo estiver empatado, false caso contrário.
     */
    bool checkTie();

    /**
     * @brief Alterna o jogador atual.
     */
    void switchPlayer();
public:
    /**
     * @brief Construtor padrão para inicializar um jogo da velha.
     */
    TicTacToe();

    /**
     * @brief Inicia e gerencia o loop principal do jogo.
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     * @return Retorna o ponteiro para o jogador vencedor ou nullptr em caso de empate.
     */
    Player* play(Player* player1,Player* player2) override;
};

#endif