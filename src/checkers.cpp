#include "../include/checkers.hpp"

void CheckersGame::printBoard()
{
    int board[8][8];
    int x, y;
    char z = 1;
    for (x = 0; x < 8; x++){
        std::cout << z << std::endl;
        z++;
        for (y = 0; y < 8; y++){
            std::cout << "|";
            switch(board[x][y])
            {
                case 0:
                    std::cout << " ";
                    break;
                case 1:
                    std::cout << "x";
                    break;
                case 2:
                    std::cout << "o";
                    break;
                case 3:
                    std::cout << "X";
                    break;
                case 4:
                    std::cout << "O";
                    break;
            }
        }
        std::cout << "|";
    }
    std::cout << std::endl;
}

void CheckersGame::setDefaults(int board[8][8])
{
    board[0][1] = 1; board[0][3] = 1; board[0][5] = 1; board[0][7] = 1;
    board[1][0] = 1; board[1][2] = 1; board[1][4] = 1; board[1][6] = 1;
    board[2][1] = 1; board[2][3] = 1; board[2][5] = 1; board[2][7] = 1;
    board[5][0] = 2; board[5][2] = 2; board[5][4] = 2; board[5][6] = 2;
    board[6][1] = 2; board[6][3] = 2; board[6][5] = 2; board[6][7] = 2;
    board[7][0] = 2; board[7][2] = 2; board[7][4] = 2; board[7][6] = 2;
}

int CheckersGame::Enemy(int piece)
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

void CheckersGame::CheckIfBecameQueen(int x, int y, int board[8][8], int turn)
{
    if(turn == 1)
    {
        if(x == 7)
        {
            board[x][y] = 3;
        }
    }
    if(turn == 2)
    {
        if(x == 0)
        {
            board[x][y] = 4;
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

bool CheckersGame::validMove(int board[8][8], int x[4])
{
    if (x[1] < 0 || x[1] >= 8 || x[2] < 0 || x[2] > 8){
        std::cout << "Jogada invalida 1" << std::endl;
        return false;
    }
    else if (x[3] < 0 || x[3] >= 8 || x[4] < 0 || x[4] > 8){
        std::cout << "Jogada invalida 2" << std::endl;
        return false;
    }
    else if (board[x[3]][x[4]] == 1 || board[x[3]][x[4]] == 2 || board[x[3]][x[4]] == 3 || board[x[3]][x[4]] == 4){
        std::cout << "Jogada invalida 3" << std::endl;
        return false;
    }
    else {
        return true;
        std::cout << "Deu bom"<< std::endl;
    }
}

int CheckersGame::nextChainValid(int board[8][8], int x[4])
{
    int currentPiece = board[x[1]][x[2]];
    int enemyPiece1 = Enemy(currentPiece);
    int enemyPiece2 = Enemy(currentPiece + 2);

    // Verifica as quatro diagonais adjacentes para uma peça inimiga
    if (board[x[1] + 1][x[2] + 1] == enemyPiece1 || board[x[1] + 1][x[2] + 1] == enemyPiece2 ||
        board[x[1] + 1][x[2] - 1] == enemyPiece1 || board[x[1] + 1][x[2] - 1] == enemyPiece2 ||
        board[x[1] - 1][x[2] + 1] == enemyPiece1 || board[x[1] - 1][x[2] + 1] == enemyPiece2 ||
        board[x[1] - 1][x[2] - 1] == enemyPiece1 || board[x[1] - 1][x[2] - 1] == enemyPiece2) {
        return 1;
    } else {
        return 0;
    }
}

bool CheckersGame::simpleMove(int x[4], int turn)
{
    return (x[3] == x[1] + 1 || x[3] == x[1] - 1) && (x[4] == x[2] + 1 || x[4] == x[2] - 1);
}

bool CheckersGame::captureMove(int board[8][8], int x[4], int turn)
{
    if (nextChainValid(board, x) == 1){
        return (x[3] == x[1] + 2 || x[3] == x[1] - 2) && (x[4] == x[2] + 2 || x[4] == x[2] - 2);
    }
    else {
        return false;
    }
}

void CheckersGame::updateBoard(int board[8][8], int x[4], int turn, int peshka[2])
{
    board[x[1]][x[2]] = 0;
    board[x[3]][x[4]] = turn;
    int x2 = (x[1] + x[3]) / 2;
    int y2 = (x[2] + x[4]) / 2;
    if (abs(x[1] - x[3]) == 2) {
        board[x2][y2] = 0;
        peshka[(turn == 1 || turn == 3) ? 1 : 0]--;
    }
}

void CheckersGame::getCo(int board[8][8], int turn, int peshka[2])
{
    int x[4];
    bool moveValido = false;
    while (!moveValido) {
        std::cout << ((turn % 2 == 1) ? "x's turn." : "o's turn.") << std::endl;
        readMove(x);
        if (validMove(board, x)) {
            if (simpleMove(x, turn)) {
                updateBoard(board, x, turn, peshka);
                CheckIfBecameQueen(x[3], x[4], board, turn);
                moveValido = true;
            } 
            else if (captureMove(board, x, turn)) {
                updateBoard(board, x, turn, peshka);
                CheckIfBecameQueen(x[3], x[4], board, turn);
                moveValido = true;
            } 
            else {
                std::cout << "Movimento inválido. Tente novamente." << std::endl;
            }
        }
    }
}

int CheckersGame::Winner(int x, int o)
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