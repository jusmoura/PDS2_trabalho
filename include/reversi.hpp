#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "board.hpp"

class ReversiGame : public Board {
private:
    const int BOARD_SIZE = 8;
    int sumX;
    int sumO;
    int hintsO;
    int hintsX;
    int currentPlayer;

    /**
     * @brief Troca o jogador atual.
     * 
     * Este método alterna o jogador que está atualmente realizando a jogada. Se o jogador atual é o jogador X, ele se torna o jogador O, e vice-versa.
     * 
     * Este método não possui parâmetros e não retorna nenhum valor.
     * 
     * Este método não lança exceções.
     */
    void switchPlayer();

    /**
     * @brief Verifica se o movimento (x, y) é válido.
     * @param x Coordenada x.
     * @param y Coordenada y.
     * @return Número de peças que serão viradas, ou 0 se o movimento não for válido.
     * @throw std::out_of_range Se o movimento estiver fora dos limites do tabuleiro.
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
     * @throw std::invalid_argument Se o movimento não for válido.
     */
    void makeMove(int x, int y);

    /**
     * @brief Calcula e exibe a pontuação dos jogadores X e O.
     */
    void calculateScore();

    /**
     * @brief Verifica e exibe o resultado final do jogo.
     * @return true se o jogador X venceu, false se o jogador O venceu.
     */
    bool checkVictory();

public:
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