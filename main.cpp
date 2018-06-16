#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SpriteAnimation.h>

int main() {
    auto *s = new Animation::SpriteAnimation();
    std::cout << "Hello, Boys and Girls!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
