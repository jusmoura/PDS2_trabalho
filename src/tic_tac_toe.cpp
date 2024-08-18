#include "../include/tic_tac_toe.hpp"


TicTacToe::TicTacToe():Board(3,3),currentPlayer(PLAYER_X){}

bool TicTacToe::checkVictory() {
    for (int i = 0;i < 3;i++) {
        if (_board[i][0].getValue() == currentPlayer && _board[i][1].getValue() == currentPlayer && _board[i][2].getValue() == currentPlayer)
            return true;    
        if (_board[0][i].getValue() == currentPlayer && _board[1][i].getValue() == currentPlayer && _board[2][i].getValue() == currentPlayer)
            return true; 
    }
    if (_board[0][0].getValue() == currentPlayer && _board[1][1].getValue() == currentPlayer && _board[2][2].getValue() == currentPlayer)
        return true;
    if (_board[0][2].getValue() == currentPlayer && _board[1][1].getValue() == currentPlayer && _board[2][0].getValue() == currentPlayer)
        return true;
    return false;    
}

bool TicTacToe::checkTie() {
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            if (_board[i][j].getValue() == EMPTY)
                return false;
        }
    }
    return true;
}

bool TicTacToe::validMove(int line, int column) {
    if (_board[line][column].getValue()!=EMPTY||line<0||column<0||line>=3||column>=3)
        return false;
    
}

void TicTacToe::switchPlayer() {
    if (currentPlayer == PLAYER_X)
        currentPlayer = PLAYER_O;
    else
        currentPlayer = PLAYER_X;
}

void TicTacToe::makeMove(int row, int column) {
    if (validMove(row, column)){
        _board[row][column].setValue(currentPlayer);
    }    
    else
        makeMove(row, column);
}

Player* TicTacToe::play(Player* player1,Player* player2) {
    Player* currentPlayerPtr=player1;
    Player* otherPlayerPtr=player2;

    string player1Nickname=player1->getNickname();
    string player2Nickname=player2->getNickname();    

    
    Board::printBoard();
    while (!checkVictory() && !checkTie()) {
        int row;
        int column;
        std::cout<<(currentPlayerPtr==player1? player1Nickname:player2Nickname)<<": insira [linha coluna]"<<std::endl;
        std::cin>>row>>column;
        makeMove(row, column);
        Board::printBoard();
        if (checkVictory()) {
            std::cout<<"PARABENS "<<currentPlayerPtr->getNickname()<<",VOCÊ GANHOU!"<<std::endl;
            return currentPlayerPtr;
            break;
        }
        else if (checkTie()) {
            std::cout<<"O jogo terminou em empate!"<<std::endl;
            break;
        }
        switchPlayer();
        std::swap(currentPlayerPtr,otherPlayerPtr);
    }
    std::cout << "game over" <<std::endl;
}