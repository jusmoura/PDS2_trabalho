/**
 * @file minesweeper.hpp
 * @brief Declaração da classe Minesweeper para implementar o jogo Campo Minado.
 *
 * Este arquivo define a classe `Minesweeper`, que herda da classe `Board` e implementa as funcionalidades
 * específicas do jogo Campo Minado, incluindo a colocação aleatória de bombas, verificação de derrota e vitória, e
 * exibição do tabuleiro.
 */
#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "board.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

 /**
  * @class Minesweeper
  * @brief Implementa o jogo Campo Minado.
  *
  * A classe `Minesweeper` herda da classe `Board` e fornece a lógica específica para o jogo Campo Minado,
  * incluindo a colocação aleatória de bombas, verificação de derrota e vitória, e exibição do tabuleiro com informações
  * sobre as células adjacentes.
  */
class Minesweeper : public Board {
private:
    /**
     * @brief Valor usado para representar uma bomba no tabuleiro.
     *
     * Um número arbitrário escolhido para identificar uma célula que contém uma bomba.
     */
    const int IS_BOMB = 50; // Número arbitrário escolhido para representar uma bomba

    /**
     * @brief Exibe o tabuleiro do jogo.
     *
     * Sobrescreve o método `printBoard` da classe base `Board` para exibir o tabuleiro do Campo Minado,
     * incluindo as células reveladas e ocultas.
     */
    void printBoard() override;

    /**
     * @brief Define as posições das bombas no tabuleiro, de maneira aleatória.
     *
     * Coloca as bombas aleatoriamente no tabuleiro, garantindo que o número de bombas e suas posições
     * sejam adequados para o tamanho do tabuleiro.
     */
    void setBombsPositions();

    /**
     * @brief Verifica se houve derrota no jogo.
     *
     * Verifica se o jogador clicou em uma célula que contém uma bomba, resultando em derrota.
     *
     * @param line Linha da célula clicada.
     * @param column Coluna da célula clicada.
     * @return `true` se o jogador perdeu, `false` caso contrário.
     */
    bool checkDefeat(int line, int column);

    /**
     * @brief Verifica se houve vitória no jogo.
     *
     * Verifica se todas as células não-bombas foram reveladas, resultando em vitória.
     *
     * @return `true` se o jogador venceu, `false` caso contrário.
     */
    bool checkVictory();

    /**
     * @brief Verifica e exibe, de maneira recursiva, as células adjacentes a uma célula revelada.
     *
     * Revela as células adjacentes e mostra as informações relacionadas a essas células.
     *
     * @param row Linha da célula revelada.
     * @param column Coluna da célula revelada.
     */
    void checkAndShowAdjacentsCells(int row, int column);

public:
    /**
    * @brief Construtor padrão para inicializar o jogo Campo Minado.
    */
    Minesweeper();
    /**
     * @brief Inicia e gerencia o jogo Campo Minado.
     *
     * Inicia o jogo e gerencia o fluxo. Inicializa o segundo jogador como `nullptr` pois
     * apenas um player joga o jogo
     *
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador (opcional).
     * @return Ponteiro para o jogador que venceu, ou `nullptr` em caso de derrota.
     */
    Player* play(Player* player1, Player* player2 = nullptr) override;
};

#endif //MINESWEEPER_H