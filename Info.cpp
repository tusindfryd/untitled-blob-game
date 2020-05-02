#include "Info.h"

bool Info::openedInfo_ = false;
sf::Text Info::info_;
sf::RectangleShape Info::infoBackground_;

void Info::setInfo(sf::Font &font) {
    infoBackground_.setFillColor(sf::Color(147, 202, 91));
    infoBackground_.setSize(sf::Vector2f(280, 276));
    infoBackground_.setPosition(sf::Vector2f(60, 62));
    info_.setFont(font);
    info_.setString("\t\t\t\t\t Credits \n Fonts: Pixelated \n by Skylar Park \n Music: \"Opening\" \n by t4ngr4m \n Sounds: Little Robot \n Sound Factory");
    info_.setCharacterSize(30);
    info_.setFillColor(sf::Color::Black);
    info_.setPosition(sf::Vector2f(65, 65));
}
void Info::drawInfo(sf::RenderWindow &window) {
    window.draw(infoBackground_);
    window.draw(info_);
}
