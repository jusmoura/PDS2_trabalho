#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

void print_board(int board[9][8])
{
    int x, y;
    char z=1;
    for (x=1;x<9;x++){
        cout << z << endl;
        z++;
        for (y=1;y<9;y++){
            cout << "|";
            switch(board[x][y])
            {
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << "x";
                    break;
                case 2:
                    cout << "o";
                    break;
                case 3:
                    cout << "X";
                    break;
                case 4:
                    cout << "O";
                    break;
            }
        }
        cout << "|";
    }
    cout << endl;
}

void set_defaults(int board[9][8])
{
    board[1][2]=1;board[1][4]=1;board[1][6]=1;board[1][8]=1;
    board[2][1]=1;board[2][3]=1;board[2][5]=1;board[2][7]=1;
    board[3][2]=1;board[3][4]=1;board[3][6]=1;board[3][8]=1;
    board[6][1]=2;board[6][3]=2;board[6][5]=2;board[6][7]=2;
    board[7][2]=2;board[7][4]=2;board[7][6]=2;board[7][8]=2;
    board[8][1]=2;board[8][3]=2;board[8][5]=2;board[8][7]=2;
}

int Enemy(int piece)
{
    if(piece==1 || piece==3)
    {
        return 2;
    }
    if(piece==2 || piece==4)
    {
        return 1;
    }
    return 0;
}

void Check_if_became_queen(int x, int y, int board[9][8], int turn)
{
    if(turn==1)
    {
        if(x==8)
        {
            board[x][y]=3;
        }
    }
    if(turn==2)
    {
        if(x==1)
        {
            board[x][y]=4;
        }
    }
}

void lerJogadas(int x[]) {
    cout << "linha peça: " << endl;
    cin >> x[1];
    cout << "coluna peça: " << endl;
    cin >> x[2];
    cout << "linha jogada: " << endl;
    cin >> x[3];
    cout << "coluna jogada: " << endl;
    cin >> x[4];
}

bool JogadaValida(int board[9][8], int x[4]) {
    if (x[1] < 0 || x[1] >= 9 || x[2] < 0 || x[2] >= 8){
        cout << "Jogada invalida 1" << endl;
        return false;
    }
    else if (x[3] < 0 || x[3] >= 9 || x[4] < 0 || x[4] >= 8){
        cout << "Jogada invalida 2" << endl;
        return false;
    }
    else if (board[x[3]][x[4]] == 1 || board[x[3]][x[4]] == 2 || board[x[3]][x[4]] == 3 || board[x[3]][x[4]] == 4){
        cout << "Jogada invalida 3" << endl;
        return false;
    }
    else {
        return true;
        cout<< "Deu bom"<<endl;
    }
}

int NextChainValid(int board[9][8], int x[4]) {
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

bool movimentoSimples(int x[4], int turn) {
    return (x[3] == x[1] + 1 || x[3] == x[1] - 1) && (x[4] == x[2] + 1 || x[4] == x[2] - 1);
}

bool movimentoCaptura(int board[9][8],int x[4], int turn) {
    if (NextChainValid(board, x) == 1){
        return (x[3] == x[1] + 2 || x[3] == x[1] - 2) && (x[4] == x[2] + 2 || x[4] == x[2] - 2);
    }
    else {
        return false;
    }
}

void atualizarTabuleiro(int board[9][8], int x[4], int turn, int peshka[2]) {
    board[x[1]][x[2]] = 0;
    board[x[3]][x[4]] = turn;
    int x2 = (x[1] + x[3]) / 2;
    int y2 = (x[2] + x[4]) / 2;
    if (abs(x[1] - x[3]) == 2) {
        board[x2][y2] = 0;
        peshka[(turn == 1 || turn == 3) ? 1 : 0]--;
    }
}

void get_co(int board[9][8], int turn, int peshka[2]) {
    int x[4];
    bool moveValido = false;
    while (!moveValido) {
        cout << ((turn % 2 == 1) ? "x's turn." : "o's turn.") << endl;
        lerJogadas(x);
        if (JogadaValida(board, x)) {
            if (movimentoSimples(x, turn)) {
                atualizarTabuleiro(board, x, turn, peshka);
                Check_if_became_queen(x[3], x[4], board, turn);
                moveValido = true;
            } 
            else if (movimentoCaptura(board, x, turn)) {
                atualizarTabuleiro(board, x, turn, peshka);
                Check_if_became_queen(x[3], x[4], board, turn);
                moveValido = true;
            } 
            else {
                cout << "Movimento inválido. Tente novamente." << endl;
            }
        }
    }
}

int Winner(int x, int o)
{
    if(x==0)
    {
        cout << "O won!" << endl;
        return 1;
    }
    else if(o==0)
    {
        cout << "X won!" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() {
    int board[9][8]={0}, turn=1, peshka[2]={12,12};
    set_defaults(board);
    print_board(board);
    
    while (true) {
        get_co(board, turn, peshka);
        print_board(board);
        if (Winner(peshka[0], peshka[1])) {
            break;
        }
        turn = (turn == 1) ? 2 : 1;
    }

}
