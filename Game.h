#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include"Button.h"

class Game {
public:
    static void drawGame(sf::RenderWindow &window);
    static void setGameData(std::vector<int> &gameData);
    static void displayTime(float elapsedTime, sf::RenderWindow &window);
    static void saveGame();
    static float timePoints_;
    static std::vector<int> gameData_; // not ideal for this to be here

private:
    static void moveFish(sf::Sprite &fish, sf::RenderWindow &window);
    static sf::Vector2f setCoordinates(sf::Sprite &fish, sf::RenderWindow &window);
    static sf::Sprite fish;
    static sf::Texture fishTexture;

    static sf::RectangleShape tank;
    //    static sf::Texture tankTexture;
};
