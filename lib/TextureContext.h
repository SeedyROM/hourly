//
// Created by rombus on 7/7/18.
//

#pragma once

#include <unordered_map>

#include <SFML/Graphics.hpp>

struct TextureContext {
    bool addResource(const std::string& key, sf::Texture& texture);
    std::shared_ptr<sf::Texture> getResource(const std::string &key);

protected:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> resources;
};
