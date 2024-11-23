#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "TicTacToeControl.hpp"
#include "MoveCommand.hpp"
#include <SFML/Graphics.hpp>

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

    int Play(bool textOrSFML) {
        if(textOrSFML == true){
            // std::cout << "SFML";
            controller.GameLoopSFML();

        }
        if(textOrSFML == false){
            // std::cout << "TEXT";
            controller.GameloopText();
        }
        return 0;
    }
};

#endif // GAME_HPP
