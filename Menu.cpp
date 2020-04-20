#include "Menu.h"

bool Menu::openedMenu_ = 1;
sf::Font Menu::headerFont;
sf::Text Menu::header;
sf::Font Menu::bodyFont;
Button Menu::newGame;
sf::Text Menu::newGameText;
Button Menu::loadGame;
sf::Text Menu::loadGameText;

void Menu::setMenu(std::string &gameName) {

    if (!headerFont.loadFromFile("assets/fonts/headerfont.ttf"))
    {
        std::cout << "Error: Header font not loaded" << std::endl;
    }

    for (unsigned int i = 0; i < gameName.length(); i++) {
        if (gameName[i] == ' ') {
            gameName[i] = '\n';
        }
    }

    header.setFont(headerFont);
    header.setString(gameName);
    header.setCharacterSize(42);
    header.setFillColor(sf::Color::Black);
    header.setPosition(sf::Vector2f(100, 80));


    if (!bodyFont.loadFromFile("assets/fonts/bodyfont.ttf"))
    {
        std::cout << "Error: Body font not loaded" << std::endl;
    }

    newGame.setPosition(sf::Vector2f(60, 250));
    newGameText.setFont(bodyFont);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(31);
    newGameText.setFillColor(sf::Color::Black);
    newGameText.setPosition(sf::Vector2f(60, 260));

    loadGame.setPosition(sf::Vector2f(210, 250));
    loadGameText.setFont(bodyFont);
    loadGameText.setString("Load Game");
    loadGameText.setCharacterSize(31);
    loadGameText.setFillColor(sf::Color::Black);
    loadGameText.setPosition(sf::Vector2f(205, 260));
}

void Menu::drawMenu(sf::RenderWindow &window) {

    window.draw(header);
    newGame.click(&newGameFile, window);
    loadGame.click(&loadGameFile, window);
    window.draw(loadGameText);
    window.draw(newGameText);
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
