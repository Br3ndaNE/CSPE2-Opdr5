#ifndef TICTACTOECONTROL_HPP
#define TICTACTOECONTROL_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "Command.hpp"
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "MoveCommand.hpp"

class TicTacToeControl {
private:
    TicTacToeModel& model;
    TicTacToeView& view;
    std::vector<std::unique_ptr<Command>> commandHistory;

public:
    TicTacToeControl(TicTacToeModel& model, TicTacToeView& view) : model(model), view(view) {}

    void executeCommand(std::unique_ptr<Command> cmd) {
        cmd->Execute();
        commandHistory.push_back(std::move(cmd));
    }

    void undoCommand() {
        if (!commandHistory.empty()) {
            commandHistory.back()->Undo();
            commandHistory.pop_back();
        } else {
            std::cout << "No moves to undo!" << std::endl;
        }
    }

    void GameloopText(){
        int undoChar;
        int var_x;
        int var_y;

        view.UpdateBoard(model.GetBoard());
        if (model.getWinningInt() == 1) {
        }
        if (model.getWinningInt() == 2) {
        }

        std::cout << "Undo? 1/0: ";
        std::cin >> undoChar;

        if (undoChar == 1) {
            undoCommand();
        } else {
            std::cout << "X: ";
            std::cin >> var_x;
            std::cout << "Y: ";
            std::cin >> var_y;
            executeCommand(std::make_unique<MoveCommand>(model, var_y, var_x));
        }
    }

    void GameLoopSFML(){
        // eventloop + boardupdate + plaatsen board
        view.UpdateBoardSFML();
        view.boardEvent();
    }

};

#endif // TICTACTOECONTROL_HPP
