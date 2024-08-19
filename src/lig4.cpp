#include "../include/lig4.hpp"

Lig4::Lig4() :Board(6, 7), currentPlayer(PLAYER_X) {
}

bool Lig4::checkVictory() {
    //Itera por todas as casas do tabuleiro; de baixo para cima, da esquerda para a direita
    for (int line = linesSize - 1; line >= 0; line--) {
        for (int col = 0; col < columnsSize; col++) {
            //Verificando vitórias
            if (_board[line][col].getValue() == EMPTY)
                continue;
            else {
                int sum = 1;
                //Verificação horizontal
                for (int i = 1; col + i < columnsSize; i++) {
                    if (Board::validateMove(line, col + i) && _board[line][col + i].getValue() != EMPTY) {
                        if (_board[line][col + i].getValue() == currentPlayer)
                            sum++;
                        else
                            break;
                    }
                    else
                        break;
                }
                if (sum == 4)
                    return true;
                else
                    sum = 1;

                //Verificação Vertical
                for (int i = 1; line - i >= 0; i++) {
                    if (Board::validateMove(line - i, col) && _board[line - i][col].getValue() != EMPTY) {
                        if (_board[line - i][col].getValue() == currentPlayer)
                            sum++;
                        else
                            break;
                    }
                    else
                        break;
                }
                if (sum == 4)
                    return true;
                else
                    sum = 1;

                //Verificação Diagonal Superior Direita
                for (int i = 1; line - i >= 0; i++) {
                    if (Board::validateMove(line - i, col + i) && _board[line - i][col + i].getValue() != EMPTY) {
                        if (_board[line - i][col + i].getValue() == currentPlayer)
                            sum++;
                        else
                            break;
                    }
                    else
                        break;
                }
                if (sum == 4)
                    return true;
                else
                    sum = 1;

                //Verificação Diagonal Superior Esquerda
                for (int i = 1; line - i >= 0; i++) {
                    if (Board::validateMove(line - i, col - i) && _board[line - i][col - i].getValue() != EMPTY) {
                        if (_board[line - i][col - i].getValue() == currentPlayer)
                            sum++;
                        else
                            break;
                    }
                    else
                        break;
                }
                if (sum == 4)
                    return true;
                else
                    sum = 1;
            }
        }
    }
    return false;
}

void Lig4::switchPlayer() {
    if (currentPlayer == PLAYER_X)
        currentPlayer = PLAYER_O;
    else
        currentPlayer = PLAYER_X;
}

void Lig4::makeMove(int column) {
    //Validando apenas a coluna
    if (Board::validateMove(0, column)) {
        bool cellWasFilled = false;
        for (int i = linesSize - 1; i >= 0; i--) {
            if (_board[i][column].getValue() == EMPTY) {
                _board[i][column].setValue(currentPlayer);
                cellWasFilled = true;
                break;
            }
        }

        if (!cellWasFilled)
            cout << "Coluna totalmente preenchida, jogue novamente" << endl;
    }
    else
        cout << "Coluna invalida, jogue novamente" << endl;
}

bool Lig4::checkTie() {
    for (int i = 0;i < linesSize;i++) {
        for (int j = 0;j < columnsSize;j++) {
            if (_board[i][j].getValue() == EMPTY)
                return false;
        }
    }
    return true;
}


Player* Lig4::play(Player* player1, Player* player2) {
    Player* currentPlayerPtr = player1;
    Player* otherPlayerPtr = player2;

    string player1Nickname = player1->getNickname();
    string player2Nickname = player2->getNickname();

    cout << endl;
    printBoard();
    int column;

    while (1) {
        std::cout << (currentPlayerPtr == player1 ? player1Nickname : player2Nickname) << ": insira [coluna]" << std::endl;
        std::cin >> column;
        makeMove(column);
        printBoard();
        if (checkVictory()) {
            std::cout << GREEN_COLOR << "PARABENS " << currentPlayerPtr->getNickname() << ", VOCE GANHOU!" << RESET_ALL << endl;
            return currentPlayerPtr;
        }

        if (checkTie()) {
            std::cout << YELLOW_COLOR << "O jogo terminou em empate!" << RESET_ALL << std::endl;
            return nullptr;
        }
        switchPlayer();
        std::swap(currentPlayerPtr, otherPlayerPtr);
    }
}

//OVERRIDE
void Lig4::printBoard() {
    // Relação que permite uma exibição visual correta do campo
    int lineSizeOfPrint = (this->columnsSize * 4) + 1;

    // Printa os números das colunas
    if (this->columnsSize <= 10) {
        printf("\t   ");
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
                cout << " " << i << " ";
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
            cout << "\n\t  |";
        // Altera a exibição dos números das linhas para mostrar corretamente índices com dois dígitos
        else {
            if (i < 10)
                cout << "\n\t   |";

            else
                cout << "\n\t   |";
        }
        // Printa o campo
        for (int j = 0; j < this->columnsSize; j++) {
            if (_board[i][j].getValue() == EMPTY)
                cout << "   |";

            else if (_board[i][j].getValue() == PLAYER_X)
                cout << " " << RED_COLOR << "X" << RESET_ALL << " |";

            else if (_board[i][j].getValue() == PLAYER_O)
                cout << " " << YELLOW_COLOR << "O" << RESET_ALL << " |";
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