#include "Button.h"

Button::Button() : sf::RectangleShape() {
    this->setSize(sf::Vector2f(buttonWidth_, buttonHeight_));
}

void Button::click(void (*function)(), sf::RenderWindow &window) {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bool boundedX = sf::Mouse::getPosition(window).x > this->getGlobalBounds().left &&
                sf::Mouse::getPosition(window).x < this->getGlobalBounds().left + this->getGlobalBounds().width;
        bool boundedY = sf::Mouse::getPosition(window).y > this->getGlobalBounds().top &&
                sf::Mouse::getPosition(window).y < this->getGlobalBounds().top + this->getGlobalBounds().height;

        if (boundedX && boundedY) {
            (*function)();
        }

    }
}


