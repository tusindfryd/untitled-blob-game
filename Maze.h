#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Button.h"

class Maze {
public:
    static void setMaze(sf::Texture &appleTexture_);
    static void drawMaze(sf::RenderWindow &window, sf::Sprite &sprite);
    static bool gameWon_;
    static bool gameLost_;
private:
    static bool isTouchingWall(sf::Sprite &sprite);
    static int map_[6][6];
    static std::vector <sf::RectangleShape> tiles_;
    static sf::Sprite apple_;
    static void foundApple(sf::Sprite &sprite);
};

