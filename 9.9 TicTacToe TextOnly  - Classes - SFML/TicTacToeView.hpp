#ifndef TICTACTOEVIEW_HPP
#define TICTACTOEVIEW_HPP

#include <iostream>
#include <SFML/Graphics.hpp>


class TicTacToeView {
public:
    sf::RenderWindow w;
    sf::RectangleShape RectangleArray[3][3];

    // TicTacToeView() : {}


    TicTacToeView() : 
        w(sf::VideoMode(600, 600), "SFML Window") 
    {}

    void UpdateBoardText(char board[3][3]) {
        std::cout << std::endl;
        for (int i = 2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void UpdateBoardSFML(){
        w.clear();
        drawBoard();
        w.display();

    }

    void boardEvent(){
        sf::Event event;
        while(w.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                w.close();
            }
        }
    }
    
    // void drawBoard(){
    //     for (int i = 0; i < 3; ++i) {
    //         for (int j = 0; j < 3; ++j) {
    //             sf::RectangleShape x;
    //             x.setSize(sf::Vector2f(200, 200));
    //             x.setPosition(j * 200, i * 200);
    //             x.setOutlineColor(sf::Color::White);
    //             x.setOutlineThickness(5.0f);
    //             RectangleArray[i][j] = x;
    //         }
    //     }

    //     for (unsigned int i = 0; i < 3; i++) {
    //         for (unsigned int j = 0; j < 3; j++) {
    //             w.draw(RectangleArray[i][j]);
    //             // OArray[i][j].draw(w);
    //             // XArray[i][j].draw(w);
    //         }
    //     }

        // std::cout << "X" << "\n";
    
    }


};

#endif // TICTACTOEVIEW_HPP
