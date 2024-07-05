#include "../include/player_controller.hpp"

#include <iostream>

int main() {
    PlayerController* controller = new PlayerController();

    controller->removePlayerByIndex(1);

    cout << "\nPRINTANDO...\n" << endl;
    controller->printPlayersByName();

    cout << "\nADICIONANDO NOVOS PLAYERS...\n" << endl;
    Player player1 = Player("a - primeiro nome", "d-ultimoNick");
    controller->insertNewPlayer(player1);
    Player player2 = Player("d - ultimo nome", "a-primeiroNick");
    controller->insertNewPlayer(player2);

    cout << "\nPRINTANDO...\n" << endl;
    controller->printPlayersByNickname();

    controller->endProcess();

    return 0;
}