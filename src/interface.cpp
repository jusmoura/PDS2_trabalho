#include "../include/interface.hpp"

using namespace std;

void Interface::mainMenu() {
    cout << "\n" << MAIN_TITLE_STYLE << "=== Bem vindo(a) ao Hub de Jogos de Tabuleiro! ===" << RESET_ALL << endl;

    while (1) {
        try {
            cout << "\n" << BLUE_COLOR << "MENU PRINCIPAL:\n\n" << RESET_ALL;
            cout << "    1 - Gerenciar jogadores" << endl;
            cout << "    2 - Jogar!" << endl;
            cout << "    9 - Sair do programa" << endl;
            cout << "\nDigite o indice da opcao desejada: ";

            int option;
            string input;
            getline(cin, input);

            stringstream ss(input);
            if (ss >> option) {
                switch (option) {
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
            }
            else
                cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
        }
        //Catch para capturar o retorno do jogador para o menu principal ou encerrar o programa
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
    while (1) {
        cout << "\n" << BLUE_COLOR << "Gerenciando jogadores...\n\n" << RESET_ALL;
        cout << "    1 - Criar jogador" << endl;
        cout << "    2 - Remover jogador" << endl;
        cout << "    3 - Listar jogadores ordenados pelo NOME" << endl;
        cout << "    4 - Listar jogadores ordenados pelo APELIDO" << endl;
        cout << "    8 - Voltar" << endl;
        cout << "    9 - Sair do programa" << endl;
        cout << "\nDigite o indice da opcao desejada: ";

        int option;
        string input;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> option) {
            switch (option) {
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
        }
        else
            cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
    }
}

void Interface::gamesMenu() {
    cout << "\n" << BLUE_COLOR << "Jogar!" << RESET_ALL << endl;
    while (1) {
        try {
            Player* player1 = loginPlayer("JOGADOR 1");
            cout << "\n" << GREEN_COLOR << "Bem vindo(a), " << player1->getName() << "!" << RESET_ALL << endl;

            Player* player2 = nullptr;

            while (1) {
                try {
                    //Verificação caso o jogador 2 já esteja "logado"
                    if (player2 != nullptr) {
                        cout << "\nJogador 1: " << player1->getNickname() << endl;
                        cout << "Jogador 2: " << player2->getNickname() << endl;

                        cout << "\nDeseja continuar com os mesmos jogadores (S/N)? ";

                        char option;
                        string input;
                        getline(cin, input);

                        stringstream ss(input);
                        if (ss >> option) {
                            switch (option) {
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
                        }
                        else
                            cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
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

                    int selectedGame;
                    string input;
                    getline(cin, input);

                    stringstream ss(input);
                    if (ss >> selectedGame) {
                        switch (selectedGame) {
                        case REVERSI:
                        {
                            player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                            cout << "\n" << BLUE_COLOR << "Reversi" << RESET_ALL << endl;

                            ReversiGame reversiGame;
                            winner = reversiGame.play(player1, player2);

                            controller->victoryAndDefeatManagement(winner, player1, player2, selectedGame);

                            cout << "\n" << GRAY_COLOR << "Encerrando Reversi..." << RESET_ALL << endl;

                        } break;

                        case LIG4:
                        {
                            cout << "\n" << BLUE_COLOR << "Lig4" << RESET_ALL << endl;

                            player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                            Lig4 lig4;
                            winner = lig4.play(player1, player2);

                            controller->victoryAndDefeatManagement(winner, player1, player2, selectedGame);

                            cout << "\n" << GRAY_COLOR << "Encerrando Lig4..." << RESET_ALL << endl;

                        } break;

                        case TIC_TAC_TOE:
                        {
                            cout << "\n" << BLUE_COLOR << "Jogo da Velha" << RESET_ALL << endl;

                            player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                            TicTacToe ticTacToe;
                            winner = ticTacToe.play(player1, player2);

                            controller->victoryAndDefeatManagement(winner, player1, player2, selectedGame);

                            cout << "\n" << GRAY_COLOR << "Encerrando Jogo da Velha..." << RESET_ALL << endl;

                        } break;

                        case MINESWEEPER:
                        {
                            cout << "\n" << BLUE_COLOR << "Campo Minado" << RESET_ALL << endl;

                            Minesweeper minesweeper;
                            winner = minesweeper.play(player1);

                            if (winner == player1)
                                player1->addWin(MINESWEEPER);

                            else
                                player1->addDefeat(MINESWEEPER);

                            cout << "\n" << GRAY_COLOR << "Encerrando Campo Minado..." << RESET_ALL << endl;
                        } break;

                        case CHECKERS:
                        {
                            cout << "\n" << BLUE_COLOR << "Damas" << RESET_ALL << endl;

                            player2 = playerLoginVerification(player1, player2, "JOGADOR 2");

                            CheckersGame checkersGame;
                            winner = checkersGame.play(player1, player2);

                            controller->victoryAndDefeatManagement(winner, player1, player2, selectedGame);

                            cout << "\n" << GRAY_COLOR << "Encerrando Damas..." << RESET_ALL << endl;

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
                    else
                        cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
                }
                //Catch para capturar o retorno do jogador caso ele decida sair de um jogo prematuramente
                catch (int value) {
                    if (value != SIMPLE_RETURN)
                        throw;
                }
            }
        }
        //Catch para capturar o retorno do jogador caso ele decida voltar durante o fluxo de menus de jogos
        catch (const char* e) {
            if (e != "RETURN")
                throw;
        }
    }
}

Player* Interface::createPlayer() {
    string name, nickname;
    cout << "\nDigite o nome do novo jogador: ";
    getline(cin, name);
    cout << "Digite o apelido do novo jogador: ";
    cin >> nickname;
    clearBuffer();

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
    string nickname;
    cout << "\nDigite o apelido do jogador a ser removido: ";
    cin >> nickname;
    clearBuffer();

    int removed = controller->removePlayer(nickname);

    if (removed == 1)
        cout << "\n" << GREEN_COLOR << "Jogador " << nickname << " removido com sucesso!" << RESET_ALL << endl;

    else if (removed == -1)
        cout << "\n" << RED_COLOR << "Jogador com apelido \"" << nickname << "\" nao encontrado! Tente novamente!" << RESET_ALL << endl;

    else
        cout << "\n" << RED_COLOR << "Nenhum jogador cadastrado! Tente novamente!" << RESET_ALL << endl;
}

Player* Interface::loginPlayer(string playerNumber) {
    while (1) {
        cout << "\n" << BOLD << playerNumber << RESET_ALL << ", entre em um perfil ja existe ou crie um novo jogador:\n" << endl;
        cout << "    1 - Entrar" << endl;
        cout << "    2 - Criar jogador" << endl;
        cout << "    8 - Voltar" << endl;
        cout << "    9 - Sair do programa" << endl;
        cout << "\nDigite o indice da opcao desejada: ";

        int option;
        string input;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> option) {
            switch (option) {
            case 1:
            {
                string nickname;
                cout << "\nDigite o apelido do " << playerNumber << ": ";
                cin >> nickname;
                clearBuffer();

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
        }
        else
            cout << "\n" << YELLOW_COLOR << "Opcao nao cadastrada. Tente novamente!" << RESET_ALL << endl;
    }
}

Player* Interface::playerLoginVerification(Player* player1, Player* player2, string playerNumber) {
    if (player2 == nullptr) {
        player2 = loginPlayer(playerNumber);

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
    throw "CLOSE_PROGRAM";
}