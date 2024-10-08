/**
 * @file Board.hpp
 * @brief Declaração da classe abstrata Board para gerenciar e manipular o tabuleiro de jogos.
 *
 * Este arquivo define a classe abstrata `Board`, que é utilizada como base para implementar os
 * diversos jogos de tabuleiro, como Reversi, Lig4, Jogo da Velha, Damas e Campo Minado. A classe
 * fornece funcionalidades básicas para inicializar e imprimir o tabuleiro, além de métodos
 * virtuais para validação e execução de jogadas.
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"
#include "player.hpp"
#include "colors.hpp"

#include <iostream>
#include <vector>
#include <string>

 /**
 * @brief Constante que auxilia no encerramento prematuro dos jogos e retorna o usuário para a interface principal
 */
const int SIMPLE_RETURN = 10;

/*Abstract Class*/
/**
 * @class Board
 * @brief Classe abstrata que define a estrutura e funcionalidades básicas do tabuleiro de jogo.
 *
 * A classe `Board` é uma classe abstrata que define as operações essenciais para manipular
 * o tabuleiro dos jogos. As classes derivadas devem implementar o método virtual puro
 * `play` para realizar jogadas específicas do jogo.
 */
class Board {
private:
    /**
     * @brief Inicializa o tabuleiro com as configurações padrão.
     *
     * Este método é chamado no construtor para definir o tamanho do tabuleiro e preencher
     * as células com o estado inicial.
     */
    void initBoard();

protected:
    /*Constantes*/
    /**
     * @brief Constante que representa uma célula vazia no tabuleiro.
     */
    const int EMPTY = 0;

    /**
     * @brief Constante que representa o jogador X no tabuleiro.
     */
    const int PLAYER_X = 1;

    /**
     * @brief Constante que representa o jogador O no tabuleiro.
     */
    const int PLAYER_O = 2;

    /*Variáveis*/
    /**
     * @brief Tamanho total das linhas do tabuleiro.
     */
    int linesSize;

    /**
     * @brief Tamanho total das colunas do tabuleiro.
     */
    int columnsSize;

    /**
     * @brief Matriz que representa o tabuleiro de jogo, composta por objetos da classe Cell.
     */
    std::vector<std::vector<Cell>> _board;

    /*Métodos*/
    /**
     * @brief Construtor da classe Board.
     *
     * Inicializa o tabuleiro com o número de linhas e colunas especificado.
     *
     * @param line Número de linhas do tabuleiro.
     * @param column Número de colunas do tabuleiro.
     */
    Board(int line, int column);

    /**
     * @brief Imprime o tabuleiro no console.
     *
     * Este método imprime o estado atual do tabuleiro no console. As classes derivadas
     * podem sobrepor este método para fornecer uma representação visual específica do tabuleiro.
     */
    virtual void printBoard();
    /**
     * @brief Valida se a jogada nas coordenadas especificadas é permitida.
     *
     * Este método é virtual e deve ser implementado pelas classes derivadas para
     * validar as jogadas específicas do jogo.
     *
     * @param line Linha da célula a ser verificada.
     * @param column Coluna da célula a ser verificada.
     * @return Retorna true se a jogada for válida, caso contrário retorna false.
     */
    virtual bool validateMove(int line, int column);

    /**
     * @brief Executa a jogada dos jogadores.
     *
     * Este método é virtual puro e deve ser implementado pelas classes derivadas para
     * realizar a jogada específica do jogo.
     *
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     * @return Ponteiro para o jogador que ganhou a partida, ou nullptr em caso de empate.
     */
    virtual Player* play(Player* player1, Player* player2) = 0;
};

#endif //BOARD_HPP