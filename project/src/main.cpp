#include "../include/player.hpp"

#include <iostream>

using namespace std;

int main() {
    Player* player1 = new Player("Pedro", "Piter");

    cout << "Número de vitórias no Reversi do player " << player1->getNickname() << ": " << player1->getNumWins(REVERSI) << endl;
    cout << "Número de derrotas no Reversi do player " << player1->getNickname() << ": " << player1->getNumDefeats(REVERSI) << endl;

    return 0;
}