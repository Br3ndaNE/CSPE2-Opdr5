#ifndef TICTACTOEVIEWTEXT_HPP
#define TICTACTOEVIEWTEXT_HPP

#include "TicTacToeView.hpp"
#include <iostream>
#include <utility>

class TicTacToeViewText : public TicTacToeView{
public:
    TicTacToeViewText() = default;

    void UpdateBoard(char board[3][3]) {
        std::cout << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::pair <int,int> ClickEvent(){
        return {0,0};
    };

    bool isOpen(){
        return true;
    }

};

#endif // TICTACTOEVIEWTEXT_HPP
