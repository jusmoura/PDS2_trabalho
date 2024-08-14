#include "../include/interface.hpp"

int main() {
    Interface interface;

    try {
        interface.mainMenu();
    }
    catch (const char* e) {
        cout << "Encerrou a main";
        return 0;
    }
}