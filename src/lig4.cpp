#include <iostream>
using namespace std;

void makeTab(char tab[6][7]) {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 7;j++) {
            tab[i][j] = '?';
        }
    }
}

void printTab(char tab[6][7]) {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 7;j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}
void makePlayRed(char tab[6][7]) {
    int col;
    cin >> col;
    if (tab[5][col] == '?')
        tab[5][col] = 'r';
    else if (tab[4][col] == '?')
        tab[4][col] = 'r';
    else if (tab[3][col] == '?')
        tab[3][col] = 'r';
    else if (tab[2][col] == '?')
        tab[2][col] = 'r';
    else if (tab[1][col] == '?')
        tab[1][col] = 'r';
    else if (tab[0][col] == '?')
        tab[0][col] = 'r';
    else
        makePlayRed(tab);
}

void makePlayBlue(char tab[6][7]) {
    int col;
    cin >> col;
    if (tab[5][col] == '?')
        tab[5][col] = 'b';
    else if (tab[4][col] == '?')
        tab[4][col] = 'b';
    else if (tab[3][col] == '?')
        tab[3][col] = 'b';
    else if (tab[2][col] == '?')
        tab[2][col] = 'b';
    else if (tab[1][col] == '?')
        tab[1][col] = 'b';
    else if (tab[0][col] == '?')
        tab[0][col] = 'b';
    else
        makePlayBlue(tab);
}

