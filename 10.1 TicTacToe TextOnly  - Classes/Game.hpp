#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "TicTacToeControl.hpp"
#include "MoveCommand.hpp"

class Game {
private:
    TicTacToeModel& model;
    TicTacToeView& view;
    TicTacToeControl& controller;
    int var_x;
    int var_y;

    // Text-Only
    int undoChar;

public:
    Game(TicTacToeModel& model, TicTacToeView& view, TicTacToeControl& controller)
        : model(model), view(view), controller(controller) {}

    int PlayText() {
        controller.AskUpdateBoardText();
        if (model.getWinningInt() == 1) {
            return 1;
        }
        if (model.getWinningInt() == 2) {
            return 2;
        }

        std::cout << "Undo? 1/0: ";
        std::cin >> undoChar;

        if (undoChar == 1) {
            controller.undoCommand();
            return 0;
        } else {
            std::cout << "X: ";
            std::cin >> var_x;
            std::cout << "Y: ";
            std::cin >> var_y;
            controller.executeCommand(std::make_unique<MoveCommand>(model, var_y, var_x));
            return 0;
        }
    }
};

#endif // GAME_HPP
