#ifndef TICTACTOECONTROL_HPP
#define TICTACTOECONTROL_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "Command.hpp"
#include "MoveCommand.hpp"
#include "TicTacToeModel.hpp"
#include "TicTacToeView.hpp"
#include "TicTacToeViewText.hpp"

class TicTacToeControl {
private:
    TicTacToeModel& model;

    std::unique_ptr<TicTacToeView> view;

    std::vector<std::unique_ptr<Command>> commandHistory;
    bool version;

    int undoChar = 0;
    int var_x = 0;
    int var_y = 0;
public:
    TicTacToeControl(TicTacToeModel& model, bool version) : 
    model(model), 
    view(nullptr), 
    version(version) 
    {
        if(!version){
            //text
            view.reset(new TicTacToeViewText());
        }
        if(version){
            //SFML
        }
    }

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

    // void initiateVersionView(){
    //     if()
    // }

    int Play(){
        // Version Text
        if(version == false){
            view->UpdateBoardText(model.GetBoard());
            if (model.getWinningInt() == 1) {
                return 1;
            }
            if (model.getWinningInt() == 2) {
                return 2;
            }

            if(!model.checkIfEmpty()){
                std::cout << "Undo? 1/0: ";
                std::cin >> undoChar;
            }

            if (undoChar == 1) {
                undoCommand();
                undoChar = 0;
                return 0;
            } else {
                std::cout << "X: ";
                std::cin >> var_x;
                std::cout << "Y: ";
                std::cin >> var_y;
                executeCommand(std::make_unique<MoveCommand>(model, var_y, var_x));
                return 0;
            }
        }
        // SFML
        if (version == true){
            
        }
        return 0;
    }
    

};

#endif // TICTACTOECONTROL_HPP
