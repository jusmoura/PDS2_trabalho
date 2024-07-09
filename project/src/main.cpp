#include "../include/player_controller.hpp"
#include "../include/minesweeper.hpp"

#include <iostream>

int main() {
    PlayerController* controller = new PlayerController();

    Player* player = controller->getPlayerByNickname("Dani");

    //Player não existe
    if (player == nullptr)
        return 1;

    else {
        //MENU - IMPLEMENTAR INTERFACE (classe separada) QUE GERENCIA EXIBIÇÕES, CONTROLLERS, GAMES E PLAYERS

        cout << "\n--- Bem vindo(a) ao Pixel Patterns, o seu hub de jogos de tabuleiro! ---" << endl;
        cout << "\nJogos disponíveis:\n\n";
        cout << "    0 - Reversi\n";
        cout << "    1 - Lig4\n";
        cout << "    2 - Jogo da Velha\n";
        cout << "    3 - Campo Minado\n";
        cout << "    9 - Sair\n";

        cout << "\n========================================\n\nDigite o numero do jogo que deseja jogar: ";
        int menuInput;
        cin >> menuInput;
        /*
        TRATAR OPÇÃO NÃO CADASTRADA ANTES DO SWITCH
        */

        while (menuInput != 9) {
            cout << "\n---Digite o tamanho do tabuleiro: ";
            int size;
            cin >> size;

            bool playerWon;

            switch (menuInput) {
            case REVERSI:
            {
                cout << "\nReversi" << endl;
                /* code */
            } break;

            case LIG4:
            {
                cout << "\nLig4" << endl;
                /* code */
            } break;

            case TIC_TAC_TOE:
            {
                cout << "\nJogo da Velha" << endl;
                /* code */
            } break;

            case MINESWEEPER:
            {
                Minesweeper mine = Minesweeper(size, size);
                playerWon = mine.play();
                if (playerWon)
                    player->addWin(MINESWEEPER);

                else
                    player->addDefeat(MINESWEEPER);

                cout << "\nEncerrando campo minado...\n\n";
            } break;

            default:
                cout << "Opcao nao cadastrada. Tente novamente!" << endl;
                break;
            }
            cout << "(9 - Sair)" << endl;
            cout << "\n========================================\n\nDigite o numero do jogo que deseja jogar: ";
            cin >> menuInput;
        }
        controller->endProcess();

        cout << "Saindo...\n" << endl;

        return 0;
    }
}