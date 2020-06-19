#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Button.h"

class Maze {
public:
    static void setMaze(sf::Texture &appleTexture_);
    static void drawMaze(sf::RenderWindow &window, sf::Sprite &sprite);
    static void randomizeMaze(sf::Texture &appleTexture_);
    static bool gameWon_;
    static bool gameLost_;
private:
    static sf::Sound lostSound;
    static sf::SoundBuffer lostBuffer;
    static sf::Sound wonSound;
    static sf::SoundBuffer wonBuffer;
    static sf::Texture smallPetTexture_;

    static bool isTouchingWall(sf::Sprite &sprite);
    static int map_[6][6];
    static int map0_[6][6];
    static int map1_[6][6];
    static int map2_[6][6];
    static int map3_[6][6];
    static int map4_[6][6];
    static std::vector <sf::RectangleShape> tiles_;
    static sf::Sprite apple_;
    static void foundApple(sf::Sprite &sprite);

};

