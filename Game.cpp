#include "Game.h"

std::vector<int> Game::gameData_(10, 0);
float Game::timePoints_;
sf::Sprite Game::pet_;
sf::Texture Game::petTexture_;
std::string Game::petTexturePath_ = "assets/images/character.png";

sf::Sprite Game::food_;
sf::Texture Game::appleTexture_;
std::string Game::appleTexturePath_ = "assets/images/apple.png";

Button Game::feedButton_;
bool Game::feedable_ = false;

Button Game::gameButton_;
bool Game:: openedCatch_ = false;

Button Game::saveGameButton_;
sf::Font Game::bodyGameFont_;
std::string Game::fontPath_ = "assets/fonts/bodyfont.ttf";

sf::Text Game::timeText_;

void Game::setGame() {
    saveGameButton_.setPosition(sf::Vector2f(210, 10));
    saveGameButton_.setSize(sf::Vector2f(40, 40));
    if (!bodyGameFont_.loadFromFile(fontPath_))
    {
        std::cout << "Error: Font not loaded" << std::endl;
    }


    if (!petTexture_.loadFromFile(petTexturePath_))
    {
        std::cout << "Pet texture not loaded" << std::endl;
    }
    pet_.setTexture(petTexture_);

    if (!appleTexture_.loadFromFile(appleTexturePath_))
    {
        std::cout << "Apple texture not loaded" << std::endl;
    }
    food_.setTexture(appleTexture_);

    feedButton_.setPosition(sf::Vector2f(95,360));
    feedButton_.setSize(sf::Vector2f(30,30));

    gameButton_.setPosition(sf::Vector2f(185,360));
    gameButton_.setSize(sf::Vector2f(30,30));

    timeText_.setFont(bodyGameFont_);
    timeText_.setCharacterSize(31);
    timeText_.setFillColor(sf::Color::Black);
    timeText_.setPosition(sf::Vector2f(110, 5));

    Maze::setMaze(appleTexture_);
}

void Game::drawGame(sf::RenderWindow &window, int &windowSize) {
    if((sf::Mouse::getPosition(window).x > 62 && sf::Mouse::getPosition(window).y > 62 &&
        sf::Mouse::getPosition(window).x < windowSize - 62 && sf::Mouse::getPosition(window).y < windowSize - 62)) {
        window.setMouseCursorVisible(false);
    }
    else {
        window.setMouseCursorVisible(true);
    }

    saveGameButton_.click(&saveGame, window);
    feedButton_.click(&makeFeedable, window);
    if (feedable_ &&
            food_.getPosition().x == pet_.getPosition().x &&
            food_.getPosition().y == pet_.getPosition().y) {
        gameData_[0] = gameData_[0] + 30;
        feedable_ = false;
    }

    gameButton_.click(&openGame, window);
    if (openedCatch_ && !Maze::gameLost_ && !Maze::gameWon_) {
        pet_.setScale(sf::Vector2f(0.15, 0.15));
        Maze::drawMaze(window, pet_);
    }
    else if (openedCatch_ && Maze::gameLost_) {
        Maze::gameLost_ = false;
        openedCatch_ = false;
    }
    else if (openedCatch_ && Maze::gameWon_) {
        gameData_[0] = gameData_[0] + 30;
        Maze::gameWon_ = false;
        openedCatch_ = false;
    }
    else {
        pet_.setScale(sf::Vector2f(0.3, 0.3));
    }

    pet_.setPosition((setCoordinates(pet_, true, window)));
    food_.setPosition(setCoordinates(food_, false, window));
    window.draw(pet_);
    if (feedable_) {
        window.draw(food_);
    }


}

void Game::setGameData(std::vector<int> &gameData) {
    gameData_ = gameData;
}

void Game::openGame() {
    openedCatch_ = true;
}

sf::Vector2f Game::setCoordinates(sf::Sprite &pet, bool isBounded, sf::RenderWindow &window) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    if (isBounded) {
        if (x < 60) {
            x = 60;
        }
        else if (x > window.getSize().x - pet.getGlobalBounds().width - 60) {
            x = window.getSize().x - pet.getGlobalBounds().width - 60;
        }

        if (y < 60) {
            y = 60;
        }
        else if (y > window.getSize().y - pet.getGlobalBounds().height - 60) {
            y = window.getSize().y - pet.getGlobalBounds().height - 60;
        }

    }

    return sf::Vector2f(x, y);
}

void Game::makeFeedable() {
    feedable_ = true;
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
