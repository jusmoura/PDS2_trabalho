#include "../include/player_controller.hpp"

#include <iostream>

using namespace std;

int main() {
    PlayerController* controller = new PlayerController();

    controller->printPlayers();
    cout << "\nADICIONANDO PLAYERS...\n" << endl;
    Player player1 = Player("Joao", "Jow");
    controller->insertPlayer(player1);
    Player player2 = Player("Maria", "Mah");
    controller->insertPlayer(player2);
    controller->printPlayers();

    controller->endProcess();

    return 0;
}