#include "../include/player_controller.hpp"

#include <iostream>

int main() {
    PlayerController* controller = new PlayerController();

    cout << "\nPRINTANDO...\n" << endl;
    controller->printPlayersByName();

    cout << "\nADICIONANDO NOVOS PLAYERS...\n" << endl;
    Player player2 = Player("d", "a-primeiroNick");
    controller->insertNewPlayer(player2);
    Player player1 = Player("a - primeiro nome", "z-ultimoNick");
    controller->insertNewPlayer(player1);

    cout << "\nPRINTANDO...\n" << endl;
    controller->printPlayersByName();
    controller->printPlayersByNickname();

    controller->endProcess();

    return 0;
}