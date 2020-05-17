#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "Button.h"
class Scenery
{
public:
    static bool openedSceneryChooser_;
    static void setSceneryChooser(sf::Font &font);
    static void drawSceneryChooser(sf::RenderWindow &window, int &timePoints);
    static int choosenSceneryIndex_;
    static bool updateNeeded_;

private:
    static std::vector<Button> buttons_;
    static std::vector<sf::Text> labels_;
    static std::vector<bool> setters_;
    static void setScenery0();
    static void setScenery1();
    static void setScenery2();
    static void setScenery3();
};

