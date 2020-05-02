#include "Info.h"

bool Info::openedInfo_ = false;
sf::Text Info::info_;
sf::RectangleShape Info::infoBackground_;

void Info::setInfo(sf::Font &font) {
    infoBackground_.setFillColor(sf::Color(147, 202, 91));
    infoBackground_.setSize(sf::Vector2f(280, 276));
    infoBackground_.setPosition(sf::Vector2f(60, 62));
    info_.setFont(font);
    info_.setString("Credits \n\n Fonts: \n Pixelated by Skylar Park \n Alagard by Hewett Tsoi \n\n Music: \n \"Opening\" by t4ngr4m \n\n Sounds: \n Little Robot Sound Factory");
    info_.setCharacterSize(16);
    info_.setFillColor(sf::Color::Black);
    info_.setPosition(sf::Vector2f(65, 65));
}
void Info::drawInfo(sf::RenderWindow &window) {
    window.draw(infoBackground_);
    window.draw(info_);
}
