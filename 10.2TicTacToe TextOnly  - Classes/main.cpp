#include <iostream>
#include <memory>
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "TicTacToeControl.hpp"
#include "MoveCommand.hpp"

int main() {
    bool version = false; // if True == SFML // if False == Text
    TicTacToeModel model;
    TicTacToeView view;
    TicTacToeControl controller(model, view, version);


    int state = 0;
    while (true) {
        state = controller.Play();
        if(state == 1){
            break;
        }
    }

    return 0;
}