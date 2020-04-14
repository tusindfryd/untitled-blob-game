#pragma once

#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "Game.h"
#include "Maze.h"
//#include "Catch.h"

class World {

public:
    static void run();
private:
    static int windowSize_;
    static std::string gameName_;
    static std::string iconPath_;
};
