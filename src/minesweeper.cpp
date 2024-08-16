#include "../include/minesweeper.hpp"

using namespace std;

Minesweeper::Minesweeper() : Board(8, 8) {
    setBombsPositions();
}

//OVERRIDE
void Minesweeper::printBoard() {
    // Relação que permite uma exibição visual correta do campo
    int lineSizeOfPrint = (this->linesSize * 4) + 1;

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
            if (_board[i][j].getSelected() == false)
                cout << " \xdb |";

            else {
                if (_board[i][j].getValue() >= IS_BOMB)
                    cout << " " << RED_COLOR << "B" << RESET_ALL << " |";

                else if (_board[i][j].getValue() == EMPTY)
                    cout << "   |";

                else {
                    int value = _board[i][j].getValue();
                    //Cores dos números
                    switch (value) {
                    case 1:
                        cout << " " << GREEN_COLOR << value << RESET_ALL << " |";
                        break;
                    case 2:
                        cout << " " << BLUE_COLOR << value << RESET_ALL << " |";
                        break;
                    case 3:
                        cout << " " << YELLOW_COLOR << value << RESET_ALL << " |";
                        break;
                    case 4:
                        cout << " " << PURPLE_COLOR << value << RESET_ALL << " |";
                        break;

                    default:
                        cout << " " << value << " |";
                        break;
                    }
                }
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

Player* Minesweeper::play(Player* player1, Player* player2) {
    cout << "\nCampo gerado para " << player1->getNickname() << ":\n\n";
    while (1) {
        printBoard();
        // Solicitando ao usuário uma escolha de posição
        cout << "Escolha uma posicao (formato: \"linha coluna\" ou digite \"SAIR\" para voltar)" << endl;
        cout << "Digite a posicao que deseja selecionar: ";

        int line, column;
        string input;

        getline(cin, input);

        if (input == "SAIR" || input == "sair")
            throw SIMPLE_RETURN;

        else {
            stringstream ss(input);
            if (ss >> line >> column) {
                cout << endl;

                if (validateMove(line, column)) {
                    // Determinando a exibição da posição escolhida
                    if (_board[line][column].getValue() == EMPTY)
                        //Verifica celulas adjacentes caso a selecionada for 0
                        checkAndShowAdjacentsCells(line, column);

                    else
                        _board[line][column].setSelected(true);
                }
                else {
                    cout << YELLOW_COLOR << "Entrada invalida. Tente novamente!\n" << RESET_ALL << endl;
                    continue;
                }

                if (checkDefeat(line, column))
                    return nullptr;

                if (checkVictory())
                    return player1;
            }
            else {
                cout << "\n" << YELLOW_COLOR << "Entrada invalida. Tente novamente!\n" << RESET_ALL << endl;
                continue;
            }
        }
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
        printBoard();
        cout << "\n" << RED_COLOR << "Bumm! Voce selecionou uma bomba!\n" << LOSER_STYLE << "Fim de jogo!" << RESET_ALL << endl;
        return true;
    }

    else
        return false;
}

bool Minesweeper::checkVictory() {
    // Verificando se o jogador ganhou
    int counter = 0;
    for (int i = 0; i < this->linesSize; i++) {
        for (int j = 0; j < this->columnsSize; j++) {
            if (_board[i][j].getSelected() == false && _board[i][j].getValue() < IS_BOMB)
                counter++;
        }
    }
    if (counter == 0) {
        printBoard();
        cout << "\n" << GREEN_COLOR << "Parabens! Voce nao selecionou nenhuma bomba!\n" << WINNER_STYLE << "Ganhou o jogo!" << RESET_ALL << endl;
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

            else if (validateMove(line + i, column + j) && _board[line + i][column + j].getValue() == EMPTY && _board[line + i][column + j].getSelected() == false)
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