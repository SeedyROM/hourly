#include <iostream>
#include <memory>
#include <unistd.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Hourly.h>

int main() {
    Renderer renderer;
    renderer.setupDefaultWindow();

    sf::RenderWindow& window = renderer.window;
    TextureContext& textures = renderer.textures;

    sf::Texture t;
    t.setSmooth(true);
    std::string path = Filesystem::Path::join({Filesystem::getCwd(), "/../data"}) + "test.png";
    if(!t.loadFromFile(path)) {
        throw Filesystem::FileNotFound(path);
    }

    Entity e;
    textures.addResource("test", t);
    e.setTexture(textures.getResource("test"));

    float x = 0;

    // Shitty motion blur
    sf::RectangleShape clear;
    clear.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    clear.setFillColor(sf::Color(255, 128, 10, 10));

    while (window.isOpen()) {
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(clear);

        // Update
        e.sprite.setRotation(e.sprite.getRotation() + 0.3f);
        x += 3;
        e.sprite.setPosition(x, 100);

        if(x >= window.getSize().x) x = 0;

        // Draw
        window.draw(e.sprite);

        window.display();
    }

    return 0;
}
