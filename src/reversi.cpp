#include "../include/reversi.hpp"

using namespace std;

ReversiGame::ReversiGame() : Board(8, 8), sumX(2), sumO(2), hintsO(5), hintsX(5), currentPlayer(PLAYER_X) {
    _board[3][3].setValue(PLAYER_X);
    _board[4][3].setValue(PLAYER_O);
    _board[3][4].setValue(PLAYER_O);
    _board[4][4].setValue(PLAYER_X);
}

void ReversiGame::switchPlayer() {
    currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int ReversiGame::validMove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || _board[x][y].getValue() != EMPTY) {
        return 0;
    }

    int opponent = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    int totalFlips = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx, ny = y + dy;
            int flips = 0;
            bool foundOpponent = false;

            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && _board[nx][ny].getValue() == opponent) {
                foundOpponent = true;
                nx += dx;
                ny += dy;
                flips++;
            }

            if (foundOpponent && nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && _board[nx][ny].getValue() == currentPlayer) {
                totalFlips += flips;
            }
        }
    }

    return totalFlips;
}


vector<pair<int, int>> ReversiGame::help() {
    vector<pair<int, int>> validMoves;
    for (int a = 0; a < 8; ++a) {
        for (int b = 0; b < 8; ++b) {
            if (validMove(a, b)) {
                validMoves.push_back({ a, b });
            }
        }
    }
    return validMoves;
}

vector<pair<pair<int, int>, int>> ReversiGame::hint() {
    vector<pair<pair<int, int>, int>> hints;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (_board[i][j].getValue() == EMPTY) {
                int flips = validMove(i, j);
                if (flips > 0) {
                    hints.push_back({ {i, j}, flips });
                }
            }
        }
    }
    return hints;
}

void ReversiGame::makeMove(int x, int y) {
    if (validMove(x, y) > 0) {
        _board[x][y].setValue(currentPlayer);
        int opponent = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;

                int nx = x + dx, ny = y + dy;
                bool foundOpponent = false;
                while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && _board[nx][ny].getValue() == opponent) {
                    foundOpponent = true;
                    nx += dx;
                    ny += dy;
                }
                if (foundOpponent && nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && _board[nx][ny].getValue() == currentPlayer) {
                    while (nx != x || ny != y) {
                        nx -= dx;
                        ny -= dy;
                        _board[nx][ny].setValue(currentPlayer);
                    }
                }
            }
        }

        calculateScore();
        switchPlayer();

    }
    else {
        cout << YELLOW_COLOR << "Movimento invalido!" << RESET_ALL << endl;
    }
}

void ReversiGame::calculateScore() {
    sumX = 0;
    sumO = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (_board[i][j].getValue() == PLAYER_X) {
                sumX++;
            }
            else if (_board[i][j].getValue() == PLAYER_O) {
                sumO++;
            }
        }
    }
    cout << "\nPontuacao X: " << sumX << endl;
    cout << "Pontuacao O: " << sumO << endl;
}

Player* ReversiGame::play(Player* player1, Player* player2) {
    Player* currentPlayerPtr = player1;
    Player* otherPlayerPtr = player2;

    string player1Nickname = player1->getNickname();
    string player2Nickname = player2->getNickname();

    int size1 = player1Nickname.size();
    int size2 = player2Nickname.size();

    int size = (size1 >= size2) ? size1 : size2;

    while (sumX + sumO < 64) {
        cout << endl;
        cout << setw(size) << left << player1Nickname << ": (" << RED_COLOR << "X" << RESET_ALL << ")" << endl;
        cout << setw(size) << left << player2Nickname << ": (" << YELLOW_COLOR << "O" << RESET_ALL << ")\n" << endl;

        Board::printBoard();

        int x, y;
        string line;

        cout << (currentPlayerPtr == player1 ? player1Nickname : player2Nickname) << ": insira [linha coluna]; 'help' para ajuda; 'hint' para dica; 'sair' para voltar ao menu de jogos: " << endl;
        getline(cin, line);

        if (line == "help") {
            vector<pair<int, int>> moves = help();
            cout << "\n" << GREEN_COLOR << "Jogadas validas:" << RESET_ALL << endl;
            for (const auto& move : moves) {
                cout << "[" << move.first << " " << move.second << "]" << endl;
            }
            continue;
        }
        else if (line == "hint") {
            vector<pair<pair<int, int>, int>> hints = hint();
            cout << "\n[Jogada | Pontuacao]" << endl;
            for (const auto& hint : hints) {
                cout << "[ " << hint.first.first << " " << hint.first.second
                    << "   |     " << hint.second << "    ]" << endl;
            }
            if (currentPlayerPtr == player1) {
                hintsX--;
                cout << endl;
                cout << "Voce ainda tem " << hintsX << " dicas" << endl;
            }
            else {
                hintsO--;
                cout << endl;
                cout << "Voce ainda tem " << hintsO << " dicas" << endl;
                cout << endl;
            }
            continue;
        }
        else if (line == "SAIR" || line == "sair")
            throw SIMPLE_RETURN;

        stringstream ss(line);
        if (ss >> x >> y) {
            if (validMove(x, y) > 0) {
                makeMove(x, y);
                std::swap(currentPlayerPtr, otherPlayerPtr);
            }
            else {
                cout << "\n" << YELLOW_COLOR << "Jogada invalida!" << RESET_ALL << endl;
            }
        }
        else {
            cout << "\n" << YELLOW_COLOR << "Entrada invalida! Insira [linha coluna] ou 'help' / 'hint' / 'sair'" << RESET_ALL << endl;
        }
    }

    return checkVictory(player1, player2);

}

Player* ReversiGame::checkVictory(Player* player1, Player* player2) {
    calculateScore();
    Board::printBoard();
    if (sumX > sumO) {
        cout << GREEN_COLOR << "PARABENS " << player1->getNickname() << ", VOCÊ GANHOU!" << RESET_ALL << endl;
        return player1;
    }
    else if (sumO > sumX) {
        cout << GREEN_COLOR << "PARABENS " << player2->getNickname() << ", VOCÊ GANHOU!" << RESET_ALL << endl;
        return player2;
    }
    else {
        cout << BOLD << "O jogo terminou em empate!" << RESET_ALL << endl;
        return nullptr;
    }
}