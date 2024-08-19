#include "../include/lig4.hpp"

Lig4::Lig4() :Board(6, 7), currentPlayer(PLAYER_X) {
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
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 7;j++) {
            if (_board[i][j].getValue() == EMPTY)
                return false;
        }
    }
    return true;
}

bool Lig4::checkVictory() {
    //Itera por todas as casas do tabuleiro
    for (int line = linesSize - 1; line >= 0; line--) {
        for (int col = 0; col < columnsSize; col++) {
            //Verificando vitórias
            int sum = 1;
            //Direita
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

            //Cima
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

            //Diagonal Superior Direita
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

            //Diagonal Superior Esquerda
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
    return false;
}

Player* Lig4::play(Player* player1, Player* player2) {
    Player* currentPlayerPtr = player1;
    Player* otherPlayerPtr = player2;

    string player1Nickname = player1->getNickname();
    string player2Nickname = player2->getNickname();

    cout << endl;
    printBoard();
    int column;

    while (!checkVictory() && !checkTie()) {
        std::cout << (currentPlayerPtr == player1 ? player1Nickname : player2Nickname) << ": insira [coluna]" << std::endl;
        std::cin >> column;
        makeMove(column);
        printBoard();
        if (checkVictory()) {
            std::cout << GREEN_COLOR << "PARABENS " << currentPlayerPtr->getNickname() << ", VOCE GANHOU!" << RESET_ALL << endl;
            return currentPlayerPtr;
            break;
        }

        if (checkTie()) {
            std::cout << YELLOW_COLOR << "O jogo terminou em empate!" << RESET_ALL << std::endl;
            return nullptr;
            break;
        }
        switchPlayer();
        std::swap(currentPlayerPtr, otherPlayerPtr);
    }
}