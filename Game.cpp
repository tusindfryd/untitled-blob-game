#include "Game.h"

std::vector<int> Game::gameData_(10, 0);
float Game::timePoints_;
sf::Sprite Game::pet_;
sf::Texture Game::petTexture_;
std::string Game::petTexturePath_ = "character.png";

Button Game::saveGameButton_;
sf::Font Game::bodyGameFont_;
std::string Game::fontPath_ = "bodyfont.ttf";
sf::Text Game::saveGameText_;

sf::Text Game::timeText_;

void Game::setGame() {
    saveGameButton_.setPosition(sf::Vector2f(250, 0));
    if (!bodyGameFont_.loadFromFile(fontPath_))
    {
        std::cout << "Error: Font not loaded" << std::endl;
    }
    saveGameText_.setFont(bodyGameFont_);
    saveGameText_.setString("Save Game");
    saveGameText_.setCharacterSize(31);
    saveGameText_.setPosition(sf::Vector2f(250, 5));
    saveGameText_.setFillColor(sf::Color::Black);

    if (!petTexture_.loadFromFile(petTexturePath_))
    {
        std::cout << "Pet texture not loaded" << std::endl;
    }
    pet_.setTexture(petTexture_);

    timeText_.setFont(bodyGameFont_);
    timeText_.setCharacterSize(31);
    timeText_.setFillColor(sf::Color::Black);
    timeText_.setPosition(sf::Vector2f(80, 5));
}

void Game::drawGame(sf::RenderWindow &window, int &windowSize) {
    saveGameButton_.click(&saveGame, window);

    pet_.setPosition((setCoordinates(pet_, windowSize, window)));
    pet_.setScale(sf::Vector2f(0.3, 0.3));
    window.draw(pet_);
    window.draw(saveGameText_);

}

void Game::setGameData(std::vector<int> &gameData) {
    gameData_ = gameData;
}

sf::Vector2f Game::setCoordinates(sf::Sprite &pet, int &windowSize, sf::RenderWindow &window) {
    int x = sf::Mouse::getPosition(window).x;
    if (x < 60) {
        x = 60;
    }
    else if (x > windowSize - pet.getGlobalBounds().width - 60) {
        x = windowSize - pet.getGlobalBounds().width - 60;
    }

    int y = sf::Mouse::getPosition(window).y;
    if (y < 60) {
        y = 60;
    }
    else if (y > windowSize - pet.getGlobalBounds().height - 60) {
        y = windowSize - pet.getGlobalBounds().height - 60;
    }

    return sf::Vector2f(x, y);
}

void Game::displayTime(float elapsedTime, sf::RenderWindow &window) {
    if (timePoints_ <= 1) {
        timePoints_ = timePoints_ + elapsedTime;
    }
    else {
        timePoints_ = 0;
    }

    gameData_[0] = gameData_[0] + int(timePoints_);

    timeText_.setString(std::to_string(gameData_[0]));
    window.draw(timeText_);
}

void Game::saveGame() {
    std::fstream gameData;
    gameData.open("gamedata.txt", std::ios::out);
    if (!gameData.is_open()) {
        std::cout << "Error: Cannot open the game data file for saving" << std::endl;
    }
    else {
        for (unsigned int i = 0; i < gameData_.size(); i++) {
            gameData << std::to_string(gameData_[i]) << '\n';
        }
        gameData.close();
    }
}
