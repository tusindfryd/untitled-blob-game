#include "Menu.h"

bool Menu::openedMenu_ = 1;

void Menu::drawMenu(sf::RenderWindow &window) {
    sf::Font headerFont;
    if (!headerFont.loadFromFile("headerfont.ttf"))
    {
        std::cout << "Error: Header font not loaded" << std::endl;
    }
    sf::Text header;
    header.setFont(headerFont);
    header.setString("Goldfish \nSimulator");
    header.setCharacterSize(120);
    header.setPosition(sf::Vector2f(275, 60));

    sf::Font bodyFont;
    if (!bodyFont.loadFromFile("bodyfont.ttf"))
    {
        std::cout << "Error: Body font not loaded" << std::endl;
    }
    sf::Text description;
    description.setFont(bodyFont);
    description.setString("but without having to actually clean \nthe aquarium off algae and stuff");
    description.setCharacterSize(45);
    description.setPosition(sf::Vector2f(275, 320));

    Button newGame;
    newGame.setPosition(sf::Vector2f(285, 420));
    newGame.click(&newGameFile, window);
    sf::Text newGameText;
    newGameText.setFont(bodyFont);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(60);
    newGameText.setPosition(sf::Vector2f(305, 435));

    Button loadGame;
    loadGame.setPosition(sf::Vector2f(615, 420));
    loadGame.click(&loadGameFile, window);
    sf::Text loadGameText;
    loadGameText.setFont(bodyFont);
    loadGameText.setString("Load Game");
    loadGameText.setCharacterSize(60);
    loadGameText.setPosition(sf::Vector2f(635, 435));


    window.draw(header);
    window.draw(description);
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
    std::fstream gameData;
    gameData.open("gamedata.txt", std::ios::out);
    if (!gameData.is_open()) {
        std::cout << "Error: Cannot create a new game file." << std::endl;
    }
    std::vector<int> gameDataTmp(10, 0);
    Game::setGameData(gameDataTmp);
    gameData.close();
    openedMenu_ = 0;
}
