//
// Created by rombus on 7/7/18.
//

#pragma once


#include <memory>
#include <SFML/Graphics.hpp>

struct Renderer {
    sf::RenderWindow* window;

    Renderer();
    ~Renderer();

    const sf::RenderWindow& setupDefaultWindow();
    template<class ...Args> const sf::RenderWindow& setupWindow(Args...);
};