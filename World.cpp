#include "World.h"

int World::windowSize_ = 400;
int World::margin_ = 62;
std::string World::gameName_ = "Untitled Blob Game";
std::string World::iconPath_ = "assets/images/icon2.png";
bool World::playMusic_ = true;

void World::run() {

    sf::RenderWindow window(sf::VideoMode(windowSize_, windowSize_), gameName_, sf::Style::Titlebar | sf::Style::Close);

    sf::Image icon;
    icon.loadFromFile(iconPath_);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Button playMusicButton;
    playMusicButton.setPosition(305, 10);
    playMusicButton.setSize(sf::Vector2f(40, 40));
    sf::Music music;
    if (!music.openFromFile("assets/sounds/music.ogg")) {
        std::cout << "Music not loaded" << std::endl;
    }
    music.setLoop(true);
    music.play();

    sf::Sprite background;
    sf::Texture backgroundTexture;
    backgroundTexture.setSmooth(false);
    if (!backgroundTexture.loadFromFile("assets/images/bg.png"))
    {
        std::cout << "Background texture not loaded" << std::endl;
    }

    Button::setSound();
    background.setTexture(backgroundTexture);
    Menu::setMenu(gameName_);
    Game::setGame();


    sf::Clock clock;
    if(!Menu::openedMenu_) {
        clock.restart();
    }
    while (window.isOpen()) {
        window.clear(sf::Color(147, 202, 91));

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
        if (!playMusic_) {
            music.setVolume(0);
        }
        else {
            music.setVolume(100);
        }
        playMusicButton.click(&toggleMusic, window);

        if (Menu::openedMenu_) {
            Menu::drawMenu(window);

        }
        else if (!Menu::openedMenu_) {

            Game::displayTime(clock.restart().asSeconds() / 10, window);
            Game::drawGame(window, windowSize_, margin_);
        }

        window.display();
    }
}

void World::toggleMusic() {
    if (playMusic_) {
        playMusic_ = false;
    }
    else if (!playMusic_) {
        playMusic_ = true;
    }
}
