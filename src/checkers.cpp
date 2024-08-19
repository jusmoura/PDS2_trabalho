#include "../include/checkers.hpp"

CheckersGame::CheckersGame() : Board(8, 8) {
}

void CheckersGame::setDefaults() {
    for (int i = 0; i < 3; ++i) {
        for (int j = (i % 2 == 0) ? 1 : 0; j < 8; j += 2) {
            _board[i][j].setValue(1);
        }
    }
    for (int i = 5; i < 8; ++i) {
        for (int j = (i % 2 == 0) ? 1 : 0; j < 8; j += 2) {
            _board[i][j].setValue(2);
        }
    }
}

int CheckersGame::enemy(int piece) {
    if (piece == PLAYER_X || piece == PLAYER_X_QUEEN) {
        return 2;
    }
    if (piece == PLAYER_O || piece == PLAYER_O_QUEEN) {
        return 1;
    }
    return 0;
}

void CheckersGame::checkIfBecameQueen(int x, int y) {
    if (turn == 1) {
        if (x == 7) {
            _board[x][y].setValue(3);
        }
    }
    if (turn == 2) {
        if (x == 0) {
            _board[x][y].setValue(4);
        }
    }
}

bool CheckersGame::readMove(int x[4]) {
    string input;
    while (1) {
        std::cout << "Digite linha e coluna da peca a ser movimentada (ou 'sair' para voltar): " << std::endl;
        getline(cin, input);

        if (input == "SAIR" || input == "sair")
            throw SIMPLE_RETURN;

        stringstream ss(input);
        if (!(ss >> x[1] >> x[2])) {
            cout << "\n" << YELLOW_COLOR << "Entrada invalida! Insira [linha coluna] ou 'sair'\n" << RESET_ALL << endl;
            return false;
        }

        std::cout << "Digite linha e coluna do destino da peca (ou 'sair' para voltar): " << std::endl;
        getline(cin, input);

        if (input == "SAIR" || input == "sair")
            throw SIMPLE_RETURN;

        stringstream ss2(input);
        if (ss2 >> x[3] >> x[4])
            return validMove(x);
        else {
            cout << "\n" << YELLOW_COLOR << "Entrada invalida! Insira [linha coluna] ou 'sair'\n" << RESET_ALL << endl;
            return false;
        }
    }
}

bool CheckersGame::validMove(int x[4]) {
    if (x[1] < 0 || x[1] >= BOARD_SIZE || x[2] < 0 || x[2] > BOARD_SIZE) {
        std::cout << "\nJogada invalida 1: Coordenadas da peca invalidas.\n" << std::endl;
        return false;
    }
    else if (x[3] < 0 || x[3] >= BOARD_SIZE || x[4] < 0 || x[4] > BOARD_SIZE) {
        std::cout << "\nJogada invalida 2: Coordenadas da jogada invalidas.\n" << std::endl;
        return false;
    }
    else if (_board[x[3]][x[4]].getValue() == 1 || _board[x[3]][x[4]].getValue() == 2 || _board[x[3]][x[4]].getValue() == 3 || _board[x[3]][x[4]].getValue() == 4) {
        std::cout << "\nJogada invalida 3: Ja existe uma peca na coordenada da jogada." << std::endl;
        return false;
    }
    else if (_board[x[1]][x[2]].getValue() == 1 && x[3] < x[1]) {
        std::cout << "\nJogada invalida 4: Essa peca nao pode se movimentar para tras." << std::endl;
        return false;
    }
    else if (_board[x[1]][x[2]].getValue() == 2 && x[3] > x[1]) {
        std::cout << "\nJogada invalida 4: Essa peca nao pode se movimentar para tras." << std::endl;
        return false;
    }
    else if (turn == 1 && _board[x[1]][x[2]].getValue() == 2) {
        std::cout << "\nJogada invalida 5: Essa peca nao e sua." << std::endl;
        return false;
    }
    else if (turn == 2 && _board[x[1]][x[2]].getValue() == 1) {
        std::cout << "\nJogada invalida 5: Essa peca nao e sua." << std::endl;
        return false;
    }
    else if (turn == 1 && _board[x[1]][x[2]].getValue() == 4) {
        std::cout << "\nJogada invalida 5: Essa peca nao e sua." << std::endl;
        return false;
    }
    else if (turn == 2 && _board[x[1]][x[2]].getValue() == 3) {
        std::cout << "\nJogada invalida 5: Essa peca nao e sua." << std::endl;
        return false;
    }
    else
        return true;
}