bool checkWinRed(char tab[6][7], char playerRed = 'r') {

    if (tab[0][0] == playerRed && tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2] && tab[0][2] == tab[0][3])
        cout << "red wins" << endl;
    else if (tab[0][1] == playerRed && tab[0][1] == tab[0][2] && tab[0][2] == tab[0][3] && tab[0][3] == tab[0][4])
        cout << "red wins" << endl;
    else if (tab[0][2] == playerRed && tab[0][2] == tab[0][3] && tab[0][3] == tab[0][4] && tab[0][4] == tab[0][5])
        cout << "red wins" << endl;
    else if (tab[0][3] == playerRed && tab[0][3] == tab[0][4] && tab[0][4] == tab[0][5] && tab[0][5] == tab[0][6])
        cout << "red wins" << endl;

    else if (tab[1][0] == playerRed && tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2] && tab[1][2] == tab[1][3])
        cout << "red wins" << endl;
    else if (tab[1][1] == playerRed && tab[1][1] == tab[1][2] && tab[1][2] == tab[1][3] && tab[1][3] == tab[1][4])
        cout << "red wins" << endl;
    else if (tab[1][2] == playerRed && tab[1][2] == tab[1][3] && tab[1][3] == tab[1][4] && tab[1][4] == tab[1][5])
        cout << "red wins" << endl;
    else if (tab[1][3] == playerRed && tab[1][3] == tab[1][4] && tab[1][4] == tab[1][5] && tab[1][5] == tab[1][6])
        cout << "red wins" << endl;

    else if (tab[2][0] == playerRed && tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2] && tab[2][2] == tab[2][3])
        cout << "red wins" << endl;
    else if (tab[2][1] == playerRed && tab[2][1] == tab[2][2] && tab[2][2] == tab[2][3] && tab[2][3] == tab[2][4])
        cout << "red wins" << endl;
    else if (tab[2][2] == playerRed && tab[2][2] == tab[2][3] && tab[2][3] == tab[2][4] && tab[2][4] == tab[2][5])
        cout << "red wins" << endl;
    else if (tab[2][3] == playerRed && tab[2][3] == tab[2][4] && tab[2][4] == tab[2][5] && tab[2][5] == tab[2][6])
        cout << "red wins" << endl;

    else if (tab[3][0] == playerRed && tab[3][0] == tab[3][1] && tab[3][1] == tab[3][2] && tab[3][2] == tab[3][3])
        cout << "red wins" << endl;
    else if (tab[3][1] == playerRed && tab[3][1] == tab[3][2] && tab[3][2] == tab[3][3] && tab[3][3] == tab[3][4])
        cout << "red wins" << endl;
    else if (tab[3][2] == playerRed && tab[3][2] == tab[3][3] && tab[3][3] == tab[3][4] && tab[3][4] == tab[3][5])
        cout << "red wins" << endl;
    else if (tab[3][3] == playerRed && tab[3][3] == tab[3][4] && tab[3][4] == tab[3][5] && tab[3][5] == tab[3][6])
        cout << "red wins" << endl;

    else if (tab[4][0] == playerRed && tab[4][0] == tab[4][1] && tab[4][1] == tab[4][2] && tab[4][2] == tab[4][3])
        cout << "red wins" << endl;
    else if (tab[4][1] == playerRed && tab[4][1] == tab[4][2] && tab[4][2] == tab[4][3] && tab[4][3] == tab[4][4])
        cout << "red wins" << endl;
    else if (tab[4][2] == playerRed && tab[4][2] == tab[4][3] && tab[4][3] == tab[4][4] && tab[4][4] == tab[4][5])
        cout << "red wins" << endl;
    else if (tab[4][3] == playerRed && tab[4][3] == tab[4][4] && tab[4][4] == tab[4][5] && tab[4][5] == tab[4][6])
        cout << "red wins" << endl;

    else if (tab[5][0] == playerRed && tab[5][0] == tab[5][1] && tab[5][1] == tab[5][2] && tab[5][2] == tab[5][3])
        cout << "red wins" << endl;
    else if (tab[5][1] == playerRed && tab[5][1] == tab[5][2] && tab[5][2] == tab[5][3] && tab[5][3] == tab[5][4])
        cout << "red wins" << endl;
    else if (tab[5][2] == playerRed && tab[5][2] == tab[5][3] && tab[5][3] == tab[5][4] && tab[5][4] == tab[5][5])
        cout << "red wins" << endl;
    else if (tab[5][3] == playerRed && tab[5][3] == tab[5][4] && tab[5][4] == tab[5][5] && tab[5][5] == tab[5][6])
        cout << "red wins" << endl;

    else if (tab[0][0] == playerRed && tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0] && tab[2][0] == tab[3][0])
        cout << "red wins" << endl;
    else if (tab[1][0] == playerRed && tab[1][0] == tab[2][0] && tab[2][0] == tab[3][0] && tab[3][0] == tab[4][0])
        cout << "red wins" << endl;
    else if (tab[2][0] == playerRed && tab[2][0] == tab[3][0] && tab[3][0] == tab[4][0] && tab[4][0] == tab[5][0])
        cout << "red wins" << endl;

    else if (tab[0][1] == playerRed && tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1] && tab[2][1] == tab[3][1])
        cout << "red wins" << endl;
    else if (tab[1][1] == playerRed && tab[1][1] == tab[2][1] && tab[2][1] == tab[3][1] && tab[3][1] == tab[4][1])
        cout << "red wins" << endl;
    else if (tab[2][1] == playerRed && tab[2][1] == tab[3][1] && tab[3][1] == tab[4][1] && tab[4][1] == tab[5][1])
        cout << "red wins" << endl;

    else if (tab[0][2] == playerRed && tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2] && tab[2][2] == tab[3][2])
        cout << "red wins" << endl;
    else if (tab[1][2] == playerRed && tab[1][2] == tab[2][2] && tab[2][2] == tab[3][2] && tab[3][2] == tab[4][2])
        cout << "red wins" << endl;
    else if (tab[2][2] == playerRed && tab[2][2] == tab[3][2] && tab[3][2] == tab[4][2] && tab[4][2] == tab[5][2])
        cout << "red wins" << endl;

    else if (tab[0][3] == playerRed && tab[0][3] == tab[1][3] && tab[1][3] == tab[2][3] && tab[2][3] == tab[3][3])
        cout << "red wins" << endl;
    else if (tab[1][3] == playerRed && tab[1][3] == tab[2][3] && tab[2][3] == tab[3][3] && tab[3][3] == tab[4][3])
        cout << "red wins" << endl;
    else if (tab[2][3] == playerRed && tab[2][3] == tab[3][3] && tab[3][3] == tab[4][3] && tab[4][3] == tab[5][3])
        cout << "red wins" << endl;

    else if (tab[0][4] == playerRed && tab[0][4] == tab[1][4] && tab[1][4] == tab[2][4] && tab[2][4] == tab[3][4])
        cout << "red wins" << endl;
    else if (tab[1][4] == playerRed && tab[1][4] == tab[2][4] && tab[2][4] == tab[3][4] && tab[3][4] == tab[4][4])
        cout << "red wins" << endl;
    else if (tab[2][4] == playerRed && tab[2][4] == tab[3][4] && tab[3][4] == tab[4][4] && tab[4][4] == tab[5][4])
        cout << "red wins" << endl;

    else if (tab[0][5] == playerRed && tab[0][5] == tab[1][5] && tab[1][5] == tab[2][5] && tab[2][5] == tab[3][5])
        cout << "red wins" << endl;
    else if (tab[1][5] == playerRed && tab[1][5] == tab[2][5] && tab[2][5] == tab[3][5] && tab[3][5] == tab[4][5])
        cout << "red wins" << endl;
    else if (tab[2][5] == playerRed && tab[2][5] == tab[3][5] && tab[3][5] == tab[4][5] && tab[4][5] == tab[5][5])
        cout << "red wins" << endl;

    else if (tab[0][6] == playerRed && tab[0][6] == tab[1][6] && tab[1][6] == tab[2][6] && tab[2][6] == tab[3][6])
        cout << "red wins" << endl;
    else if (tab[1][6] == playerRed && tab[1][6] == tab[2][6] && tab[2][6] == tab[3][6] && tab[3][6] == tab[4][6])
        cout << "red wins" << endl;
    else if (tab[2][6] == playerRed && tab[2][6] == tab[3][6] && tab[3][6] == tab[4][6] && tab[4][6] == tab[5][6])
        cout << "red wins" << endl;

    else if (tab[0][0] == playerRed && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[2][2] == tab[3][3])
        cout << "red wins" << endl;
    else if (tab[1][1] == playerRed && tab[1][1] == tab[2][2] && tab[2][2] == tab[3][3] && tab[3][3] == tab[4][4])
        cout << "red wins" << endl;
    else if (tab[2][2] == playerRed && tab[2][2] == tab[3][3] && tab[3][3] == tab[4][4] && tab[4][4] == tab[5][5])
        cout << "red wins" << endl;

    else if (tab[2][0] == playerRed && tab[2][0] == tab[3][1] && tab[3][1] == tab[4][2] && tab[4][2] == tab[5][3])
        cout << "red wins" << endl;
    else if (tab[1][0] == playerRed && tab[1][0] == tab[2][1] && tab[2][1] == tab[3][2] && tab[3][2] == tab[4][3])
        cout << "red wins" << endl;
    else if (tab[2][1] == playerRed && tab[2][1] == tab[3][2] && tab[3][2] == tab[4][3] && tab[4][3] == tab[5][4])
        cout << "red wins" << endl;

    else if (tab[0][1] == playerRed && tab[0][1] == tab[1][2] && tab[1][2] == tab[2][3] && tab[2][3] == tab[3][4])
        cout << "red wins" << endl;
    else if (tab[1][2] == playerRed && tab[1][2] == tab[2][3] && tab[2][3] == tab[3][4] && tab[3][4] == tab[4][5])
        cout << "red wins" << endl;
    else if (tab[2][3] == playerRed && tab[2][3] == tab[3][4] && tab[3][4] == tab[4][5] && tab[4][5] == tab[5][6])
        cout << "red wins" << endl;

    else if (tab[0][2] == playerRed && tab[0][2] == tab[1][3] && tab[1][3] == tab[2][4] && tab[2][4] == tab[3][5])
        cout << "red wins" << endl;
    else if (tab[1][3] == playerRed && tab[1][3] == tab[2][4] && tab[2][4] == tab[3][5] && tab[3][5] == tab[4][6])
        cout << "red wins" << endl;
    else if (tab[0][3] == playerRed && tab[0][3] == tab[1][4] && tab[1][4] == tab[2][5] && tab[2][5] == tab[3][6])
        cout << "red wins" << endl;

    else if (tab[0][6] == playerRed && tab[0][6] == tab[1][5] && tab[1][5] == tab[2][4] && tab[2][4] == tab[3][3])
        cout << "red wins" << endl;
    else if (tab[1][5] == playerRed && tab[1][5] == tab[2][4] && tab[2][4] == tab[3][3] && tab[3][3] == tab[4][2])
        cout << "red wins" << endl;
    else if (tab[2][4] == playerRed && tab[2][4] == tab[3][3] && tab[3][3] == tab[4][2] && tab[4][2] == tab[5][1])
        cout << "red wins" << endl;

    else if (tab[1][6] == playerRed && tab[1][6] == tab[2][5] && tab[2][5] == tab[3][4] && tab[3][4] == tab[4][3])
        cout << "red wins" << endl;
    else if (tab[2][6] == playerRed && tab[2][6] == tab[3][5] && tab[3][5] == tab[4][4] && tab[4][4] == tab[5][3])
        cout << "red wins" << endl;
    else if (tab[0][5] == playerRed && tab[0][5] == tab[1][4] && tab[1][4] == tab[2][3] && tab[2][3] == tab[3][2])
        cout << "red wins" << endl;

    else if (tab[1][4] == playerRed && tab[1][4] == tab[2][3] && tab[2][3] == tab[3][2] && tab[3][2] == tab[4][1])
        cout << "red wins" << endl;
    else if (tab[2][3] == playerRed && tab[2][3] == tab[3][2] && tab[3][2] == tab[4][1] && tab[4][1] == tab[5][0])
        cout << "red wins" << endl;
    else if (tab[0][3] == playerRed && tab[0][3] == tab[1][2] && tab[1][2] == tab[2][1] && tab[2][1] == tab[3][0])
        cout << "red wins" << endl;

    else
        return false;
    return true;
}

