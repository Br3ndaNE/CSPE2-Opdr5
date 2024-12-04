#include "TicTacToeViewText.hpp"

TicTacToeViewText::TicTacToeViewText() = default;

void TicTacToeViewText::UpdateBoard(char board[3][3]) {
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::pair <int,int> TicTacToeViewText::ClickEvent(){
    return {0,0};
};

bool TicTacToeViewText::isOpen(){
    return true;
}
