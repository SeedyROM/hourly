#include <iostream>
#include <memory>
#include <unistd.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Entity.h>
#include <Filesystem.h>

using namespace Filesystem;

int main() {
    sf::Texture t;
    std::string path = Path::join({getCwd(), "/../data", "/test.png"});

    if(!t.loadFromFile(path)) {
        throw FileNotFound(path);
    }

    t.setSmooth(true);
    auto tsp = std::make_shared<sf::Texture>(t);

    Entity e;
    e.setTexture(tsp);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    float x = 0;

    while (window.isOpen()) {
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 128, 0));
        e.sprite.setRotation(e.sprite.getRotation() + 0.7f);
        x += 1;
        e.sprite.setPosition(x, 100);
        window.draw(e.sprite);
        window.display();
    }

    return 0;
}
