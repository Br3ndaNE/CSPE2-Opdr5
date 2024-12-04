#ifndef TICTACTOEVIEWSFML_HPP
#define TICTACTOEVIEWSFML_HPP

#include <SFML/Graphics.hpp>
#include "TicTacToeView.hpp"
#include <iostream>

class TicTacToeViewSFML : public TicTacToeView{
private: 
    sf::RenderWindow window;
    sf::RectangleShape RectangleArray[3][3];
    const float cellWidth = 200.0f;
    const float cellHeight = 200.0f;
    const int numRows = 3;
    const int numCols = 3;

    sf::Font font;
    sf::Text text[3][3];

public:
    TicTacToeViewSFML();


    std::pair<int, int> ClickEvent();


    void UpdateBoard(char board[3][3]);
    
    bool isOpen();

};

#endif // TICTACTOEVIEWSFML_HPP
