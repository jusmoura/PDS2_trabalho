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
            removePlayer();
            break;

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
    while (1) {
        try {
            Player* player1 = loginPlayer("JOGADOR 1");
            cout << "\n" << GREEN_COLOR << "Bem vindo(a), " << player1->getName() << "!" << RESET_ALL << endl;
            clearBuffer();

            Player* player2 = nullptr;

            while (1) {
                //Verificação caso o jogador 2 já esteja "logado"
                if (player2 != nullptr) {
                    cout << "Jogador 1: " << player1->getNickname() << endl;
                    cout << "Jogador 2: " << player2->getNickname() << endl;

                    cout << "\nDeseja continuar com os mesmos jogadores (S/N)? ";
                    char input;
                    cin >> input;

                    switch (input) {
                    case 'N':
                    case 'n':
                        throw "RETURN";
                        break;

                    case 'S':
                    case 's':
                        break;

                    default:
                        cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Continuando com os mesmos jogadores..." << RESET_ALL << endl;
                        break;
                    }

                    clearBuffer();
                }

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
                int input;
                cin >> input;

                clearBuffer();
                switch (input) {
                case REVERSI:
                {
                    player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                    cout << "\n" << BLUE_COLOR << "Reversi" << RESET_ALL << endl;

                    cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
                    // ReversiGame reversiGame;
                    // winner = reversiGame.play(player1, player2);

                    // if (winner == player1) {
                    //     player1->addWin(REVERSI);
                    //     player2->addDefeat(REVERSI);
                    // }
                    // else if (winner == player2) {
                    //     player2->addWin(REVERSI);
                    //     player1->addDefeat(REVERSI);
                    // }
                    // else {
                    //     player1->addDraw(REVERSI);
                    //     player2->addDraw(REVERSI);
                    // }
                    cout << "\n" << GRAY_COLOR << "Encerrando Reversi...\n" << RESET_ALL << endl;

                } break;

                case LIG4:
                {
                    cout << "\n" << BLUE_COLOR << "Lig4" << RESET_ALL << endl;

                    player2 = playerLoginVerification(player1, player2, "JOGADOR 2");
                    cout << "PRINTANDOO" << player2->getNickname() << endl;

                    cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
                    // Lig4 lig4;
                    // winner = lig4.play(player1, player2);

                    // if (winner == player1) {
                    //     player1->addWin(LIG4);
                    //     player2->addDefeat(LIG4);
                    // }
                    // else if (winner == player2) {
                    //     player2->addWin(LIG4);
                    //     player1->addDefeat(LIG4);
                    // }
                    // else {
                    //     player1->addDraw(LIG4);
                    //     player2->addDraw(LIG4);
                    // }
                    cout << "\n" << GRAY_COLOR << "Encerrando Lig4...\n" << RESET_ALL << endl;

                } break;

                case TIC_TAC_TOE:
                {
                    cout << "\n" << BLUE_COLOR << "Jogo da Velha" << RESET_ALL << endl;

                    player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                    cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
                    // TicTacToe ticTacToe;
                    // winner = ticTacToe.play(player1, player2);

                    // if (winner == player1) {
                    //     player1->addWin(TIC_TAC_TOE);
                    //     player2->addDefeat(TIC_TAC_TOE);
                    // }
                    // else if (winner == player2) {
                    //     player2->addWin(TIC_TAC_TOE);
                    //     player1->addDefeat(TIC_TAC_TOE);
                    // }
                    // else {
                    //     player1->addDraw(TIC_TAC_TOE);
                    //     player2->addDraw(TIC_TAC_TOE);
                    // }
                    cout << "\n" << GRAY_COLOR << "Encerrando Jogo da Velha...\n" << RESET_ALL << endl;

                } break;

                case MINESWEEPER:
                {
                    cout << "\n" << BLUE_COLOR << "Campo Minado" << RESET_ALL << endl;

                    cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
                    // Minesweeper mine(8, 8);
                    // winner = mine.play(player1);

                    // if (winner == player1)
                    //     player1->addWin(MINESWEEPER);

                    // else
                    //     player1->addDefeat(MINESWEEPER);

                    cout << "\n" << GRAY_COLOR << "Encerrando Campo Minado...\n" << RESET_ALL << endl;
                } break;

                case CHECKERS:
                {
                    cout << "\n" << BLUE_COLOR << "Damas" << RESET_ALL << endl;

                    player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                    cout << ">>>>>>>>>>INICIANDO O JOGO <<<<<<<<<" << endl;
                    // CheckersGame checkersGame;
                    // winner = checkersGame.play(player1, player2);
                    // if (winner == player1) {
                    //     player1->addWin(CHECKERS);
                    //     player2->addDefeat(CHECKERS);
                    // }
                    // else if (winner == player2) {
                    //     player2->addWin(CHECKERS);
                    //     player1->addDefeat(CHECKERS);
                    // }
                    cout << "\n" << GRAY_COLOR << "Encerrando Damas...\n" << RESET_ALL << endl;

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
            }
        }
        catch (const char* e) {
            if (e != "RETURN")
                throw;
        }
    }
}

Player* Interface::createPlayer() {
    clearBuffer();

    string name, nickname;
    cout << "\nDigite o nome do novo jogador: ";
    getline(cin, name);
    cout << "Digite o apelido do novo jogador: ";
    cin >> nickname;
    Player* newPlayer = new Player(name, nickname);

    bool inserted = controller->insertNewPlayer(newPlayer);

    if (inserted) {
        cout << "\n" << GREEN_COLOR << "Jogador " << nickname << " criado com sucesso!" << RESET_ALL << endl;
        return newPlayer;
    }

    else {
        cout << "\n" << RED_COLOR << "Jogador com apelido " << nickname << " ja cadastrado! Tente novamente!" << RESET_ALL << endl;
        return nullptr;
    }
}

void Interface::removePlayer() {
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
}

Player* Interface::loginPlayer(string playerNumber) {
    int input = 0;
    while (1) {
        cout << "\n" << BOLD << playerNumber << RESET_ALL << ", entre em um perfil ja existe ou crie um novo jogador:\n" << endl;
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
            else
                return player;

        } break;

        case 2:
        {
            Player* player = createPlayer();
            if (player != nullptr)
                return player;
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

Player* Interface::playerLoginVerification(Player* player1, Player* player2, string playerNumber) {
    if (player2 == nullptr) {
        player2 = loginPlayer(playerNumber);
        clearBuffer();

        if (player1 == player2) {
            cout << "\n" << RED_COLOR << "Jogador com apelido \"" << player1->getNickname() << "\" ja selecionado! Tente novamente!" << RESET_ALL << endl;
            throw "RETURN";
        }
        else {
            cout << "\n" << GREEN_COLOR << "Bem vindo(a), " << player2->getName() << "!" << RESET_ALL << endl;
            return player2;
        }
    }
    else
        return player2;
}

void Interface::clearBuffer() {
    string buffer;
    getline(cin, buffer);
    cin.clear();
}

void Interface::endProcess() {
    delete controller;
    cout << "\nSaindo...\n" << endl;
    throw "CLOSE_PROGRAM";
}