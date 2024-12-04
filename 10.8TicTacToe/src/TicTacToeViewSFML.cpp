#include "TicTacToeViewSFML.hpp"



TicTacToeViewSFML::TicTacToeViewSFML() : window(sf::VideoMode(600,600), "CPSE2 - Opdr5 TTT")
{
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            sf::RectangleShape x;
            x.setSize(sf::Vector2f(cellWidth, cellHeight));
            x.setPosition(j * cellWidth, i * cellHeight);
            x.setOutlineColor(sf::Color::White);
            x.setFillColor(sf::Color::Black);
            x.setOutlineThickness(5.0f);
            RectangleArray[i][j] = x;

            text[i][j].setString("");
            text[i][j].setCharacterSize(75);
            text[i][j].setFillColor(sf::Color::White);
            text[i][j].setStyle(sf::Text::Bold);

        }
    }

    font.loadFromFile("font.ttf");

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            text[i][j].setFont(font);
        }
    }
}


std::pair<int, int> TicTacToeViewSFML::ClickEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        sf::sleep(sf::milliseconds(20));
        if (event.type == sf::Event::Closed) {
            window.close();
            return {-2, -2}; // if window = closed
        }

        // Click Event
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            int clickedRow = mousePosition.y / cellHeight;
            int clickedCol = mousePosition.x / cellWidth;
            return {clickedCol, clickedRow};
        }
        // Press event
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sf::sleep(sf::milliseconds(50));
            return {-1,-1};
        }
    }
    return {-5, -5}; // No click
}


void TicTacToeViewSFML::UpdateBoard(char board[3][3]) {
    window.clear();

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            window.draw(RectangleArray[i][j]);
            if (board[i][j] == 'x' || board[i][j] == 'o') {
                text[i][j].setString(board[i][j]);
                text[i][j].setPosition(j * cellWidth + 75, i * cellHeight + 50);
                window.draw(text[i][j]);
            }
        }
    }

    window.display();
}

bool TicTacToeViewSFML::isOpen(){
    if(window.isOpen()){
        return true;
    }
    return false;
}
