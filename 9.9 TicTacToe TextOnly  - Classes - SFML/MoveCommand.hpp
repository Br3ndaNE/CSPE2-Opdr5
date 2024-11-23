#ifndef MOVECOMMAND_HPP
#define MOVECOMMAND_HPP

#include "Command.hpp"
#include "TicTacToeModel.hpp"

class MoveCommand : public Command {
private:
    TicTacToeModel& model;
    int x;
    int y;

public:
    MoveCommand(TicTacToeModel& model, int x, int y) : model(model), x(x), y(y) {}

    void Execute() override {
        model.MakeValidMove(x, y);
    }

    void Undo() override {
        model.Undo();
    }
};

#endif // MOVECOMMAND_HPP
