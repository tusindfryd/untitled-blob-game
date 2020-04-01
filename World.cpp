#include "World.h"

void World::run() {

    sf::RenderWindow window(sf::VideoMode(1200, 660), "Goldfish Simulator", sf::Style::Titlebar | sf::Style::Close);

    sf::Image icon;
    icon.loadFromFile("icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite background;
    sf::Texture backgroundTexture;
    backgroundTexture.setSmooth(false);
    if (!backgroundTexture.loadFromFile("bg.png"))
    {
        std::cout << "Background texture not loaded" << std::endl;
    }

    background.setTexture(backgroundTexture);
    sf::Clock clock;
    if(!Menu::openedMenu_) {
        clock.restart();
    }
    while (window.isOpen()) {
        window.clear(sf::Color::Black);

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
            Menu::drawMenu(window);
        }
        else if (!Menu::openedMenu_){
            Game::displayTime(clock.restart().asSeconds() / 10, window);
            Game::drawGame(window);
        }
        window.display();
    }
}