int CheckersGame::nextChainValid(int x[4]) {
    int currentPiece = _board[x[1]][x[2]].getValue();
    int enemyPiece1 = enemy(currentPiece);
    int enemyPiece2 = enemy(currentPiece + 2);

    // Verifica as quatro diagonais adjacentes para uma peça inimiga
    if (_board[x[1] + 1][x[2] + 1].getValue() == enemyPiece1 || _board[x[1] + 1][x[2] + 1].getValue() == enemyPiece2 ||
        _board[x[1] + 1][x[2] - 1].getValue() == enemyPiece1 || _board[x[1] + 1][x[2] - 1].getValue() == enemyPiece2 ||
        _board[x[1] - 1][x[2] + 1].getValue() == enemyPiece1 || _board[x[1] - 1][x[2] + 1].getValue() == enemyPiece2 ||
        _board[x[1] - 1][x[2] - 1].getValue() == enemyPiece1 || _board[x[1] - 1][x[2] - 1].getValue() == enemyPiece2) {
        return 1;
    }
    else {
        return 0;
    }
}

bool CheckersGame::simpleMove(int x[4]) {
    return (x[3] == x[1] + 1 || x[3] == x[1] - 1) && (x[4] == x[2] + 1 || x[4] == x[2] - 1);
}

bool CheckersGame::captureMove(int x[4]) {
    if (nextChainValid(x) == 1) {
        return (x[3] == x[1] + 2 || x[3] == x[1] - 2) && (x[4] == x[2] + 2 || x[4] == x[2] - 2);
    }
    else {
        return false;
    }
}

void CheckersGame::updateBoard(int x[4]) {
    _board[x[1]][x[2]].setValue(0);
    _board[x[3]][x[4]].setValue(turn);
    int x2 = (x[1] + x[3]) / 2;
    int y2 = (x[2] + x[4]) / 2;
    if (abs(x[1] - x[3]) == 2) {
        _board[x2][y2].setValue(0);
        pieces[(turn == 1 || turn == 3) ? 1 : 0]--;
    }
}

int CheckersGame::winner(int x, int o) {
    if (x == 0) {
        return PLAYER_O;
    }
    else if (o == 0) {
        return PLAYER_X;
    }
    else {
        return 0;
    }
}

