#ifndef TICTACTOEVIEW_HPP
#define TICTACTOEVIEW_HPP

#include <iostream>
#include <utility>

class TicTacToeView {
public:
    virtual ~TicTacToeView() = default;

    virtual void UpdateBoard(char board[3][3]) = 0;
    virtual std::pair<int,int> ClickEvent() = 0;
};

#endif // TICTACTOEVIEW_HPP
