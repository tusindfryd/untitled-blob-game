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
bool Game:: openedMaze_ = false;

Button Game::saveGameButton_;
sf::Font Game::bodyGameFont_;
std::string Game::fontPath_ = "assets/fonts/pixelated.ttf";

sf::Text Game::timeText_;

sf::Sprite Game::scenery_;
Button Game::sceneryChooserButton_;
std::vector<sf::Texture> Game::sceneries_;

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

    sceneryChooserButton_.setPosition(sf::Vector2f(275, 360));
    sceneryChooserButton_.setSize(sf::Vector2f(30, 30));

    timeText_.setFont(bodyGameFont_);
    timeText_.setCharacterSize(31);
    timeText_.setFillColor(sf::Color::Black);
    timeText_.setPosition(sf::Vector2f(110, 5));

    Maze::setMaze(appleTexture_);

    sceneries_.resize(4);
    if (!sceneries_[0].create(400, 400))
    {
        std::cout << "Empty scenery texture not created" << std::endl;
    }
    if (!sceneries_[1].loadFromFile("assets/images/basic.png"))
    {
        std::cout << "Basic scenery texture not loaded" << std::endl;
    }
    if (!sceneries_[2].loadFromFile("assets/images/cute.png"))
    {
        std::cout << "Cute scenery texture not loaded" << std::endl;
    }
    if (!sceneries_[3].loadFromFile("assets/images/color.png"))
    {
        std::cout << "Color scenery texture not loaded" << std::endl;
    }
    scenery_.setTexture(sceneries_[gameData_[1]]);
    Scenery::setSceneryChooser(bodyGameFont_);
}

void Game::drawGame(sf::RenderWindow &window, int &windowSize, int &margin) {
    if((sf::Mouse::getPosition(window).x > margin && sf::Mouse::getPosition(window).y > margin &&
        sf::Mouse::getPosition(window).x < windowSize - margin && sf::Mouse::getPosition(window).y < windowSize - margin)) {
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
    sceneryChooserButton_.click(&openSceneryChooser, window);
    if(Scenery::updateNeeded_) {
        gameData_[1] = Scenery::choosenSceneryIndex_;
        Scenery::updateNeeded_ = false;
    }
    scenery_.setTexture(sceneries_[gameData_[1]]);
    if (Scenery::openedSceneryChooser_) {
        window.draw(scenery_);
        Scenery::drawSceneryChooser(window, gameData_[0]);
    }
    else if (openedMaze_ && !Maze::gameLost_ && !Maze::gameWon_) {
        Maze::drawMaze(window, pet_);
    }
    else if (openedMaze_ && Maze::gameLost_) {
        Maze::gameLost_ = false;
        openedMaze_ = false;
    }
    else if (openedMaze_ && Maze::gameWon_) {
        gameData_[0] = gameData_[0] + 30;
        Maze::gameWon_ = false;
        openedMaze_ = false;
    }
    else {
        window.draw(scenery_);
        pet_.setTexture(petTexture_, true);
        pet_.setScale(sf::Vector2f(1, 1));
    }


    pet_.setPosition((setCoordinates(pet_, true, window, margin)));
    food_.setPosition(setCoordinates(food_, false, window, margin));
    window.draw(pet_);
    if (feedable_) {
        window.draw(food_);
    }


}

void Game::setGameData(std::vector<int> &gameData) {
    gameData_ = gameData;
}

void Game::openGame() {
    openedMaze_ = true;
}

void Game::openSceneryChooser() {
    Scenery::openedSceneryChooser_ = true;
}

sf::Vector2f Game::setCoordinates(sf::Sprite &pet, bool isBounded, sf::RenderWindow &window, int &margin) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    if (isBounded) {
        if (x < margin) {
            x = margin;
        }
        else if (x > window.getSize().x - pet.getGlobalBounds().width - margin) {
            x = window.getSize().x - pet.getGlobalBounds().width - margin;
        }

        if (y < margin) {
            y = margin;
        }
        else if (y > window.getSize().y - pet.getGlobalBounds().height - margin) {
            y = window.getSize().y - pet.getGlobalBounds().height - margin;
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
