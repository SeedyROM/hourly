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
    
    void setupDefaultWindow();
    void setupDefaultWindow(unsigned int x, unsigned int y);
    template<class ...Args> void setupWindow(Args...);

};