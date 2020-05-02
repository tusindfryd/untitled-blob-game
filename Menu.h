#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Game.h"

class Menu {
public:
    static bool openedMenu_;

    static void drawMenu(sf::RenderWindow &window);
    static void setMenu(std::string &gameName);
    static void loadGameFile();
    static void newGameFile();
    static sf::Font font_;

private:
    static sf::Text header_;
    static Button newGame_;
    static sf::Text newGameText_;
    static Button loadGame_;
    static sf::Text loadGameText_;
    static sf::Texture menuImageTexture_;
    static sf::Sprite menuImage_;
};
