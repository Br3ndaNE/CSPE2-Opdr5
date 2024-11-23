#ifndef TICTACTOEVIEW_HPP
#define TICTACTOEVIEW_HPP

#include <iostream>

class TicTacToeView {
public:
    TicTacToeView() {}

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

    void UpdateBoardSFML(){

    }
};

#endif // TICTACTOEVIEW_HPP
