#include <iostream>
#include <memory>
#include "TicTacToeModel.hpp"
#include "TicTacToeControl.hpp"
#include "MoveCommand.hpp"

int main() {
    // if True == SFML // if False == Text
    char charYesNo = ' ';
    bool version = true; 
    for(;;){
        std::cout << "Do you want to play SFML(Y) or Text(N)?:" << "\n";
        std::cin >> charYesNo;
        if(charYesNo == 'Y'){
            version = true;
            break;
        }else if(charYesNo == 'N'){
            version = false;
            break;
        }
    }

    TicTacToeControl controller(version);

    int state = 0;
    while (true) {
        state = controller.Play();
        if(state == 1){
            break;
        }
        if(state == 2){
            break;
        }
        if(state == 3){
            break;
        }
    }

    return 0;
}