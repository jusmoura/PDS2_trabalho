#include "../include/interface.hpp"

int main() {
    //Limpa o terminal (Windows || Linux)
    system("clear||cls");

    Interface interface;

    try {
        interface.mainMenu();
    }
    catch (const char* e) {
        std::cout << "\nSaindo...\n" << std::endl;
        return 0;
    }
}