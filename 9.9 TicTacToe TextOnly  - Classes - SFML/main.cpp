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

    bool TextOrSFML = true; // TRUE = SFML // FALSE = TEXT

    while (true) {
        TTT.Play(TextOrSFML);
    }

    return 0;
}