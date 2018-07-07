//
// Created by rombus on 7/7/18.
//

#pragma once


#include <memory>
#include <SFML/Graphics.hpp>

#include <TextureContext.h>

struct Renderer {
    sf::RenderWindow window;
    TextureContext textures;
    
    const sf::RenderWindow& setupDefaultWindow();
    template<class ...Args> const sf::RenderWindow& setupWindow(Args...);
};