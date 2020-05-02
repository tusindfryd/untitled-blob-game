#pragma once

#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Menu.h"
#include "Game.h"
#include "Maze.h"
#include "Info.h"

class World {

public:
    static void run();
private:
    static int windowSize_;
    static int margin_;
    static std::string gameName_;
    static std::string iconPath_;
    static bool playMusic_;

    static void toggleMusic();
    static void toggleInfo();
};
