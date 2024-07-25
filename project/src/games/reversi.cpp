#include "reversi.hpp"

const int BOARD_SIZE = 9;

class Board {
public:
    std::vector<std::vector<char>> grid;

    Board() {
        grid = std::vector<std::vector<char>>(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));
        initialize();
    }

    void initialize() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                grid[i][j] = ' ';
            }
        }
        grid[4][4] = 'O';
        grid[5][4] = 'X';
        grid[4][5] = 'X';
        grid[5][5] = 'O';
    }

    void display() {
        std::cout << "   ";
        for (int j = 1; j < BOARD_SIZE; ++j) {
            std::cout << " " << j << " ";
        }
        std::cout << std::endl;

        for (int i = 1; i < BOARD_SIZE; ++i) {
            std::cout << " " << i << " ";

            for (int j = 1; j < BOARD_SIZE; ++j) {
                std::cout << "[" << grid[i][j] << "]";
            }
            std::cout << std::endl;
        }
    }
};

class ReversiGame {
public:
    Board board;
    int sumX;
    int sumO;
    int hintsO;
    int hintsX;
    char currentPlayer;

    ReversiGame() : sumX(2), sumO(2), hintsO(2), hintsX(2), currentPlayer('X') {}


    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

   int validMove(int x, int y) {
    if (x < 1 || x >= BOARD_SIZE || y < 1 || y >= BOARD_SIZE || board.grid[x][y] != ' ')
        return 0;

    char opponent = (currentPlayer == 'X') ? 'O' : 'X';
    int totalFlips = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx, ny = y + dy;
            int flips = 0;
            bool foundOpponent = false;

            while (nx >= 1 && nx < BOARD_SIZE && ny >= 1 && ny < BOARD_SIZE && board.grid[nx][ny] == opponent) {
                foundOpponent = true;
                nx += dx;
                ny += dy;
                ++flips;
            }

            if (foundOpponent && nx >= 1 && nx < BOARD_SIZE && ny >= 1 && ny < BOARD_SIZE && board.grid[nx][ny] == currentPlayer) {
                totalFlips += flips;
            }
        }
    }

    return totalFlips;
}

    std::vector<std::pair<int, int>> help() {
        std::vector<std::pair<int, int>> validMoves;
        for (int a = 1; a < BOARD_SIZE; ++a) {
            for (int b = 1; b < BOARD_SIZE; ++b) {
                if (validMove(a, b)) {
                    validMoves.push_back({a, b});
                }
            }
        }
        return validMoves;
    }

    std::vector<std::pair<std::pair<int, int>, int>> hint() {
        std::vector<std::pair<std::pair<int, int>, int>> hints;

        for (int i = 1; i < BOARD_SIZE; ++i) {
            for (int j = 1; j < BOARD_SIZE; ++j) {
                if (board.grid[i][j] == ' ') {
                    int flips = validMove(i, j);
                    if (flips > 0) {
                        hints.push_back({{i, j}, flips});
                    }
                }
            }
        }
        return hints;
    }

    void makeMove(int x, int y) {
        if (validMove(x, y)) {
            board.grid[x][y] = currentPlayer;
            char opponent = (currentPlayer == 'X') ? 'O' : 'X';

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;

                    int nx = x + dx, ny = y + dy;
                    bool foundOpponent = false;
                    while (nx >= 1 && nx < BOARD_SIZE && ny >= 1 && ny < BOARD_SIZE && board.grid[nx][ny] == opponent) {
                        foundOpponent = true;
                        nx += dx;
                        ny += dy;
                    }
                    if (foundOpponent && nx >= 1 && nx < BOARD_SIZE && ny >= 1 && ny < BOARD_SIZE && board.grid[nx][ny] == currentPlayer) {
                        while (nx != x || ny != y) {
                            nx -= dx;
                            ny -= dy;
                            board.grid[nx][ny] = currentPlayer;
                        }
                    }
                }
            }

            calculateScore();
            switchPlayer();

        } else {
            std::cout << "Movimento inválido!" << std::endl;
        }
    }

    void calculateScore() {
        sumX = 0;
        sumO = 0;
        for (int i = 1; i < BOARD_SIZE; ++i) {
            for (int j = 1; j < BOARD_SIZE; ++j) {
                if (board.grid[i][j] == 'X') {
                    sumX++;
                } else if (board.grid[i][j] == 'O') {
                    sumO++;
                }
            }
        }
        std::cout << "Pontuação X: " << sumX << std::endl;
        std::cout << "Pontuação O: " << sumO << std::endl;
    }

    void play() {
        int x, y;
        std::string line;

        while (sumX + sumO < 64) {
            board.display();
            std::cout << "Jogador " << currentPlayer << ": [linha coluna]; 'help' para ajuda; 'hint' para dica: " << std::endl;
            std::getline(std::cin, line);

            if (line == "help") {
                std::vector<std::pair<int, int>> moves = help();
                std::cout << "Jogadas válidas:" << std::endl;
                for (const auto& move : moves) {
                    std::cout << "[" << move.first << " " << move.second << "]" << std::endl;
                }
                continue;
            } else if (line == "hint") {
                std::vector<std::pair<std::pair<int, int>, int>> hints = hint();
                std::cout << "[Jogadas válidas]:[Pontuação conquistada]" << std::endl;
                for (const auto& hint : hints) {
                    std::cout <<"      ["<< hint.first.first << " " << hint.first.second 
                    << "]"<<"     :         [" << hint.second << "]"<< std::endl;
                }
                if (currentPlayer == 'X') {
                    hintsX--;
                    std::cout << "      Você ainda tem " << hintsX << " dicas" << std::endl;
                } else {
                    hintsO--;
                    std::cout << "      Você ainda tem " << hintsO << " dicas" << std::endl;
                }
                continue;
            }

            std::stringstream ss(line);
            if (ss >> x >> y) {
                makeMove(x, y);
            } else {
                std::cout << "Entrada inválida!" << std::endl;
            }
        }

        board.display();
        if (sumX > sumO) {
            std::cout << "PARABÉNS X, VOCÊ GANHOU!" << std::endl;
        } else if (sumO > sumX) {
            std::cout << "PARABÉNS O, VOCÊ GANHOU!" << std::endl;
        } else {
            std::cout << "O jogo terminou em empate!" << std::endl;
        }
    }
};

int main() {
    ReversiGame game;
    game.play();
    return 0;
}