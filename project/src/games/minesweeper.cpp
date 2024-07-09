#include "../include/minesweeper.hpp"

using namespace std;

Minesweeper::Minesweeper(int line, int column) : Board(line, column) {
    setBombsPositions();
}

//OVERRIDE
void Minesweeper::printBoard() {
    // Relação que permite uma exibição visual correta do campo
    int lineSizeOfPrint = (this->linesSize * 4) + 1;

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
            if (_board[i][j].getSelected() == false)
                cout << " \xdb |";

            else {
                if (_board[i][j].getValue() >= IS_BOMB)
                    cout << " B |";

                else if (_board[i][j].getValue() == 0)
                    cout << "   |";

                else
                    cout << " " << _board[i][j].getValue() << " |";
            }
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

bool Minesweeper::play() {
    cout << "\nCampo gerado:\n\n";
    printBoard();
    while (1) {
        // Solicitando ao usuário uma escolha de posição
        int line, column;
        cout << "\nEscolha uma posicao (formato: \"nLinha nColuna\")" << endl;
        cout << "Digite a posicao que deseja selecionar: ";
        cin >> line >> column;
        cout << endl;

        // Determinando a exibição da posição escolhida
        if (validateMove(line, column) && _board[line][column].getValue() == 0)
            //Verifica celulas adjacentes caso a selecionada for 0
            checkAndShowAdjacentsCells(line, column);

        else {
            if (validateMove(line, column))
                _board[line][column].setSelected(true);
        }

        printBoard();

        if (checkDefeat(line, column))
            return false;

        if (checkWin())
            return true;
    }
}

void Minesweeper::setBombsPositions() {
    int bombsNumber;
    //Define um número aceitável de bombas de acordo com o tamanho do tabuleiro
    int size = (linesSize + columnsSize) / 2;
    bombsNumber = size > 11 ? size + 5 : size + 1;

    // Sorteando as posições das bombas
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < bombsNumber; i++) {
        int line = rand() % size;
        int column = rand() % size;

        if (_board[line][column].getValue() < IS_BOMB)
            _board[line][column].setValue(IS_BOMB);

        else // Caso na posição sorteada já exista uma bomba
            i--;
    }

    // Identificando o número de bombas existentes ao redor de uma posição
    for (int line = 0; line < this->linesSize; line++) {
        for (int column = 0; column < this->columnsSize; column++) {
            // Verifica se há bomba na posição
            if (_board[line][column].getValue() >= IS_BOMB) {
                // Itera por todas as posições adjacentes e incrementa seu valor devido à presença de bomba na posição atual
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (validateMove(line + i, column + j)) {
                            if (line + i == line && column + j == column)
                                // Evita que a própria posição seja incrementada
                                continue;
                            else {
                                int value = _board[line + i][column + j].getValue();
                                value++;
                                _board[line + i][column + j].setValue(value);
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Minesweeper::checkDefeat(int line, int column) {
    // Determinando o fim do jogo caso uma bomba seja escolhida
    if (validateMove(line, column) && _board[line][column].getValue() >= IS_BOMB) {
        cout << "\n\nBumm! Voce selecionou uma bomba!\nFim de jogo!\n\n";
        return true;
    }

    else
        return false;
}

bool Minesweeper::checkWin() {
    // Verificando se o jogador ganhou
    int counter = 0;
    for (int i = 0; i < this->linesSize; i++) {
        for (int j = 0; j < this->columnsSize; j++) {
            if (_board[i][j].getSelected() == false && _board[i][j].getValue() < IS_BOMB)
                counter++;
        }
    }
    if (counter == 0) {
        cout << "\n\nParabens! Voce nao selecionou nenhuma bomba!\nGanhou o jogo!\n\n";
        return true;
    }
    else
        return false;
}

void Minesweeper::checkAndShowAdjacentsCells(int line, int column) {
    _board[line][column].setSelected(true);

    // Itera por todas as posições adjacentes, verifica se não são bombas e determina sua exibição
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (line + i == line && column + j == column)
                // Evita que a própria posição seja checada novamente
                continue;

            else if (validateMove(line + i, column + j) && _board[line + i][column + j].getValue() == 0 && _board[line + i][column + j].getSelected() == false)
                // Chamada recursiva da função para verificar se o adjacente ao adjacente atual (e etc) também não é bomba -> para liberar todos os 0's adjacentes
                checkAndShowAdjacentsCells(line + i, column + j);

            else {
                if (validateMove(line + i, column + j))
                    // Exibe a posição adjacente que possui contagem de bombas caso não seja 0
                    _board[line + i][column + j].setSelected(true);
            }
        }
    }
}