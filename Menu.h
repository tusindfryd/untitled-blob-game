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

    static void drawMenu(sf::RenderWindow &window, int &windowSize, std::string &gameName);
    static void loadGameFile();
    static void newGameFile();
};
