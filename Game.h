#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Maze.h"
#include "Scenery.h"

class Game {
public:
    static bool openedMaze_;

    static void setGame();
    static void setGameData(std::vector<int> &gameData);
    static void drawGame(sf::RenderWindow &window, int &windowSize, int &margin);
    static void displayTime(float elapsedTime, sf::RenderWindow &window);
    static void saveGame();

private:
    static float timePoints_;
    static sf::Vector2f setCoordinates(sf::Sprite &pet, bool isBounded, sf::RenderWindow &window, int &margin);
    static sf::Sprite pet_;
    static sf::Texture petTexture_;
    static std::string petTexturePath_;
    static sf::Texture hungryTexture_;
    static std::string hungryTexturePath_;
    static sf::Sprite food_;
    static sf::Texture appleTexture_;
    static std::string appleTexturePath_;
    static Button feedButton_;
    static void makeFeedable();
    static bool feedable_;
    static Button gameButton_;
    static void openGame();
    static std::vector<int> gameData_;
    static Button saveGameButton_;
    static sf::Font bodyGameFont_;
    static std::string fontPath_;
    static sf::Text timeText_;
    static void openSceneryChooser();
    static Button sceneryChooserButton_;
    static std::vector<sf::Texture> sceneries_;
    static sf::Sprite scenery_;
};
