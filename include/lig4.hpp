/**
 * @file Lig4.hpp
 * @brief Declaração da classe Lig4 para implementar o jogo Lig4 (Conecta 4).
 */
#ifndef LIG4_HPP
#define LIG4_HPP

#include "board.hpp"

 /**
  * @class Lig4
  * @brief Classe que implementa o jogo Lig4 (Conecta 4), derivada da classe Board.
  */
class Lig4 : public Board {
private:
    /**
    * @brief Jogador que está executando a jogada durante sua iteração.
     */
    int currentPlayer;

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
     * @brief Faz uma jogada no tabuleiro.
     * @param column A coluna em que o jogador deseja fazer a jogada.
     */
    void makeMove(int column);

    /**
     * @brief Alterna o jogador atual.
     */
    void switchPlayer();

    /**
     * @brief Imprime o tabuleiro do jogo.
     * Este método sobrescreve o método `printBoard` da classe base Board.
     */
    void printBoard() override;
public:
    /**
     * @brief Construtor padrão para inicializar o jogo Lig4.
     */
    Lig4();

    /**
     * @brief Inicia e gerencia o loop principal do jogo.
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     * @return Retorna o ponteiro para o jogador vencedor ou nullptr em caso de empate.
     */
    Player* play(Player* player1, Player* player2);
};

#endif //LIG4_HPP
