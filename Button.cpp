#include "Button.h"


Button::Button() : sf::RectangleShape() {
    this->setSize(sf::Vector2f(buttonWidth_, buttonHeight_));
}


sf::Sound Button::clickSound;
sf::SoundBuffer Button::clickBuffer;


void Button::setSound() {
    if (!clickBuffer.loadFromFile("assets/sounds/click.wav")) {
        std::cout << "Click sound not loaded" << std::endl;
    }
    clickSound.setBuffer(clickBuffer);
}

void Button::click(void (*function)(), sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bool boundedX = sf::Mouse::getPosition(window).x > this->getGlobalBounds().left &&
                sf::Mouse::getPosition(window).x < this->getGlobalBounds().left + this->getGlobalBounds().width;
        bool boundedY = sf::Mouse::getPosition(window).y > this->getGlobalBounds().top &&
                sf::Mouse::getPosition(window).y < this->getGlobalBounds().top + this->getGlobalBounds().height;

        if (boundedX && boundedY) {
            clickSound.play();
            (*function)();
            std::chrono::duration<int, std::milli> timespan(150);       // workaround to avoid multiple function execution
            std::this_thread::sleep_for(timespan);
        }

    }
}


