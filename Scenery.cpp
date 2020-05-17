#include "Scenery.h"

bool Scenery::openedSceneryChooser_ = false;
std::vector<Button> Scenery::buttons_;
std::vector<sf::Text> Scenery::labels_;
std::vector<bool> Scenery::setters_{true, false, false, false};
bool Scenery::updateNeeded_ = false;
int Scenery::choosenSceneryIndex_ = 0;

void Scenery::setSceneryChooser(sf::Font &font) {

    for (int i = 0; i < 4; i++) {
        Button button;
        button.setSize(sf::Vector2f(120, 40));
        button.setPosition(sf::Vector2f(80, 60+(24*(i+1))+i*40));
        buttons_.emplace_back(button);

        sf::Text label;
        label.setFont(font);
        label.setCharacterSize(30);
        label.setFillColor(sf::Color::Black);
        label.setPosition(sf::Vector2f(100, 60+(24*(i+1))+i*40));
        labels_.emplace_back(label);
    }

    labels_[0].setString("0");
    labels_[1].setString("200");
    labels_[2].setString("400");
    labels_[3].setString("600");
}

void Scenery::drawSceneryChooser(sf::RenderWindow &window, int &timePoints) {
    for (int i = 0; i < 4; i++) {
        window.draw(buttons_[i]);
        window.draw(labels_[i]);
    }
    buttons_[0].click(setScenery0, window);
    if (timePoints > 200) {
        buttons_[1].click(setScenery1, window);
    }
    if (timePoints > 400) {
        buttons_[2].click(setScenery2, window);
    }
    if (timePoints > 600) {
        buttons_[3].click(setScenery3, window);
    }

    for (int i = 0; i < setters_.size(); i++) {
        if (setters_[i]) {
             choosenSceneryIndex_ = i;
             break;
        }
    }
}

void Scenery::setScenery0() {
    if (!setters_[0]) {
        setters_[0] = true;
        setters_[1] = false;
        setters_[2] = false;
        setters_[3] = false;
    }
    updateNeeded_ = true;
    openedSceneryChooser_ = false;
}

void Scenery::setScenery1() {
    if (!setters_[1]) {
        setters_[0] = false;
        setters_[1] = true;
        setters_[2] = false;
        setters_[3] = false;
    }
    updateNeeded_ = true;
    openedSceneryChooser_ = false;

}

void Scenery::setScenery2() {
    if (!setters_[2]) {
        setters_[0] = false;
        setters_[1] = false;
        setters_[2] = true;
        setters_[3] = false;
    }
    updateNeeded_ = true;
    openedSceneryChooser_ = false;

}

void Scenery::setScenery3() {
    if (!setters_[3]) {
        setters_[0] = false;
        setters_[1] = false;
        setters_[2] = false;
        setters_[3] = true;
    }
    updateNeeded_ = true;
    openedSceneryChooser_ = false;

}
