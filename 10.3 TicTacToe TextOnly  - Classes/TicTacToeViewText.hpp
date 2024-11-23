#ifndef TICTACTOEVIEWTEXT_HPP
#define TICTACTOEVIEWTEXT_HPP

#include "TicTacToeView.hpp"
#include <iostream>

class TicTacToeViewText : public TicTacToeView{
public:
    TicTacToeViewText() = default;

    void UpdateBoardText(char board[3][3]) {
        std::cout << std::endl;
        for (int i = 2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

};

#endif // TICTACTOEVIEWTEXT_HPP
