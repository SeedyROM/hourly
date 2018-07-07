//
// Created by rombus on 7/7/18.
//

#include <Entity.h>

Entity::Entity() {
    this->sprite.setPosition(0, 0);
}

Entity::Entity(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Entity::setTexture(std::shared_ptr<sf::Texture> texture) {
    this->texture = std::move(texture);
    this->sprite.setTexture(*this->texture);
    this->centerOrigin();
}

std::shared_ptr<sf::Texture> Entity::getTexture() {
    return this->texture;
}

void Entity::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

sf::Vector2f Entity::getPosition() {
    return this->sprite.getPosition();
}

void Entity::centerOrigin() {
    this->sprite.setOrigin(
            sf::Vector2f(
                    this->sprite.getGlobalBounds().width / 2.f,
                    this->sprite.getGlobalBounds().height / 2.f
            )
    );
}

void Entity::setOrigin(const float x, const float y) {
    this->sprite.setOrigin(sf::Vector2f(x, y));
}

