#include "Game.h"

std::vector<int> Game::gameData_;
float Game::timePoints_;
sf::Sprite Game::fish;
sf::Texture Game::fishTexture;
sf::RectangleShape Game::tank;
//sf::Texture Game::tankTexture;

void Game::drawGame(sf::RenderWindow &window) {
    Button saveGameButton;
    saveGameButton.setSize(sf::Vector2f(148,50));
    saveGameButton.setPosition(sf::Vector2f(1055, 0));
    saveGameButton.click(&saveGame, window);
    sf::Font saveGameFont;
    if (!saveGameFont.loadFromFile("bodyfont.ttf"))
    {
        std::cout << "Error: Font not loaded" << std::endl;
    }
    sf::Text saveGameText;
    saveGameText.setFont(saveGameFont);
    saveGameText.setString("Save Game");
    saveGameText.setCharacterSize(32);
    saveGameText.setPosition(sf::Vector2f(1054, 0));
    saveGameText.setFillColor(sf::Color::Black);
    window.draw(saveGameText);
    //    if (!tankTexture.loadFromFile("tank.png"))
    //    {
    //        std::cout << "Tank texture not loaded" << std::endl;
    //    }
    //tank.setTexture(tankTexture);
    //   tank.setTextureRect(sf::IntRect(100, 30, 1000, 600));
    tank.setSize(sf::Vector2f(1000,600));
    tank.setFillColor(sf::Color::Blue);
    //  tank.setScale(sf::Vector2f(0.9,0.9));
    tank.setPosition(50, 50);
    //window.draw(tank);

    if (!fishTexture.loadFromFile("fish.png"))
    {
        std::cout << "Fish texture not loaded" << std::endl;
    }
    fish.setTexture(fishTexture);
    fish.setPosition((setCoordinates(fish, window)));
    window.draw(fish);
}

void Game::setGameData(std::vector<int> &gameData) {
    gameData_ = gameData;
}

sf::Vector2f Game::setCoordinates(sf::Sprite &fish, sf::RenderWindow &window) {
    int x = sf::Mouse::getPosition(window).x;
    if (x < 50) {
        x = 50;
    }
    else if (x > 1050 - fish.getGlobalBounds().width) {
        x = 1050 - fish.getGlobalBounds().width;
    }

    int y = sf::Mouse::getPosition(window).y;
    if (y < 50) {
        y = 50;
    }
    else if (y > 650 - fish.getGlobalBounds().height) {
        y = 650 - fish.getGlobalBounds().height;
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
    sf::Font timeFont;
    if (!timeFont.loadFromFile("bodyfont.ttf"))
    {
        std::cout << "Error: Time font not loaded" << std::endl;
    }
    sf::Text timeText;
    timeText.setFont(timeFont);
    timeText.setString(std::to_string(gameData_[0]));
    timeText.setCharacterSize(45);
    timeText.setFillColor(sf::Color::Black);
    timeText.setPosition(sf::Vector2f(1115, 50));
    window.draw(timeText);
}

void Game::saveGame() {
    std::fstream gameData;
    gameData.open("gamedata.txt", std::ios::out);
    if (!gameData.is_open()) {
        std::cout << "Error: Cannot open the game data file for saving" << std::endl;
    }
    for (auto &el : gameData_) {
        gameData << std::to_string(el) << '\n';
    }
    gameData.close();
}
