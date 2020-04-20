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

private:
    static sf::Font headerFont;
    static sf::Text header;
    static sf::Font bodyFont;
    static Button newGame;
    static sf::Text newGameText;
    static Button loadGame;
    static sf::Text loadGameText;
};
