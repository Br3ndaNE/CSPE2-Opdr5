#include "MoveCommand.hpp"


MoveCommand::MoveCommand(TicTacToeModel& model, int x, int y) : model(model), x(x), y(y) {}

void MoveCommand::Execute(){
    model.ValidMove(x, y);
}

void MoveCommand::Undo(){
    model.Undo();
}

