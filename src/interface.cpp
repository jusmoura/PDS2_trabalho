#include "../include/interface.hpp"

using namespace std;

void Interface::mainMenu() {
    cout << "\n" << MAIN_TITLE_STYLE << "=== Bem vindo(a) ao Hub de Jogos de Tabuleiro! ===" << RESET_ALL << endl;

    int input = 0;
    while (input != SAIR) {
        try {
            cout << "\n" << BLUE_COLOR << "MENU PRINCIPAL:\n\n" << RESET_ALL;
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
                cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
            }

            clearBuffer();
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
    clearBuffer();

    int input = 0;

    while (input != SAIR) {
        cout << "\n" << BLUE_COLOR << "Gerenciando jogadores...\n\n" << RESET_ALL;
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
            createPlayer();
            break;

        case 2:
        {
            clearBuffer();

            string nickname;
            cout << "\nDigite o apelido do jogador a ser removido: ";
            cin >> nickname;

            int removed = controller->removePlayer(nickname);

            if (removed == 1)
                cout << "\n" << GREEN_COLOR << "Jogador " << nickname << " removido com sucesso!" << RESET_ALL << endl;

            else if (removed == -1)
                cout << "\n" << RED_COLOR << "Jogador com apelido \"" << nickname << "\" nao encontrado! Tente novamente!" << RESET_ALL << endl;

            else
                cout << "\n" << RED_COLOR << "Nenhum jogador cadastrado! Tente novamente!" << RESET_ALL << endl;

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
            cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
            break;
        }

        clearBuffer();
    }
}

void Interface::gamesMenu() {
    clearBuffer();

    cout << "\n" << BLUE_COLOR << "Jogar!" << RESET_ALL << endl;

    Player* player1 = loginPlayer("JOGADOR 1");

    int input = 0;
    while (input != VOLTAR) {

        Player* player2;
        Player* winner;

        cout << "\n" << BLUE_COLOR << "Jogos disponiveis:\n\n" << RESET_ALL;
        cout << "    0 - Reversi\n";
        cout << "    1 - Lig4\n";
        cout << "    2 - Jogo da Velha\n";
        cout << "    3 - Campo Minado\n";
        cout << "    4 - Damas\n";
        cout << "    8 - Voltar" << endl;
        cout << "    9 - Sair do programa" << endl;
        cout << "\nDigite o indice do jogo que quer jogar: ";
        cin >> input;

        switch (input) {
        case REVERSI:
        {
            cout << "\nReversi" << endl;

            player2 = loginPlayer("JOGADOR 2");
            cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;

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

            player2 = loginPlayer("JOGADOR 2");
            cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
            /* code */
        } break;

        case TIC_TAC_TOE:
        {
            cout << "\nJogo da Velha" << endl;

            player2 = loginPlayer("JOGADOR 2");
            cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
            /* code */
        } break;

        case MINESWEEPER:
        {
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

            player2 = loginPlayer("JOGADOR 2");
            cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;

            CheckersGame checkersGame;

            /*ALTERAR O CHECKERS PARA RETORNAR O VENCEDOR*/
            winner = checkersGame.play(player1, player2);
            if (winner == player1) {
                player1->addWin(CHECKERS);
                player2->addDefeat(CHECKERS);
            }
            else if (winner == player2) {
                player2->addWin(CHECKERS);
                player1->addDefeat(CHECKERS);
            }
        } break;

        case VOLTAR: //Voltar
            throw VOLTAR;
            break;

        case SAIR: //Sair do programa
            throw SAIR;
            break;

        default:
            cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
            break;
        }

        clearBuffer();
    }
}

string Interface::createPlayer() {
    clearBuffer();

    string name, nickname;
    cout << "\nDigite o nome do novo jogador: ";
    getline(cin, name);
    cout << "Digite o apelido do novo jogador: ";
    cin >> nickname;
    Player newPlayer(name, nickname);

    bool inserted = controller->insertNewPlayer(newPlayer);

    if (inserted) {
        cout << "\n" << GREEN_COLOR << "Jogador " << nickname << " criado com sucesso!" << RESET_ALL << endl;
        return nickname;
    }

    else {
        cout << "\n" << RED_COLOR << "Jogador com apelido " << nickname << " ja cadastrado! Tente novamente!" << RESET_ALL << endl;
        return "";
    }
}

Player* Interface::loginPlayer(string playerNumber) {
    int input = 0;
    while (1) {
        cout << "\nAntes de jogar, " << BOLD << playerNumber << RESET_ALL << ", entre em um perfil ja existe ou crie um novo jogador:\n" << endl;
        cout << "    1 - Entrar" << endl;
        cout << "    2 - Criar jogador" << endl;
        cout << "    8 - Voltar" << endl;
        cout << "    9 - Sair do programa" << endl;
        cout << "\nDigite o indice da opcao desejada: ";
        cin >> input;

        switch (input) {
        case 1:
        {
            clearBuffer();

            string nickname;
            cout << "\nDigite o apelido do " << playerNumber << ": ";
            cin >> nickname;
            Player* player = controller->getPlayerByNickname(nickname);

            if (player == nullptr) {
                cout << "\n" << RED_COLOR << "Jogador com apelido \"" << nickname << "\" nao encontrado! Tente novamente!" << RESET_ALL << endl;
                break;
            }
            else {
                cout << "\n" << GREEN_COLOR << "Bem vindo(a), " << player->getName() << "!" << RESET_ALL << endl;
                return player;
            }

        } break;

        case 2:
        {
            string nickname = createPlayer();

            if (nickname != "") {
                return controller->getPlayerByNickname(nickname);
            }

        } break;

        case VOLTAR:
            throw VOLTAR;
            break;

        case SAIR:
            throw SAIR;
            break;

        default:
            cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
            break;
        }

        clearBuffer();
    }
}

void Interface::clearBuffer() {
    cin.clear();
    string buffer;
    getline(cin, buffer);
}

void Interface::endProcess() {
    controller->endProcess();
    delete controller;
    cout << "\nSaindo...\n" << endl;
    throw "ENCERRAR";
}