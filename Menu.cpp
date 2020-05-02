#include "Menu.h"

bool Menu::openedMenu_ = 1;
sf::Text Menu::header_;
sf::Font Menu::font_;
Button Menu::newGame_;
sf::Text Menu::newGameText_;
Button Menu::loadGame_;
sf::Text Menu::loadGameText_;
sf::Texture Menu::menuImageTexture_;
sf::Sprite Menu::menuImage_;

void Menu::setMenu(std::string &gameName) {

    if (!font_.loadFromFile("assets/fonts/pixelated.ttf"))
    {
        std::cout << "Error: Body font not loaded" << std::endl;
    }

    if (!menuImageTexture_.loadFromFile("assets/images/charactertransparent.png"))
    {
        std::cout << "Menu image texture not loaded" << std::endl;
    }
    menuImage_.setTexture(menuImageTexture_);
    menuImage_.setPosition(sf::Vector2f(170, 160));

    header_.setFont(font_);
    header_.setString(gameName);
    header_.setCharacterSize(30);
    header_.setFillColor(sf::Color::Black);
    header_.setPosition(sf::Vector2f(80, 95));

    newGame_.setPosition(sf::Vector2f(140, 235));
    newGame_.setSize(sf::Vector2f(130, 32));
    newGameText_.setFont(font_);
    newGameText_.setString("New Game");
    newGameText_.setCharacterSize(30);
    newGameText_.setFillColor(sf::Color::Black);
    newGameText_.setPosition(sf::Vector2f(141, 235));

    loadGame_.setPosition(sf::Vector2f(140, 275));
    loadGame_.setSize(sf::Vector2f(130, 32));
    loadGameText_.setFont(font_);
    loadGameText_.setString("Load Game");
    loadGameText_.setCharacterSize(30);
    loadGameText_.setFillColor(sf::Color::Black);
    loadGameText_.setPosition(sf::Vector2f(140, 275));
}

void Menu::drawMenu(sf::RenderWindow &window) {
    window.draw(menuImage_);
    window.draw(header_);
    newGame_.click(&newGameFile, window);
    loadGame_.click(&loadGameFile, window);
    window.draw(loadGameText_);
    window.draw(newGameText_);
}

void Menu::loadGameFile() {
    std::fstream gameData;
    gameData.open("gamedata.txt", std::ios::in);
    if (!gameData.is_open()) {
        std::cout << "Warning: Game data not loaded. \nCreating a new game file." << std::endl;
        newGameFile();
    }
    std::string line;
    std::vector<int> gameDataTmp;
    while(getline(gameData, line)) {
        gameDataTmp.emplace_back(stoi(line));
    }
    Game::setGameData(gameDataTmp);
    gameData.close();
    openedMenu_ = 0;
}

void Menu::newGameFile() {
    std::vector<int> gameDataTmp(10, 0);
    Game::setGameData(gameDataTmp);
    openedMenu_ = 0;
}
