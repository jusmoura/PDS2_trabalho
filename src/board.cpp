#include "../include/board.hpp"

using namespace std;

Board::Board(int line, int column) : linesSize(line), columnsSize(column) {
    initBoard();
};

void Board::initBoard() {
    //Inicializa todas as celulas do tabuleiro
    for (int i = 0; i < this->linesSize; i++) {
        vector<Cell> column;
        for (int j = 0; j < this->columnsSize; j++) {
            Cell cell = Cell();
            column.push_back(cell);
        }
        _board.push_back(column);
    }
}

bool Board::validateMove(int line, int column) {
    if (line < 0 || line >= linesSize || column < 0 || column >= columnsSize)
        return false;
    else
        return true;
}

void Board::printBoard() {
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
            /*
            ADAPTAR OS PRINTS ABAIXO PARA CADA JOGO, SE NECESSÁRIO (OVERRIDE)
            */
            if (_board[i][j].getValue() == EMPTY)
                cout << "   |";

            else if (_board[i][j].getValue() == PLAYER_X) {
                cout << " " << RED_COLOR << "X" << RESET_ALL << " |";
            }

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