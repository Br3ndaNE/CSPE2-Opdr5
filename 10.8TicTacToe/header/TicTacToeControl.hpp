#ifndef TICTACTOECONTROL_HPP
#define TICTACTOECONTROL_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <windows.h>
#include "Command.hpp"
#include "MoveCommand.hpp"
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "TicTacToeViewText.hpp"

#ifdef SFML_VERSION
#include "TicTacToeViewSFML.hpp"
#endif

class TicTacToeControl {
private:
    TicTacToeModel model;

    std::unique_ptr<TicTacToeView> view;

    std::vector<std::unique_ptr<Command>> commandHistory;
    bool version;

    int undoChar = 0;
    int var_x = 0;
    int var_y = 0;
public:
    TicTacToeControl( bool version );

    void executeCommand(std::unique_ptr<Command> cmd);

    void undoCommand();


    int Play();

};

#endif // TICTACTOECONTROL_HPP
