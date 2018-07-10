//
// Created by rombus on 7/7/18.
//

#include "Renderer.h"

void Renderer::setupDefaultWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window.create(sf::VideoMode(800, 400), "Hourly", sf::Style::Default, settings);
    this->window.setFramerateLimit(60);
}

template<class ...Args>
void Renderer::setupWindow(Args... args) {
    this->window.create(args...);
    this->window.setFramerateLimit(60);
}

void Renderer::setupDefaultWindow(unsigned int x, unsigned int y) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window.create(sf::VideoMode(x, y), "Hourly", sf::Style::Default, settings);
    this->window.setFramerateLimit(60);
}
