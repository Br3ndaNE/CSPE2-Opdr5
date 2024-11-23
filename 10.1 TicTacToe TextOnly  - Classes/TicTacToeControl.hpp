#ifndef TICTACTOECONTROL_HPP
#define TICTACTOECONTROL_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "Command.hpp"
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"

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

    void AskUpdateBoardText(){
        view.UpdateBoardText(model.GetBoard());
    }
};

#endif // TICTACTOECONTROL_HPP
