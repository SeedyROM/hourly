//
// Created by rombus on 7/7/18.
//

#include "Renderer.h"

const sf::RenderWindow& Renderer::setupDefaultWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window.create(sf::VideoMode(400, 400), "SFML works!", sf::Style::Default, settings);
    this->window.setFramerateLimit(60);
}

template<class ...Args>
const sf::RenderWindow& Renderer::setupWindow(Args... args) {
    this->window.create(args...);
    this->window.setFramerateLimit(60);
}
