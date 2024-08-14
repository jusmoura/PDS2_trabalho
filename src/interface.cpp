#include "../include/interface.hpp"

using namespace std;

void Interface::mainMenu() {
    cout << "\n=== Bem vindo(a) ao Hub de Jogos de Tabuleiro! ===" << endl;

    int input = 0;
    while (input != SAIR) {
        try {
            cout << "\nMENU PRINCIPAL:\n\n";
            cout << "    1 - Gerenciar jogadores" << endl;
            cout << "    2 - Jogar!" << endl;
            cout << "    9 - Sair do programa" << endl;
            cout << "\nDigite o indice da opcao desejada: ";
            cin >> input;

            switch (input) {
            case 1:
                playersMenu();
                break;

            case 2:
                gamesMenu();
                break;

            case SAIR:
                throw SAIR;
                break;

            default:
                cout << "\n" << YELLOW_COLOR << "\nOpcao nao cadastrada. Tente novamente!" << RESET_COLOR << endl;
            }

            //Tratamento para casos em que a entrada é inválida (letras, por exemplo)
            cin.clear();
            string buffer;
            getline(cin, buffer);
        }
        catch (int value) {
            if (value == SAIR)
                endProcess();
        }
        catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
        }
    }
}

void Interface::playersMenu() {
    int input = 0;

    while (input != SAIR) {
        cout << "\nGerenciando jogadores...\n\n";
        cout << "    1 - Criar jogador" << endl;
        cout << "    2 - Remover jogador" << endl;
        cout << "    3 - Listar jogadores ordenados pelo NOME" << endl;
        cout << "    4 - Listar jogadores ordenados pelo APELIDO" << endl;
        cout << "    8 - Voltar" << endl;
        cout << "    9 - Sair do programa" << endl;
        cout << "\nDigite o indice da opcao desejada: ";
        cin >> input;

        switch (input) {
        case 1:
        {
            string name, nickname;
            cout << "\nDigite o nome do novo jogador: ";
            cin >> name;
            cout << "Digite o apelido do novo jogador: ";
            cin >> nickname;
            Player newPlayer(name, nickname);

            bool inserted = controller->insertNewPlayer(newPlayer);

            if (inserted)
                cout << "\nJogador " << nickname << " criado com sucesso!" << endl;

            else
                cout << "\nJogador com apelido " << nickname << " ja cadastrado! Tente novamente!" << endl;

        } break;

        case 2:
        {
            string nickname;
            cout << "\nDigite o apelido do jogador a ser removido: ";
            cin >> nickname;

            bool removed = controller->removePlayer(nickname);

            if (removed)
                cout << "\nJogador " << nickname << " removido com sucesso!" << endl;

            else
                cout << "\nJogador com apelido \"" << nickname << "\" nao encontrado! Tente novamente!" << endl;

        } break;

        case 3:
            controller->printPlayersByName();
            break;

        case 4:
            controller->printPlayersByNickname();
            break;

        case VOLTAR:
            return;

        case SAIR:
            throw SAIR;
            break;

        default:
            cout << "\n" << YELLOW_COLOR << "\nOpcao nao cadastrada. Tente novamente!" << RESET_COLOR << endl;
            break;
        }

        //Tratamento para casos em que a entrada é inválida (letras, por exemplo)
        cin.clear();
        string buffer;
        getline(cin, buffer);
    }

}

void Interface::showSelectPlayerMenu(string player) {
    cout << "\n" << player << ": Entre em um perfil ja cadastrado ou crie um novo" << endl;
    cout << "Selecione:\n\n";
    cout << "    1 - Entrar\n";
    cout << "    2 - Criar jogador\n";
    cout << "    8 - Voltar\n";
    cout << "    9 - Sair do programa\n";
    cout << "\nDigite o indice da opcao desejada: ";
}

void Interface::gamesMenu() {
    // int playerMenuInput = 0;
    // while (playerMenuInput != VOLTAR && playerMenuInput != SAIR) {
    //     showSelectPlayerMenu("Jogador 1");
    //     cin >> playerMenuInput;

    //     switch (playerMenuInput) {
    //     case 1:
    //     {
    //         string nickname;
    //         cout << "\nDigite o apelido do jogador 1: ";
    //         cin >> nickname;
    //         player1 = controller->getPlayerByNickname(nickname);

    //         if (player1 == nullptr) {
    //             cout << "Tente novamente!" << endl;
    //             break;
    //         }
    //         else {
    //             cout << "\nBem vindo(a), " << player1->getName() << "!\n\n";
    //             showSelectPlayerMenu("Jogador 2");
    //             cin >> playerMenuInput;
    //         }
    //     } break;
    //     case 2:
    //         gamesMenu();
    //         break;
    //     case VOLTAR:
    //         throw VOLTAR;
    //     case SAIR:
    //         throw SAIR;
    //         break;
    //     default:
    //         cout << "\n\nOpcao nao cadastrada. Tente novamente!" << endl;
    //         break;
    //     }

    //     //Tratamento para casos em que a entrada é inválida (letras, por exemplo)
    //     cin.clear();
    //     string buffer;
    //     getline(cin, buffer);
    // }

    Player* player1 = controller->getPlayerByNickname("Dani");
    Player* player2 = controller->getPlayerByNickname("jusmoura");
    Player* winner;

    int input = 0;
    while (input != 8 && input != 9) {
        cout << "\nJogos disponíveis:\n\n";
        cout << "    0 - Reversi\n";
        cout << "    1 - Lig4\n";
        cout << "    2 - Jogo da Velha\n";
        cout << "    3 - Campo Minado\n";
        cout << "    4 - Damas\n";
        cout << "    8 - Voltar\n";
        cout << "    9 - Sair do programa\n";

        cout << "\n========================================\n\nDigite o indice do jogo que deseja jogar: ";
        cin >> input;

        switch (input) {
        case REVERSI:
        {
            cout << "\nReversi" << endl;
            ReversiGame reversiGame;
            winner = reversiGame.play(player1, player2);
            if (winner == player1) {
                player1->addWin(REVERSI);
                player2->addDefeat(REVERSI);
            }
            else if (winner == player2) {
                player2->addWin(REVERSI);
                player1->addDefeat(REVERSI);
            }
            else {
                cout << "Empate!" << endl;
            }
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
            Player* playerWon;
            Minesweeper mine(8, 8);
            winner = mine.play(player1);
            if (winner == player1)
                player1->addWin(MINESWEEPER);

            else
                player1->addDefeat(MINESWEEPER);

            cout << "\nEncerrando campo minado...\n\n";
        } break;

        case CHECKERS:
        {
            cout << "\nDamas" << endl;
            /* code */
        } break;

        case VOLTAR: //Voltar
            mainMenu();
            break;

        case SAIR: //Sair do programa
            throw SAIR;
            break;

        default:
            cout << "\n" << YELLOW_COLOR << "\nOpcao nao cadastrada. Tente novamente!" << RESET_COLOR << endl;
            break;
        }

        //Tratamento para casos em que a entrada é inválida (letras, por exemplo)
        cin.clear();
        string buffer;
        getline(cin, buffer);
    }
}

void Interface::endProcess() {
    controller->endProcess();
    delete controller;
    cout << "\nSaindo...\n" << endl;
    throw "ENCERRAR";
}