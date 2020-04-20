#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Button : public sf::RectangleShape {

public:
    Button();
    void click(void (*function)(), sf::RenderWindow &window);
    static void setSound();

private:
    int buttonWidth_ = 130;
    int buttonHeight_ = 50;
    static sf::Sound clickSound;
    static sf::SoundBuffer clickBuffer;
};
