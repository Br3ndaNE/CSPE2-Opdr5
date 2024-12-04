#ifndef TICTACTOEVIEWTEXT_HPP
#define TICTACTOEVIEWTEXT_HPP

#include "TicTacToeView.hpp"
#include <iostream>
#include <utility>

class TicTacToeViewText : public TicTacToeView{
public:
    TicTacToeViewText();

    void UpdateBoard(char board[3][3]);

    std::pair <int,int> ClickEvent();

    bool isOpen();

};

#endif // TICTACTOEVIEWTEXT_HPP
