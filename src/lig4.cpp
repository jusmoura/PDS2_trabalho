#include "../include/lig4.hpp"

Lig4::Lig4():Board(6,7),currentPlayer(PLAYER_X){}

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

bool Lig4::checkVictory() {
    for (int i = 0;i < 6;i++) {
        for (int j = 0;j < 7;j++) {
            if (_board[i][j].getValue() == currentPlayer && _board[i][j+1].getValue() == currentPlayer && _board[i][j+2].getValue() == currentPlayer && _board[i][j+3].getValue() == currentPlayer)
                return true;
            else if (_board[i][j].getValue() == currentPlayer && _board[i+1][j].getValue() == currentPlayer && _board[i+2][j].getValue() == currentPlayer && _board[i+3][j].getValue() == currentPlayer)
                return true;
            else if (_board[i][j].getValue() == currentPlayer && _board[i+1][j+1].getValue() == currentPlayer && _board[i+2][j+2].getValue() == currentPlayer && _board[i+3][j+3].getValue() == currentPlayer)
                return true;
            else if (_board[i][j].getValue() == currentPlayer && _board[i-1][j+1].getValue() == currentPlayer && _board[i-2][j+2].getValue() == currentPlayer && _board[i-3][j+3].getValue() == currentPlayer)
                return true;
        }
    }
    return false;
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