bool checkWinBlue(char tab[6][7], char playerBlue = 'b') {
    if (tab[0][0] == playerBlue && tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2] && tab[0][2] == tab[0][3])
        cout << "blue wins" << endl;
    else if (tab[0][1] == playerBlue && tab[0][1] == tab[0][2] && tab[0][2] == tab[0][3] && tab[0][3] == tab[0][4])
        cout << "blue wins" << endl;
    else if (tab[0][2] == playerBlue && tab[0][2] == tab[0][3] && tab[0][3] == tab[0][4] && tab[0][4] == tab[0][5])
        cout << "blue wins" << endl;
    else if (tab[0][3] == playerBlue && tab[0][3] == tab[0][4] && tab[0][4] == tab[0][5] && tab[0][5] == tab[0][6])
        cout << "blue wins" << endl;

    else if (tab[1][0] == playerBlue && tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2] && tab[1][2] == tab[1][3])
        cout << "blue wins" << endl;
    else if (tab[1][1] == playerBlue && tab[1][1] == tab[1][2] && tab[1][2] == tab[1][3] && tab[1][3] == tab[1][4])
        cout << "blue wins" << endl;
    else if (tab[1][2] == playerBlue && tab[1][2] == tab[1][3] && tab[1][3] == tab[1][4] && tab[1][4] == tab[1][5])
        cout << "blue wins" << endl;
    else if (tab[1][3] == playerBlue && tab[1][3] == tab[1][4] && tab[1][4] == tab[1][5] && tab[1][5] == tab[1][6])
        cout << "blue wins" << endl;

    else if (tab[2][0] == playerBlue && tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2] && tab[2][2] == tab[2][3])
        cout << "blue wins" << endl;
    else if (tab[2][1] == playerBlue && tab[2][1] == tab[2][2] && tab[2][2] == tab[2][3] && tab[2][3] == tab[2][4])
        cout << "blue wins" << endl;
    else if (tab[2][2] == playerBlue && tab[2][2] == tab[2][3] && tab[2][3] == tab[2][4] && tab[2][4] == tab[2][5])
        cout << "blue wins" << endl;
    else if (tab[2][3] == playerBlue && tab[2][3] == tab[2][4] && tab[2][4] == tab[2][5] && tab[2][5] == tab[2][6])
        cout << "blue wins" << endl;

    else if (tab[3][0] == playerBlue && tab[3][0] == tab[3][1] && tab[3][1] == tab[3][2] && tab[3][2] == tab[3][3])
        cout << "blue wins" << endl;
    else if (tab[3][1] == playerBlue && tab[3][1] == tab[3][2] && tab[3][2] == tab[3][3] && tab[3][3] == tab[3][4])
        cout << "blue wins" << endl;
    else if (tab[3][2] == playerBlue && tab[3][2] == tab[3][3] && tab[3][3] == tab[3][4] && tab[3][4] == tab[3][5])
        cout << "blue wins" << endl;
    else if (tab[3][3] == playerBlue && tab[3][3] == tab[3][4] && tab[3][4] == tab[3][5] && tab[3][5] == tab[3][6])
        cout << "blue wins" << endl;

    else if (tab[4][0] == playerBlue && tab[4][0] == tab[4][1] && tab[4][1] == tab[4][2] && tab[4][2] == tab[4][3])
        cout << "blue wins" << endl;
    else if (tab[4][1] == playerBlue && tab[4][1] == tab[4][2] && tab[4][2] == tab[4][3] && tab[4][3] == tab[4][4])
        cout << "blue wins" << endl;
    else if (tab[4][2] == playerBlue && tab[4][2] == tab[4][3] && tab[4][3] == tab[4][4] && tab[4][4] == tab[4][5])
        cout << "blue wins" << endl;
    else if (tab[4][3] == playerBlue && tab[4][3] == tab[4][4] && tab[4][4] == tab[4][5] && tab[4][5] == tab[4][6])
        cout << "blue wins" << endl;

    else if (tab[5][0] == playerBlue && tab[5][0] == tab[5][1] && tab[5][1] == tab[5][2] && tab[5][2] == tab[5][3])
        cout << "blue wins" << endl;
    else if (tab[5][1] == playerBlue && tab[5][1] == tab[5][2] && tab[5][2] == tab[5][3] && tab[5][3] == tab[5][4])
        cout << "blue wins" << endl;
    else if (tab[5][2] == playerBlue && tab[5][2] == tab[5][3] && tab[5][3] == tab[5][4] && tab[5][4] == tab[5][5])
        cout << "blue wins" << endl;
    else if (tab[5][3] == playerBlue && tab[5][3] == tab[5][4] && tab[5][4] == tab[5][5] && tab[5][5] == tab[5][6])
        cout << "blue wins" << endl;

    else if (tab[0][0] == playerBlue && tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0] && tab[2][0] == tab[3][0])
        cout << "blue wins" << endl;
    else if (tab[1][0] == playerBlue && tab[1][0] == tab[2][0] && tab[2][0] == tab[3][0] && tab[3][0] == tab[4][0])
        cout << "blue wins" << endl;
    else if (tab[2][0] == playerBlue && tab[2][0] == tab[3][0] && tab[3][0] == tab[4][0] && tab[4][0] == tab[5][0])
        cout << "blue wins" << endl;

    else if (tab[0][1] == playerBlue && tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1] && tab[2][1] == tab[3][1])
        cout << "blue wins" << endl;
    else if (tab[1][1] == playerBlue && tab[1][1] == tab[2][1] && tab[2][1] == tab[3][1] && tab[3][1] == tab[4][1])
        cout << "blue wins" << endl;
    else if (tab[2][1] == playerBlue && tab[2][1] == tab[3][1] && tab[3][1] == tab[4][1] && tab[4][1] == tab[5][1])
        cout << "blue wins" << endl;

    else if (tab[0][2] == playerBlue && tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2] && tab[2][2] == tab[3][2])
        cout << "blue wins" << endl;
    else if (tab[1][2] == playerBlue && tab[1][2] == tab[2][2] && tab[2][2] == tab[3][2] && tab[3][2] == tab[4][2])
        cout << "blue wins" << endl;
    else if (tab[2][2] == playerBlue && tab[2][2] == tab[3][2] && tab[3][2] == tab[4][2] && tab[4][2] == tab[5][2])
        cout << "blue wins" << endl;

    else if (tab[0][3] == playerBlue && tab[0][3] == tab[1][3] && tab[1][3] == tab[2][3] && tab[2][3] == tab[3][3])
        cout << "blue wins" << endl;
    else if (tab[1][3] == playerBlue && tab[1][3] == tab[2][3] && tab[2][3] == tab[3][3] && tab[3][3] == tab[4][3])
        cout << "blue wins" << endl;
    else if (tab[2][3] == playerBlue && tab[2][3] == tab[3][3] && tab[3][3] == tab[4][3] && tab[4][3] == tab[5][3])
        cout << "blue wins" << endl;

    else if (tab[0][4] == playerBlue && tab[0][4] == tab[1][4] && tab[1][4] == tab[2][4] && tab[2][4] == tab[3][4])
        cout << "blue wins" << endl;
    else if (tab[1][4] == playerBlue && tab[1][4] == tab[2][4] && tab[2][4] == tab[3][4] && tab[3][4] == tab[4][4])
        cout << "blue wins" << endl;
    else if (tab[2][4] == playerBlue && tab[2][4] == tab[3][4] && tab[3][4] == tab[4][4] && tab[4][4] == tab[5][4])
        cout << "blue wins" << endl;

    else if (tab[0][5] == playerBlue && tab[0][5] == tab[1][5] && tab[1][5] == tab[2][5] && tab[2][5] == tab[3][5])
        cout << "blue wins" << endl;
    else if (tab[1][5] == playerBlue && tab[1][5] == tab[2][5] && tab[2][5] == tab[3][5] && tab[3][5] == tab[4][5])
        cout << "blue wins" << endl;
    else if (tab[2][5] == playerBlue && tab[2][5] == tab[3][5] && tab[3][5] == tab[4][5] && tab[4][5] == tab[5][5])
        cout << "blue wins" << endl;

    else if (tab[0][6] == playerBlue && tab[0][6] == tab[1][6] && tab[1][6] == tab[2][6] && tab[2][6] == tab[3][6])
        cout << "blue wins" << endl;
    else if (tab[1][6] == playerBlue && tab[1][6] == tab[2][6] && tab[2][6] == tab[3][6] && tab[3][6] == tab[4][6])
        cout << "blue wins" << endl;
    else if (tab[2][6] == playerBlue && tab[2][6] == tab[3][6] && tab[3][6] == tab[4][6] && tab[4][6] == tab[5][6])
        cout << "blue wins" << endl;

    else if (tab[0][6] == playerBlue && tab[0][6] == tab[1][5] && tab[1][5] == tab[2][4] && tab[2][4] == tab[3][3])
        cout << "blue wins" << endl;
    else if (tab[1][5] == playerBlue && tab[1][5] == tab[2][4] && tab[2][4] == tab[3][3] && tab[3][3] == tab[4][2])
        cout << "blue wins" << endl;
    else if (tab[2][4] == playerBlue && tab[2][4] == tab[3][3] && tab[3][3] == tab[4][2] && tab[4][2] == tab[5][1])
        cout << "blue wins" << endl;

    else if (tab[1][6] == playerBlue && tab[1][6] == tab[2][5] && tab[2][5] == tab[3][4] && tab[3][4] == tab[4][3])
        cout << "blue wins" << endl;
    else if (tab[2][6] == playerBlue && tab[2][6] == tab[3][5] && tab[3][5] == tab[4][4] && tab[4][4] == tab[5][3])
        cout << "blue wins" << endl;
    else if (tab[0][5] == playerBlue && tab[0][5] == tab[1][4] && tab[1][4] == tab[2][3] && tab[2][3] == tab[3][2])
        cout << "blue wins" << endl;

    else if (tab[1][4] == playerBlue && tab[1][4] == tab[2][3] && tab[2][3] == tab[3][2] && tab[3][2] == tab[4][1])
        cout << "blue wins" << endl;
    else if (tab[2][3] == playerBlue && tab[2][3] == tab[3][2] && tab[3][2] == tab[4][1] && tab[4][1] == tab[5][0])
        cout << "blue wins" << endl;
    else if (tab[0][3] == playerBlue && tab[0][3] == tab[1][2] && tab[1][2] == tab[2][1] && tab[2][1] == tab[3][0])
        cout << "blue wins" << endl;

    else
        return false;
    return true;

}

bool checkTie(char tab[6][7]) {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 7;j++) {
            if (tab[i][j] == '?')
                return false;
        }
    }
    return true;
}

// int main() {
//     char tab[6][7];
//     makeTab(tab);
//     printTab(tab);
//     char playerRed='r';
//     char playerBlue='b';
//     while(!checkWinRed(tab,playerRed) && !checkWinBlue(tab,playerBlue)&& !checkTie(tab)){
//         cout<<"Red play"<<endl;
//         makePlayRed(tab);
//         printTab(tab);
//         if(checkWinRed(tab,playerRed))
//             break;
//         if(checkTie(tab))
//             break;
//         cout<<"----------"<<endl;
//         cout<<"Blue play"<<endl;
//         makePlayBlue(tab);
//         printTab(tab);
//         if(checkWinBlue(tab,playerRed))
//             break;
//         if(checkTie(tab))
//             break;
//         cout<<"----------"<<endl;
//     }
//     return 0;
// }