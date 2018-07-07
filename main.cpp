#include <iostream>
#include <memory>
#include <unistd.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Entity.h>
#include <Filesystem.h>


int main() {
    sf::Texture t;
    std::string path = Filesystem::getCwd() + "/../data" + "/test.png";

    if(!t.loadFromFile(path)) {
        throw Filesystem::FileNotFound(path);
    }


    auto tsp = std::make_shared<sf::Texture>(t);

    Entity e;
    e.setTexture(tsp);

    sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");

    while (window.isOpen()) {
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 128, 0));
        window.draw(e.sprite);
        window.display();
    }

    return 0;
}
