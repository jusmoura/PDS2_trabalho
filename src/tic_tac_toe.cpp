#include "../include/tic_tac_toe.hpp"

using namespace std;

TicTacToe::TicTacToe() :Board(3, 3), currentPlayer(PLAYER_X) {
}

bool TicTacToe::checkVictory() {
    int currentValue;
    //Verificação horizontal
    for (int i = 0; i < linesSize; i++) {
        currentValue = _board[i][0].getValue();
        if (currentValue != EMPTY) {
            int sum = 1;
            for (int j = 1; j < columnsSize; j++) {
                if (_board[i][j].getValue() == currentValue)
                    sum++;
                else
                    break;
            }
            if (sum == 3)
                return currentValue;
        }
    }

    //Verificação vertical
    for (int j = 0; j < columnsSize; j++) {
        currentValue = _board[0][j].getValue();
        if (currentValue != EMPTY) {
            int sum = 1;
            for (int i = 1; i < linesSize; i++) {
                if (_board[i][j].getValue() == currentValue)
                    sum++;
                else
                    break;
            }
            if (sum == 3)
                return currentValue;
        }
    }

    //Verificação diagonal principal
    //Primeira celula: de baixo para cima; da esquerda para direita
    int line = linesSize - 1;
    int col = 0;
    currentValue = _board[line][col].getValue();

    if (currentValue != EMPTY) {
        int sum = 1;
        for (int i = 1; i < BOARD_SIZE; i++) {
            if (_board[line - i][col + i].getValue() == currentValue)
                sum++;
            else
                break;
        }
        if (sum == 3)
            return currentValue;
    }

    //Verificação diagonal secundária
    //Primeira celula: de baixo para cima; da direita para esquerda
    line = linesSize - 1;
    col = columnsSize - 1;
    currentValue = _board[line][col].getValue();

    if (currentValue != EMPTY) {
        int sum = 1;
        for (int i = 1; i < BOARD_SIZE; i++) {
            if (_board[line - i][col - i].getValue() == currentValue)
                sum++;
            else
                break;
        }
        if (sum == 3)
            return currentValue;
    }
    return 0;
}

bool TicTacToe::checkTie() {
    for (int i = 0;i < BOARD_SIZE;i++) {
        for (int j = 0;j < BOARD_SIZE;j++) {
            if (_board[i][j].getValue() == EMPTY)
                return false;
        }
    }
    return true;
}

bool TicTacToe::validMove(int line, int column) {
    if (_board[line][column].getValue() != EMPTY || line < 0 || column < 0 || line >= BOARD_SIZE || column >= BOARD_SIZE)
        return false;
    else
        return true;
}

void TicTacToe::switchPlayer() {
    if (currentPlayer == PLAYER_X)
        currentPlayer = PLAYER_O;
    else
        currentPlayer = PLAYER_X;
}

void TicTacToe::makeMove(int line, int column) {
    if (validMove(line, column))
        _board[line][column].setValue(currentPlayer);
    else {
        cout << "\n" << YELLOW_COLOR << "Jogada invalida. Tente novamente!\n" << RESET_ALL << endl;
        throw "INVALID_MOVE";
    }
}

Player* TicTacToe::play(Player* player1, Player* player2) {
    Player* currentPlayerPtr = player1;
    Player* otherPlayerPtr = player2;

    string player1Nickname = player1->getNickname();
    string player2Nickname = player2->getNickname();

    int size1 = player1Nickname.size();
    int size2 = player2Nickname.size();

    int size = (size1 >= size2) ? size1 : size2;

    cout << "\nIniciando tabuleiro...\n" << endl;
    cout << setw(size) << left << player1Nickname << ": (" << RED_COLOR << "X" << RESET_ALL << ")" << endl;
    cout << setw(size) << left << player2Nickname << ": (" << YELLOW_COLOR << "O" << RESET_ALL << ")\n" << endl;
    Board::printBoard();

    int line;
    int column;
    string input;

    while (1) {
        try {
            cout << (currentPlayerPtr == player1 ? player1Nickname : player2Nickname) << ": insira [linha coluna] ou 'sair' para voltar ao menu de jogos" << endl;
            getline(cin, input);

            if (input == "SAIR" || input == "sair")
                throw SIMPLE_RETURN;

            stringstream ss(input);

            if (ss >> line >> column) {
                makeMove(line, column);
                cout << endl;
                cout << setw(size) << left << player1Nickname << ": (" << RED_COLOR << "X" << RESET_ALL << ")" << endl;
                cout << setw(size) << left << player2Nickname << ": (" << YELLOW_COLOR << "O" << RESET_ALL << ")\n" << endl;
                Board::printBoard();
                if (checkVictory()) {
                    cout << GREEN_COLOR << "PARABENS " << currentPlayerPtr->getNickname() << ", VOCE GANHOU!" << RESET_ALL << endl;
                    return currentPlayerPtr;
                }
                else if (checkTie()) {
                    cout << YELLOW_COLOR << "VELHA! O jogo terminou em empate!" << RESET_ALL << endl;
                    return nullptr;
                }
                switchPlayer();
                swap(currentPlayerPtr, otherPlayerPtr);
            }
            else
                cout << "\n" << YELLOW_COLOR << "Entrada invalida! Insira [linha coluna] ou 'sair'\n" << RESET_ALL << endl;
        }
        catch (const char* e) {
            if (e != "INVALID_MOVE")
                throw;
        }
    }
}