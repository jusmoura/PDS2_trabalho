/**
 * @file interface.hpp
 * @brief Declaração da classe Interface para gerenciar a interação com o usuário e a instanciação de todas as funcionalidades do projeto.
 *
 * Este arquivo define a classe `Interface`, que fornece métodos para interagir com o usuário,
 * incluindo menus para gerenciar jogadores e jogos, criar e remover jogadores, e realizar o login dos jogadores,
 * iniciar jogos e agrupar todo o fluxo do projeto.
 */
#ifndef INTERFACE_H
#define INTERFACE_H

#include "player_controller.hpp"
#include "minesweeper.hpp"
#include "reversi.hpp"
#include "lig4.hpp"
#include "tic_tac_toe.hpp"
#include "checkers.hpp"

#include <iostream>

 /**
  * @brief Contante para padronizar a opção de 'Voltar' durante o fluxo dos menus.
  */
const int VOLTAR = 8;
/**
 * @brief Contante para padronizar a opção de 'Sair' durante o fluxo dos menus.
 */
const int SAIR = 9;
/**
 * @class Interface
 * @brief Gerencia a interação com o usuário através de menus e operações relacionadas a jogadores e jogos.
 *
 * A classe `Interface` fornece métodos para exibir menus, criar e remover jogadores, realizar login de jogadores,
 * e gerenciar a interação geral com o usuário. Ela se comunica indiretamente com todas as outras classes,
 * possibilitando gerenciar os jogos e os players.
 */
class Interface {
private:

    /**
     * @brief Ponteiro para o controlador de jogadores.
     *
     * Usado para gerenciar e acessar informações sobre todos os jogadores.
     */
    PlayerController* controller = new PlayerController();
public:

    /**
     * @brief Exibe o menu principal e gerencia a navegação para outros menus.
     *
     * Este método exibe o menu principal e lida com a seleção do usuário para acessar diferentes opções,
     * como gerenciar jogadores ou iniciar jogos.
     */
    void mainMenu();

    /**
     * @brief Exibe o menu de jogadores e gerencia operações relacionadas aos jogadores.
     *
     * Este método exibe o menu para criar, remover e exibir jogadores.
     */
    void playersMenu();

    /**
     * @brief Exibe o menu de jogos e gerencia a seleção de jogos disponíveis.
     *
     * Este método exibe o menu para escolher entre os jogos disponíveis e iniciar um jogo selecionado.
     */
    void gamesMenu();

    /**
     * @brief Cria um novo jogador.
     *
     * Método auxiliar que solicita ao usuário as informações necessárias para criar um novo jogador e o adiciona ao controlador
     * de jogadores.
     *
     * @return Um ponteiro para o jogador recém-criado.
     */
    Player* createPlayer();

    /**
     * @brief Remove um jogador existente.
     *
     * Método auxiliar que solicita ao usuário as informações necessárias para identificar e remover um jogador existente do controlador
     * de jogadores.
     */
    void removePlayer();
    /**
     * @brief Realiza o login de um jogador.
     *
     * Método auxiliar que solicita ao usuário o número do jogador para realizar o login e retorna um ponteiro para o jogador correspondente.
     *
     * @param playerNumber Jogador que irá realizar o login (player 1 ou player 2).
     * @return Um ponteiro para o jogador que fez login.
     */
    Player* loginPlayer(std::string playerNumber);

    /**
     * @brief Verifica o login de um jogador.
     *
     * Verifica se o jogador com o número fornecido já está 'logado' e retorna o jogador correspondente.
     *
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     * @param playerNumber O número do jogador a ser verificado.
     * @return Um ponteiro para o jogador correspondente.
     */
    Player* playerLoginVerification(Player* player1, Player* player2, std::string playerNumber);

    /**
     * @brief Limpa o buffer de entrada.
     *
     * Remove qualquer entrada residual do buffer de entrada para evitar problemas de leitura em métodos subsequentes.
     */
    void clearBuffer();

    /**
     * @brief Encerra o processo atual e limpa recursos.
     *
     * Este método finaliza o processo atual, limpa recursos alocados e realiza qualquer operação de encerramento necessária.
     */
    void endProcess();
};

#endif //INTERFACE_H