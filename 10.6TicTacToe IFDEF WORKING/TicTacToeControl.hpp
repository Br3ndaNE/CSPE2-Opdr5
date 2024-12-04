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
    TicTacToeControl( bool version ) : 
    view(nullptr), 
    version(version) 
    {
        if(!version){
            //text
            view.reset(new TicTacToeViewText());
        }

    #ifdef SFML_VERSION
        if(version){
            //SFML
            view.reset(new TicTacToeViewSFML());
        }
    #endif
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


    int Play(){
        // Version Text
        if(version == false){
            view->UpdateBoard(model.GetBoard());
            if (model.getWinningInt() == 1) {
                std::cout << "X Wins!" << "\n";
                return 1;
            }
            if (model.getWinningInt() == 2) {
                std::cout << "O Wins!" << "\n";
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
        #ifdef SFML_VERSION
        // SFML
        if (version == true){
            if (model.getWinningInt() == 1) {
                MessageBoxA(NULL, "X wins!","Winnner", MB_OKCANCEL | MB_ICONEXCLAMATION);
                return 1;
            }
            if (model.getWinningInt() == 2) {
                MessageBoxA(NULL, "O wins!", "Winnner", MB_OKCANCEL | MB_ICONEXCLAMATION);
                return 2;
            }
            auto pair = view->ClickEvent();
            if(pair.first != -5 && pair.second != -5){
                if(((pair.first >= 0 && pair.second <= 2) && (pair.first >= 0 && pair.second <= 2))){
                    executeCommand(std::make_unique<MoveCommand>(model, pair.second, pair.first));
                }
                if(pair.first == -1 && pair.second == -1){
                    if(!model.checkIfEmpty()){
                        undoCommand();
                    }else{
                        MessageBoxA(NULL, "!!!", "No moves to undo", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                }
            }

            if(!(view->isOpen())){
                return 3;
            }
            
            view->UpdateBoard(model.GetBoard());

        }
        #endif
        return 0;
    }
    

};

#endif // TICTACTOECONTROL_HPP
