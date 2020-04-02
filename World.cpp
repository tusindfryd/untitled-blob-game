#include "World.h"

int World::windowSize_ = 400;
std::string World::gameName_ = "Untitled Blob Game";
std::string World::iconPath_ = "icon2.png";

void World::run() {

    sf::RenderWindow window(sf::VideoMode(windowSize_, windowSize_), gameName_, sf::Style::Titlebar | sf::Style::Close);

    sf::Image icon;
    icon.loadFromFile(iconPath_);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite background;
    sf::Texture backgroundTexture;
    backgroundTexture.setSmooth(false);
    if (!backgroundTexture.loadFromFile("bg.png"))
    {
        std::cout << "Background texture not loaded" << std::endl;
    }

    background.setTexture(backgroundTexture);
    Game::setGame();
    sf::Clock clock;
    if(!Menu::openedMenu_) {
        clock.restart();
    }
    while (window.isOpen()) {
        window.clear(sf::Color(120, 128, 74));

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.draw(background);

        if (Menu::openedMenu_){
            Menu::drawMenu(window, windowSize_, gameName_);
        }
        else if (!Menu::openedMenu_){
            Game::displayTime(clock.restart().asSeconds() / 10, window);
            Game::drawGame(window, windowSize_);
        }
        window.display();
    }
}
