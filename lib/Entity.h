//
// Created by rombus on 7/7/18.
//

#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

struct Entity {
    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> texture;

    Entity();
    Entity(const float x, const float y);

    void setTexture(std::shared_ptr<sf::Texture> texture);
    std::shared_ptr<sf::Texture> getTexture();

    sf::Vector2f getPosition();
    void setPosition(const float x, const float y);
};
