#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Button : public sf::RectangleShape {

public:
    Button();
    void click(void (*function)(), sf::RenderWindow &window);

private:
    int buttonWidth_ = 300;
    int buttonHeight_ = 120;
};
