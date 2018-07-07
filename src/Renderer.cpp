//
// Created by rombus on 7/7/18.
//

#include "Renderer.h"

const sf::RenderWindow& Renderer::setupDefaultWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window = new sf::RenderWindow(sf::VideoMode(800, 400), "SFML works!", sf::Style::Default, settings);
    window->setFramerateLimit(60);
}

template<class ...Args>
const sf::RenderWindow& Renderer::setupWindow(Args... args) {
    this->window = new sf::RenderWindow(args...);
    window->setFramerateLimit(60);
}

Renderer::~Renderer() {
    free(this->window);
}

Renderer::Renderer() {
    this->window = nullptr;
}
