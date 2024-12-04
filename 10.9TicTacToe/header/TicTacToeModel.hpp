#ifndef TICTACTOEMODEL_HPP
#define TICTACTOEMODEL_HPP

#include <vector>
#include <utility>
#include <iostream>

class TicTacToeModel {
private:
    std::vector<std::pair<int, int>> moves;
    int playerBool = 0; // player 0 is x; player 1 is o
    int WinningInt = 0;
    char board[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };

public:
    TicTacToeModel();

    char (*GetBoard())[3];

    bool checkIfEmpty();

    int getWinningInt();

    void ValidMove(int x, int y);

    void Undo();

    int CheckFinishedPlayer(char player, int returnOnWin);
};

#endif // TICTACTOEMODEL_HPP
