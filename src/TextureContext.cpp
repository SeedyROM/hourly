//
// Created by rombus on 7/7/18.
//

#include <memory>

#include "TextureContext.h"

bool TextureContext::addResource(const std::string& key, sf::Texture &texture) {
    if(this->resources.count(key) == 0) {
        this->resources[key] = std::make_shared<sf::Texture>(std::move(texture));
        return true;

    } else {
        return false;
    }
}

std::shared_ptr<sf::Texture> TextureContext::getResource(const std::string &key) {
    if(this->resources.find(key) == this->resources.end()) {
        throw InvalidResourceKey();
    }
    return this->resources[key];
}

const char *InvalidResourceKey::what() const noexcept {
    return "Invalid resource key!";
}
