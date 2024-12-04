#include <iostream>
#include "TicTacToeControl.hpp"
int main() {
    // if version bool = ( True == SFML // False == Text )
    bool version = false;
    #ifdef SFML_VERSION
    char charYesNo = ' ';
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
    #else
        version = false;
        std::cout << "Running console" << "\n";
    #endif

    TicTacToeControl controller(version);

    int state = 0;
    while (true) {
        state = controller.Play();
        if(state == 1){
            // exit program if X wins
            break;
        }
        if(state == 2){
            // exit program if O wins
            break;
        }
        if(state == 3){
            // exit program if SFML window closed
            break;
        }
    }

    return 0;
}