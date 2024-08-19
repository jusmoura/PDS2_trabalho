#include "../include/lig4.hpp"

Lig4::Lig4():Board(6,7),currentPlayer(PLAYER_X){}

bool Lig4::checkVictory() {
    //Itera por todas as casas do tabuleiro; de baixo para cima, da esquerda para a direita
    for (int line = linesSize - 1; line >= 0; line--) {
        for (int col = 0; col < columnsSize; col++) {
            //Verificando vitórias
            int player = _board[line][col].getValue();
            int sum = 1;
            //Verificação horizontal
            for (int i = 1; col + i < columnsSize; i++) {
                if (Board::validateMove(line, col + i) && _board[line][col + i].getValue() != EMPTY) {
                    if (_board[line][col + i].getValue() == player)
                        sum++;
                    else
                        break;
                }
                else
                    break;
            }
            if (sum == 4)
                return true;
            else
                sum = 1;

            //Verificação Vertical
            for (int i = 1; line - i >= 0; i++) {
                if (Board::validateMove(line - i, col) && _board[line - i][col].getValue() != EMPTY) {
                    if (_board[line - i][col].getValue() == player)
                        sum++;
                    else
                        break;
                }
                else
                    break;
            }
            if (sum == 4)
                return true;
            else
                sum = 1;

            //Verificação Diagonal Superior Direita
            for (int i = 1; line - i >= 0; i++) {
                if (Board::validateMove(line - i, col + i) && _board[line - i][col + i].getValue() != EMPTY) {
                    if (_board[line - i][col + i].getValue() == player)
                        sum++;
                    else
                        break;
                }
                else
                    break;
            }
            if (sum == 4)
                return true;
            else
                sum = 1;

            //Verificação Diagonal Superior Esquerda
            for (int i = 1; line - i >= 0; i++) {
                if (Board::validateMove(line - i, col - i) && _board[line - i][col - i].getValue() != EMPTY) {
                    if (_board[line - i][col - i].getValue() == player)
                        sum++;
                    else
                        break;
                }
                else
                    break;
            }
            if (sum == 4)
                return true;
            else
                sum = 1;
        }
    }
    return false;
}

void Lig4::switchPlayer() {
    if (currentPlayer == PLAYER_X)
        currentPlayer = PLAYER_O;
    else
        currentPlayer = PLAYER_X;
}

void Lig4::makeMove(int column) {
    if(column>0 && column<7){
        if (_board[0][column].getValue() == EMPTY)
            _board[0][column].setValue(currentPlayer);
        else if (_board[1][column].getValue() == EMPTY)
            _board[1][column].setValue(currentPlayer);
        else if (_board[2][column].getValue() == EMPTY)
            _board[2][column].setValue(currentPlayer);
        else if (_board[3][column].getValue() == EMPTY)
            _board[3][column].setValue(currentPlayer);
        else if (_board[4][column].getValue() == EMPTY)
            _board[4][column].setValue(currentPlayer);
        else if (_board[5][column].getValue() == EMPTY)
            _board[5][column].setValue(currentPlayer);
            
    }
    else
        makeMove(column);    
}

bool Lig4::checkTie() {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 7;j++) {
            if (_board[i][j].getValue() == EMPTY)
                return false;
        }
    }
    return true;
}

Player* Lig4::play(Player* player1,Player* player2) {
    Player* currentPlayerPtr=player1;
    Player* otherPlayerPtr=player2;

    string player1Nickname=player1->getNickname();
    string player2Nickname=player2->getNickname();

    Board::printBoard();
    int column;

    while (!checkVictory() && !checkTie()) {
        std::cout<<(currentPlayerPtr==player1? player1Nickname:player2Nickname)<<": insira [coluna]"<<std::endl;
        std::cin>>column;
        makeMove(column);
        Board::printBoard();
        if (checkVictory()){
            std::cout<<"PARABENS "<<currentPlayerPtr->getNickname()<<",VOCÊ GANHOU!"<<std::endl;
            return currentPlayerPtr;
            break;
        }
            
        if (checkTie()){
            std::cout<<"O jogo terminou em empate!"<<std::endl;
            break;
        }
        switchPlayer();
        std::swap(currentPlayerPtr,otherPlayerPtr);
    }
    
}