#include "../include/checkers.hpp"

CheckersGame::CheckersGame() : Board(8, 8) {
}

void CheckersGame::setDefaults()
{
    _board[0][1].setValue(1); _board[0][3].setValue(1); _board[0][5].setValue(1); _board[0][7].setValue(1);
    _board[1][0].setValue(1); _board[1][2].setValue(1); _board[1][4].setValue(1); _board[1][6].setValue(1);
    _board[2][1].setValue(1); _board[2][3].setValue(1); _board[2][5].setValue(1); _board[2][7].setValue(1);
    _board[5][0].setValue(2); _board[5][2].setValue(2); _board[5][4].setValue(2); _board[5][6].setValue(2);
    _board[6][1].setValue(2); _board[6][3].setValue(2); _board[6][5].setValue(2); _board[6][7].setValue(2);
    _board[7][0].setValue(2); _board[7][2].setValue(2); _board[7][4].setValue(2); _board[7][6].setValue(2);
}

int CheckersGame::enemy(int piece)
{
    if(piece == 1 || piece == 3)
    {
        return 2;
    }
    if(piece == 2 || piece == 4)
    {
        return 1;
    }
    return 0;
}

void CheckersGame::checkIfBecameQueen(int x, int y)
{
    if(turn == 1)
    {
        if(x == 7)
        {
            _board[x][y].setValue(3);
        }
    }
    if(turn == 2)
    {
        if(x == 0)
        {
            _board[x][y].setValue(4);
        }
    }
}

void CheckersGame::readMove(int x[])
{
    std::cout << "Digite linha e coluna da peça: " << std::endl;
    std::cin >> x[1] >> x[2];
    std::cout << "Digite linha e coluna da jogada: " << std::endl;
    std::cin >> x[3] >> x[4];
}

bool CheckersGame::validMove(int x[4])
{
    if(x[1] < 0 || x[1] >= BOARD_SIZE || x[2] < 0 || x[2] > BOARD_SIZE) {
        std::cout << "Jogada invalida 1" << std::endl;
        return false;
    }
    else if(x[3] < 0 || x[3] >= BOARD_SIZE || x[4] < 0 || x[4] > BOARD_SIZE) {
        std::cout << "Jogada invalida 2" << std::endl;
        return false;
    }
    else if(_board[x[3]][x[4]].getValue() == 1 || _board[x[3]][x[4]].getValue() == 2 || _board[x[3]][x[4]].getValue() == 3 || _board[x[3]][x[4]].getValue() == 4) {
        std::cout << "Jogada invalida 3" << std::endl;
        return false;
    }
    else {
        return true;
        std::cout << "Deu bom" << std::endl;
    }
}

int CheckersGame::nextChainValid(int x[4])
{
    int currentPiece = _board[x[1]][x[2]].getValue();
    int enemyPiece1 = enemy(currentPiece);
    int enemyPiece2 = enemy(currentPiece + 2);

    // Verifica as quatro diagonais adjacentes para uma peça inimiga
    if(_board[x[1] + 1][x[2] + 1].getValue() == enemyPiece1 || _board[x[1] + 1][x[2] + 1].getValue() == enemyPiece2 ||
        _board[x[1] + 1][x[2] - 1].getValue() == enemyPiece1 || _board[x[1] + 1][x[2] - 1].getValue() == enemyPiece2 ||
        _board[x[1] - 1][x[2] + 1].getValue() == enemyPiece1 || _board[x[1] - 1][x[2] + 1].getValue() == enemyPiece2 ||
        _board[x[1] - 1][x[2] - 1].getValue() == enemyPiece1 || _board[x[1] - 1][x[2] - 1].getValue() == enemyPiece2) {
        return 1;
    }
    else {
        return 0;
    }
}

bool CheckersGame::simpleMove(int x[4])
{
    return (x[3] == x[1] + 1 || x[3] == x[1] - 1) && (x[4] == x[2] + 1 || x[4] == x[2] - 1);
}

bool CheckersGame::captureMove(int x[4])
{
    if (nextChainValid(x) == 1){
        return (x[3] == x[1] + 2 || x[3] == x[1] - 2) && (x[4] == x[2] + 2 || x[4] == x[2] - 2);
    }
    else {
        return false;
    }
}

void CheckersGame::updateBoard(int x[4])
{
    _board[x[1]][x[2]].setValue(0);
    _board[x[3]][x[4]].setValue(turn);
    int x2 = (x[1] + x[3]) / 2;
    int y2 = (x[2] + x[4]) / 2;
    if (abs(x[1] - x[3]) == 2) {
        _board[x2][y2].setValue(0);
        peshka[(turn == 1 || turn == 3) ? 1 : 0]--;
    }
}

void CheckersGame::getCo()
{
    int x[4];
    bool moveValido = false;
    while (!moveValido) {
        std::cout << ((turn % 2 == 1) ? "x's turn." : "o's turn.") << std::endl;
        readMove(x);
        if (validMove(x)) {
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
                std::cout << "Movimento inválido. Tente novamente." << std::endl;
            }
        }
    }
}

int CheckersGame::winner(int x, int o)
{
    if(x == 0)
    {
        std::cout << "O won!" << std::endl;
        return 1;
    }
    else if(o == 0)
    {
        std::cout << "X won!" << std::endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

Player* CheckersGame::play(Player* player1, Player* player2) {
    setDefaults();
    Board::printBoard();

    while (true) {
        getCo();
        Board::printBoard();
        if (winner(peshka[0], peshka[1])) {
            break;
        }
        turn = (turn == 1) ? 2 : 1;
    }
}