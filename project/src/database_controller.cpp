#include "../include/database_controller.hpp"

DatabaseController::DatabaseController() {
    _filePath = "../database/players_data.txt";

    _inputFile.open(_filePath);
    if (!_inputFile.is_open())
        std::cout << "Falha na abertura do arquivo " << _filePath << std::endl;
}

void DatabaseController::readFile(PlayerController* playerController) {

    while (!_inputFile.eof()) {
        string name;
        string nickName;
        int num;

        std::getline(_inputFile, name);
        _inputFile >> nickName;

        Player player = Player(name, nickName);

        _inputFile >> num;
        player.setNumWins(REVERSI, num);
        _inputFile >> num;
        player.setNumDefeats(REVERSI, num);
        _inputFile >> num;
        player.setNumWins(LIG4, num);
        _inputFile >> num;
        player.setNumDefeats(LIG4, num);
        _inputFile >> num;
        player.setNumWins(TIC_TAC_TOE, num);
        _inputFile >> num;
        player.setNumDefeats(TIC_TAC_TOE, num);
        _inputFile >> num;
        player.setNumWins(MINESWEEPER, num);
        _inputFile >> num;
        player.setNumDefeats(MINESWEEPER, num);

        string buffer;
        std::getline(_inputFile, buffer);

        playerController->insertPlayer(player);
    }

    _inputFile.close();
}

void DatabaseController::writeFile(PlayerController* playerController) {
    _outputFile.open(_filePath);

    if (!_outputFile.is_open())
        std::cout << "Falha na abertura do arquivo " << _filePath << std::endl;

    int size = playerController->getTotalNumberOfPlayers();

    for (int i = 0; i < size; i++) {
        _outputFile << playerController->getPlayerByIndex(i).getName() << endl;
        _outputFile << playerController->getPlayerByIndex(i).getNickname() << endl;
        _outputFile << playerController->getPlayerByIndex(i).getNumWins(REVERSI) << " " << playerController->getPlayerByIndex(i).getNumDefeats(REVERSI) << endl;
        _outputFile << playerController->getPlayerByIndex(i).getNumWins(LIG4) << " " << playerController->getPlayerByIndex(i).getNumDefeats(LIG4) << endl;
        _outputFile << playerController->getPlayerByIndex(i).getNumWins(TIC_TAC_TOE) << " " << playerController->getPlayerByIndex(i).getNumDefeats(TIC_TAC_TOE) << endl;
        _outputFile << playerController->getPlayerByIndex(i).getNumWins(MINESWEEPER) << " " << playerController->getPlayerByIndex(i).getNumDefeats(MINESWEEPER);

        if (i != size - 1)
            _outputFile << endl;
    }

    _outputFile.close();
}