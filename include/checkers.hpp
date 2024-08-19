/**
 * @file checkers.hpp
 * @brief Declaração da classe CheckersGame para gerenciar um jogo de damas.
 * 
 * Este arquivo define a classe `CheckersGame`, que herda da classe `Board` e fornece funcionalidades
 * específicas para um jogo de damas. A classe gerencia o estado do jogo, as regras de movimentação e
 * captura, e determina o vencedor.
 */

#ifndef CHECKERS_HPP
#define CHECKERS_HPP

#include <iostream>
#include <cmath>
#include "board.hpp"

/**
 * @class CheckersGame
 * @brief Implementa a lógica do jogo de damas (checkers) baseado na classe Board.
 * 
 * A classe `CheckersGame` é uma implementação específica de um jogo de damas que herda da classe
 * `Board`. Ela inclui métodos para definir o tabuleiro, validar movimentos, realizar jogadas e
 * determinar o vencedor do jogo.
 */
class CheckersGame : public Board {
private:
    /** 
     * @brief Tamanho do tabuleiro para o jogo de damas.
     * 
     * O tamanho padrão do tabuleiro de damas é 8x8.
     */
    const int BOARD_SIZE = 8;

    /**
     * @brief Constante que representa a 'Dama' do jogador X no tabuleiro.
     */
    const int PLAYER_X_QUEEN = 3;

    /**
     * @brief Constante que representa a 'Dama' do jogador O no tabuleiro.
     */
    const int PLAYER_O_QUEEN = 4;

    /** 
     * @brief Indica o turno atual no jogo.
     * 
     * Valores possíveis são 1 ou 2, representando os dois jogadores.
     */
    int turn = 2;

    /** 
     * @brief Armazena a quantidade de peças para cada jogador.
     * 
     * O array pieces[2] armazena o número de peças restantes para o jogador 1 e jogador 2.
     */
    int pieces[2] = {12, 12};

    /**
     * @brief Configura os valores padrão para o jogo de damas.
     * 
     * Este método inicializa o tabuleiro e as peças de acordo com as regras do jogo de damas.
     */
    void setDefaults();

    /**
     * @brief Determina o jogador adversário com base na peça fornecida.
     * 
     * @param piece O jogador cuja peça está sendo verificada.
     * @return O jogador adversário.
     */
    int enemy(int piece);

    /**
     * @brief Verifica se uma peça se tornou uma dama após um movimento.
     * 
     * @param x Coordenada x da peça no tabuleiro.
     * @param y Coordenada y da peça no tabuleiro.
     */
    void checkIfBecameQueen(int x, int y);

    /**
     * @brief Lê e interpreta um movimento de jogador.
     * 
     * @param coordinates Array que armazena as coordenadas do movimento.
     */
    void readMove(int coordinates[]);

    /**
     * @brief Valida se um movimento é válido.
     * 
     * @param coordinates Array que contém as coordenadas do movimento.
     * @return Retorna true se o movimento for válido, caso contrário retorna false.
     */
    bool validMove(int coordinates[4]);

    /**
     * @brief Valida a continuidade de uma cadeia de movimentos.
     * 
     * @param coordinates Array que contém as coordenadas do movimento.
     * @return O número de movimentos válidos em sequência.
     */
    int nextChainValid(int coordinates[4]);

    /**
     * @brief Executa um movimento simples no tabuleiro.
     * 
     * @param coordinates Array que contém as coordenadas do movimento.
     * @return Retorna true se o movimento foi executado com sucesso, caso contrário retorna false.
     */
    bool simpleMove(int coordinates[4]);

    /**
     * @brief Executa um movimento de captura no tabuleiro.
     * 
     * @param coordinates Array que contém as coordenadas do movimento.
     * @return Retorna true se a captura foi realizada com sucesso, caso contrário retorna false.
     */
    bool captureMove(int coordinates[4]);

    /**
     * @brief Atualiza o estado do tabuleiro após um movimento.
     * 
     * @param coordinates Array que contém as coordenadas do movimento.
     */
    void updateBoard(int coordinates[4]);

    /**
     * @brief Obtém as coordenadas de um movimento do jogador.
     * 
     * Este método é responsável por ler as coordenadas do movimento a partir da entrada do jogador.
     */
    void getCo();

    /**
     * @brief Determina o vencedor do jogo.
     * 
     * @param x Número de peças restantes para o jogador X.
     * @param o Número de peças restantes para o jogador O.
     * @return O número do jogador vencedor ou 0 se houver um empate.
     */
    int winner(int x, int o);

public:
    /**
     * @brief Construtor da classe CheckersGame.
     * 
     * Inicializa o jogo de damas, configurando o tabuleiro e as peças de acordo com as regras do jogo.
     */
    CheckersGame();

    /**
     * @brief Realiza uma jogada no jogo de damas.
     * 
     * Este método sobrepõe o método `play` da classe `Board` para implementar a lógica específica
     * das jogadas no jogo de damas.
     * 
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     * @return Ponteiro para o jogador que fez a jogada.
     */
    Player* play(Player* player1, Player* player2) override;
};

#endif //CHECKERS_HPP
