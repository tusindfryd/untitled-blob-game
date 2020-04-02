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
    static void setGame();
    static void drawGame(sf::RenderWindow &window, int &windowSize);
    static void setGameData(std::vector<int> &gameData);
    static void displayTime(float elapsedTime, sf::RenderWindow &window);
    static void saveGame();

private:
    static float timePoints_;
    static sf::Vector2f setCoordinates(sf::Sprite &pet, int &windowSize, sf::RenderWindow &window);
    static sf::Sprite pet_;
    static sf::Texture petTexture_;
    static std::string petTexturePath_;
    static std::vector<int> gameData_;
    static Button saveGameButton_;
    static sf::Font bodyGameFont_;
    static std::string fontPath_;
    static sf::Text saveGameText_;
    static sf::Text timeText_;
};
