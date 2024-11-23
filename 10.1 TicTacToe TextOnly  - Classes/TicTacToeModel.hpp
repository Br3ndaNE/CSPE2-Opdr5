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
    TicTacToeModel() {}

    char (*GetBoard())[3] {
        return board;
    }

    int getWinningInt() {
        return WinningInt;
    }

    void ValidMove(int x, int y) {
        if (board[x][y] == '.' && playerBool == 0) {
            playerBool = 1;
            board[x][y] = 'x';

            if (CheckFinishedPlayer('x', 1) == 1) {
                WinningInt = 1;
            }
            moves.push_back({x, y});
        } else if (board[x][y] == '.' && playerBool == 1) {
            playerBool = 0;
            board[x][y] = 'o';

            if (CheckFinishedPlayer('o', 2) == 2) {
                WinningInt = 2;
            }
            moves.push_back({x, y});
        } else {
            std::cout << "invalid move" << std::endl;
        }
    }

    void Undo() {
        if (!moves.empty()) {
            auto lastPair = moves.back();
            board[lastPair.first][lastPair.second] = '.';

            playerBool = (playerBool == 0) ? 1 : 0;
            moves.pop_back();
        } else {
            std::cout << "Nothing to undo" << std::endl;
        }
    }

    int CheckFinishedPlayer(char player, int returnOnWin) {
        for (int i = 0; i <= 2; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return returnOnWin;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return returnOnWin;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return returnOnWin;
        }
        if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
            return returnOnWin;
        }
        return 0;
    }
};

#endif // TICTACTOEMODEL_HPP
