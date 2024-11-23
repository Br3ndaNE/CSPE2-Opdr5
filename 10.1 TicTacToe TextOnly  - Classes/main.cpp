#include <iostream>
#include <memory>
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "TicTacToeControl.hpp"
#include "Game.hpp"
#include "MoveCommand.hpp"

int main() {
    TicTacToeModel model;
    TicTacToeView view;
    TicTacToeControl controller(model, view);
    Game TTT(model, view, controller);

    while (true) {
        int winState = TTT.PlayText();
        if (winState == 1) {
            std::cout << "X Won!" << std::endl;
            break;
        }
        if (winState == 2) {
            std::cout << "O Won!" << std::endl;
            break;
        }
    }

    return 0;
}