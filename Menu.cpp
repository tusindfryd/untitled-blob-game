#include "Menu.h"

bool Menu::openedMenu_ = 1;

void Menu::drawMenu(sf::RenderWindow &window, int &windowSize, std::string &gameName) {
    sf::Font headerFont;
    if (!headerFont.loadFromFile("headerfont.ttf"))
    {
        std::cout << "Error: Header font not loaded" << std::endl;
    }
    sf::Text header;
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

    sf::Font bodyFont;
    if (!bodyFont.loadFromFile("bodyfont.ttf"))
    {
        std::cout << "Error: Body font not loaded" << std::endl;
    }
//    sf::Text description;
//    description.setFont(bodyFont);
//    description.setString("but without having to actually clean \nthe aquarium off algae and stuff");
//    description.setCharacterSize(45);
//    description.setPosition(sf::Vector2f(275, 320));

    Button newGame;
    newGame.setPosition(sf::Vector2f(60, 250));
    newGame.click(&newGameFile, window);
    sf::Text newGameText;
    newGameText.setFont(bodyFont);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(31);
    newGameText.setFillColor(sf::Color::Black);
    newGameText.setPosition(sf::Vector2f(60, 260));

    Button loadGame;
    loadGame.setPosition(sf::Vector2f(210, 250));
    loadGame.click(&loadGameFile, window);
    sf::Text loadGameText;
    loadGameText.setFont(bodyFont);
    loadGameText.setString("Load Game");
    loadGameText.setCharacterSize(31);
    loadGameText.setFillColor(sf::Color::Black);
    loadGameText.setPosition(sf::Vector2f(205, 260));


    window.draw(header);
 //   window.draw(description);
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