Player* CheckersGame::play(Player* player1, Player* player2) {
    setDefaults();

    string player1Nickname = player1->getNickname();
    string player2Nickname = player2->getNickname();

    int size1 = player1Nickname.size();
    int size2 = player2Nickname.size();

    int size = (size1 >= size2) ? size1 : size2;

    cout << "\nIniciando tabuleiro...\n" << endl;
    cout << setw(size) << left << player1Nickname << ": (" << RED_COLOR << "x" << RESET_ALL << " - peca comum)" << endl;
    cout << setw(size) << left << " " << ": (" << RED_BOLD << "X" << RESET_ALL << " - Dama)" << endl;
    cout << setw(size) << left << player2Nickname << ": (" << YELLOW_COLOR << "o" << RESET_ALL << " - peca comum)" << endl;
    cout << setw(size) << left << " " << ": (" << YELLOW_BOLD << "O" << RESET_ALL << " - Dama)" << endl;
    cout << endl;
    printBoard();

    while (true) {
        int x[4];
        bool moveValido = false;
        while (!moveValido) {
            std::cout << ((turn % 2 == 1) ? "-- Turno do X --" : "-- Turno do O --") << std::endl;
            if (readMove(x)) {
                if (simpleMove(x)) {
                    updateBoard(x);
                    checkIfBecameQueen(x[3], x[4]);
                    moveValido = true;
                }
                else if (captureMove(x)) {
                    updateBoard(x);
                    checkIfBecameQueen(x[3], x[4]);
                    moveValido = true;
                }
                else {
                    std::cout << "Movimento invalido. Tente novamente." << std::endl;
                }
            }
        }
        cout << endl;
        printBoard();
        int playerWinner = winner(pieces[0], pieces[1]);

        if (playerWinner == PLAYER_X) {
            cout << GREEN_COLOR << "PARABENS " << player1->getNickname() << ", VOCE GANHOU!" << RESET_ALL << endl;
            return player1;
        }
        else if (playerWinner == PLAYER_O) {
            cout << GREEN_COLOR << "PARABENS " << player2->getNickname() << ", VOCE GANHOU!" << RESET_ALL << endl;
            return player2;
        }
        turn = (turn == 1) ? 2 : 1;
    }
}

void CheckersGame::printBoard() {
    // Relação que permite uma exibição visual correta do campo
    int lineSizeOfPrint = (this->columnsSize * 4) + 1;

    // Printa os números das colunas
    if (this->columnsSize <= 10) {
        cout << "\t   ";
        for (int i = 0; i < this->columnsSize; i++)
            cout << " " << i << "  ";

        cout << endl;
    }
    // Altera a exibição dos números das colunas para mostrar corretamente índices com dois dígitos
    else {
        cout << "\t    ";
        for (int i = 0; i < this->columnsSize; i++) {
            if (i < 10)
                cout << " " << i << "  ";

            else
                cout << i << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < this->linesSize; i++) {
        // Printa as linhas de separação
        if (this->linesSize <= 10) {
            cout << "\t  ";
            for (int a = 0; a < lineSizeOfPrint; a++)
                cout << "-";
        }
        // Altera a exibição das linhas para se adequar ao layout para índices com dois dígitos
        else {
            cout << "\t   ";
            for (int a = 0; a < lineSizeOfPrint; a++)
                cout << "-";
        }

        // Printa o número das linhas
        if (this->linesSize <= 10)
            cout << "\n\t" << i << " |";
        // Altera a exibição dos números das linhas para mostrar corretamente índices com dois dígitos
        else {
            if (i < 10)
                cout << "\n\t" << i << "  |";

            else
                cout << "\n\t" << i << " |";
        }
        // Printa o campo
        for (int j = 0; j < this->columnsSize; j++) {
            if (_board[i][j].getValue() == EMPTY)
                cout << "   |";

            else if (_board[i][j].getValue() == PLAYER_X) {
                cout << " " << RED_COLOR << "x" << RESET_ALL << " |";
            }

            else if (_board[i][j].getValue() == PLAYER_O)
                cout << " " << YELLOW_COLOR << "o" << RESET_ALL << " |";

            else if (_board[i][j].getValue() == PLAYER_X_QUEEN) {
                cout << " " << RED_BOLD << "X" << RESET_ALL << " |";
            }

            else if (_board[i][j].getValue() == PLAYER_O_QUEEN)
                cout << " " << YELLOW_BOLD << "O" << RESET_ALL << " |";
        }
        cout << endl;

        // Printa a última linha de separação
        if (i == this->linesSize - 1) {
            if (this->linesSize <= 10) {
                cout << "\t  ";
                for (int a = 0; a < lineSizeOfPrint; a++)
                    cout << "-";
            }
            // Altera a exibição da linha para se adequar ao layout para índices com dois dígitos
            else {
                cout << "\t   ";
                for (int a = 0; a < lineSizeOfPrint; a++)
                    cout << "-";
            }
        }
    }
    cout << "\n\n";
}