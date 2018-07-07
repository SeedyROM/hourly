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
    Entity(float x, float y);

    void centerOrigin();
    void setOrigin(float x, float y);

    void setTexture(std::shared_ptr<sf::Texture> texture);
    std::shared_ptr<sf::Texture> getTexture();

    sf::Vector2f getPosition();
    void setPosition(float x, float y);

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
