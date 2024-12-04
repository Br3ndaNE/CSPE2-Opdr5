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
    MoveCommand(TicTacToeModel& model, int x, int y);

    void Execute();

    void Undo();
};

#endif // MOVECOMMAND_HPP
