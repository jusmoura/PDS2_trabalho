#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include "player_controller.hpp"

#include <iostream>
#include <fstream>
#include <string>

class PlayerController;

class DatabaseController {
private:
    string _filePath;
    ifstream _inputFile;
    ofstream _outputFile;

public:
    DatabaseController();
    void readFile(PlayerController* playerController);
    void writeFile(PlayerController* playerController);
};

#endif //DATABASE_CONTROLLER_H