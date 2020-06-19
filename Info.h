#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
class Info
{
public:
    static bool openedInfo_;
    static void setInfo(sf::Font &font);
    static void drawInfo(sf::RenderWindow &window);
    static void scrollInfo(int wheelDelta);
    static void setInfoPositionBack();

private:
    static sf::Text info_;
    static sf::RectangleShape infoBackground_;

};

