#include "Maze.h"

int Maze::map_[6][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 0, 1},
                        {1, 0, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0, 1},
                        {1, 2, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1, 1}};

sf::Sprite Maze::apple_;
std::vector <sf::RectangleShape> Maze::tiles_;

bool Maze::gameWon_ = false;
bool Maze::gameLost_ = false;

void Maze::setMaze(sf::Texture &appleTexture_) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            sf::RectangleShape tmp_tile;
            switch (map_[i][j]) {
            case 1:
                tmp_tile.setFillColor(sf::Color::Black);
                tmp_tile.setPosition(j * 46 + 62, i * 46 + 62);
                tmp_tile.setSize(sf::Vector2f(46, 46));
                break;
            case 2:
                apple_.setPosition(j * 46 + 72, i * 46 + 73);
                apple_.setTexture(appleTexture_);
            default:
                break;
            }
            tiles_.emplace_back(tmp_tile);
        }
    }
}

void Maze::drawMaze(sf::RenderWindow &window, sf::Sprite &sprite) {
    foundApple(sprite);

    if (isTouchingWall(sprite)) {
        gameLost_ = true;
    }

    window.draw(apple_);
    for (auto &el : tiles_) {
        window.draw(el);
    }
}

void Maze::foundApple(sf::Sprite &sprite) {
    gameWon_ = false;

    bool isTouchingLeftWall = int(apple_.getGlobalBounds().left == int(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width));
    bool isTouchingRightWall = int(apple_.getGlobalBounds().left + apple_.getGlobalBounds().width) == int(sprite.getGlobalBounds().left);
    bool isAtSameHeight = int(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) > int(apple_.getGlobalBounds().top) &&
            int(sprite.getGlobalBounds().top) < int(apple_.getGlobalBounds().top + apple_.getGlobalBounds().height);

    bool isTouchingBottomWall = int(apple_.getGlobalBounds().top == int(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height));
    bool isTouchingTopWall = int(apple_.getGlobalBounds().top + apple_.getGlobalBounds().height) == int(sprite.getGlobalBounds().top);
    bool isAtSameWidth = int(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) > int(apple_.getGlobalBounds().left) &&
            int(sprite.getGlobalBounds().left) < int(apple_.getGlobalBounds().left + apple_.getGlobalBounds().width);

    if (isTouchingRightWall && isAtSameHeight) {
        gameWon_ = true;
    }
    if (isTouchingLeftWall && isAtSameHeight) {
        gameWon_ = true;
    }
    if (isTouchingBottomWall && isAtSameWidth) {
        gameWon_ = true;
    }
    if (isTouchingTopWall && isAtSameWidth) {
        gameWon_ = true;
    }
}

bool Maze::isTouchingWall(sf::Sprite &sprite) {
    bool isTouchingWall_ = false;
    for (auto &el : tiles_) {
        bool isTouchingLeftWall = int(el.getGlobalBounds().left == int(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width));
        bool isTouchingRightWall = int(el.getGlobalBounds().left + el.getGlobalBounds().width) == int(sprite.getGlobalBounds().left);
        bool isAtSameHeight = int(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) > int(el.getGlobalBounds().top) &&
                int(sprite.getGlobalBounds().top) < int(el.getGlobalBounds().top + el.getGlobalBounds().height);

        bool isTouchingBottomWall = int(el.getGlobalBounds().top == int(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height));
        bool isTouchingTopWall = int(el.getGlobalBounds().top + el.getGlobalBounds().height) == int(sprite.getGlobalBounds().top);
        bool isAtSameWidth = int(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) > int(el.getGlobalBounds().left) &&
                int(sprite.getGlobalBounds().left) < int(el.getGlobalBounds().left + el.getGlobalBounds().width);

        if (isTouchingRightWall && isAtSameHeight) {
            isTouchingWall_ = true;
            break;
        }
        if (isTouchingLeftWall && isAtSameHeight) {
            isTouchingWall_ = true;
            break;

        }
        if (isTouchingBottomWall && isAtSameWidth) {
            isTouchingWall_ = true;
            break;

        }
        if (isTouchingTopWall && isAtSameWidth) {
            isTouchingWall_ = true;
            break;
        }
    }
    return isTouchingWall_;
}

