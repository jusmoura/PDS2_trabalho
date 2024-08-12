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
        //Tratamento para arquivo vazio
        if (name == "")
            break;

        _inputFile >> nickName;

        Player player = Player(name, nickName);

        vector<Game>* games = player.getGamesStats();
        int gamesSize = games->size();

        for (int i = 0; i < gamesSize; i++) {
            _inputFile >> num;
            games->at(i).setNumWins(num);
            _inputFile >> num;
            games->at(i).setNumDefeats(num);
        }

        string buffer;
        std::getline(_inputFile, buffer);

        playerController->insertNewPlayer(player);
    }

    _inputFile.close();
}

void DatabaseController::writeFile(PlayerController* playerController) {
    _outputFile.open(_filePath);

    if (!_outputFile.is_open())
        std::cout << "Falha na abertura do arquivo " << _filePath << std::endl;

    int playersSize = playerController->getTotalNumberOfPlayers();

    for (int i = 0; i < playersSize; i++) {
        Player* player = playerController->getPlayerByIndex(i);

        _outputFile << player->getName() << endl;
        _outputFile << player->getNickname() << endl;

        vector<Game>* games = player->getGamesStats();
        int gamesSize = games->size();

        for (int gameIndex = 0; gameIndex < gamesSize; gameIndex++) {
            _outputFile << player->getNumWins(gameIndex) << " " << player->getNumDefeats(gameIndex);

            if (i != playersSize - 1)
                _outputFile << endl;

            //Tratamento para a quebra de linha do ultimo jogo do ultimo player cadastrado
            else {
                if (gameIndex != gamesSize - 1)
                    _outputFile << endl;
            }
        }
    }

    _outputFile.close();
}