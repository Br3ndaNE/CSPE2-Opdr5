#ifndef TICTACTOEVIEW_HPP
#define TICTACTOEVIEW_HPP

#include <iostream>

class TicTacToeView {
public:
    virtual ~TicTacToeView() = default;

    virtual void UpdateBoardText(char board[3][3]) = 0;
};

#endif // TICTACTOEVIEW_HPP
