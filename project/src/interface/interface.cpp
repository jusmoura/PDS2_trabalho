#include "../include/interface.hpp"

using namespace std;

void Interface::mainMenu() {
    cout << "\n--- Bem vindo(a) ao Pixel Patterns, o seu hub de jogos de tabuleiro! ---" << endl;

    int input = 0;
    while (input != 3) {
        cout << "\nMENU:\n\n";
        cout << "    1 - Gerenciar jogadores" << endl;
        cout << "    2 - Jogar!" << endl;
        cout << "    3 - Sair do programa" << endl;
        cout << "Digite o numero da opcao desejada: ";
        cin >> input;

        switch (input) {
        case 1:
            playersMenu();
            break;
        case 2:
            gamesMenu();
            break;
        case 3:
            endProcess();
            break;
        default:
            cout << "Opcao nao cadastrada. Tente novamente!" << endl;
            break;
        }
    }
    return;
}

void Interface::playersMenu() {
    /*
    Listar players by name
    Listar players by nick
    Criar jogador
    Remover jogador
    */

    // cout << "    8 - Voltar\n";
    // cout << "    9 - Sair do programa\n";
    //    if (menuInput == 8)
    //         mainMenu();
    //     else if (menuInput == 9)
    //         endProcess();
}

void Interface::gamesMenu() {

    //Digite o apelido do jogador 1
    //
    //Digite o apelido do jogador 2
    Player* player = controller->getPlayerByNickname("Dani");

    //Player não existe
    if (player == nullptr)
        return;

    int menuInput = 0;
    while (menuInput != 8 && menuInput != 9) {

        cout << "\nJogos disponíveis:\n\n";
        cout << "    0 - Reversi\n";
        cout << "    1 - Lig4\n";
        cout << "    2 - Jogo da Velha\n";
        cout << "    3 - Campo Minado\n";
        cout << "    4 - Damas\n";
        cout << "    8 - Voltar\n";
        cout << "    9 - Sair do programa\n";

        cout << "\n========================================\n\nDigite o numero do jogo que deseja jogar: ";
        cin >> menuInput;

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

        case CHECKERS:
        {
            cout << "\nDamas" << endl;
            /* code */
        } break;

        case 8: //Voltar
            mainMenu();
            break;

        case 9: //Sair do programa
            endProcess();
            break;

        default:
            cout << "Opcao nao cadastrada. Tente novamente!" << endl;
            break;
        }
    }
}

void Interface::endProcess() {
    controller->endProcess();
    cout << "Saindo...\n" << endl;
    return;
}