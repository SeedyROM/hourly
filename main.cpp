#include <iostream>
#include <memory>
#include <unistd.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Hourly.h>

int main() {
    sf::Texture t;
    std::string path = Filesystem::Path::join({Filesystem::getCwd(), "/../data"}) + "test.png";

    if(!t.loadFromFile(path)) {
        throw Filesystem::FileNotFound(path);
    }
    t.setSmooth(true);

    TextureContext tc;
    tc.addResource("test", t);

    Entity e;
    e.setTexture(tc.getResource("test"));

    Renderer renderer;
    renderer.setupDefaultWindow();
    auto window = renderer.window;

    float x = 0;

    while (window->isOpen()) {
        sf::Event event = sf::Event();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear(sf::Color(255, 128, 0));

        // Update
        e.sprite.setRotation(e.sprite.getRotation() + 0.7f);
        x += 1;
        e.sprite.setPosition(x, 100);

        // Draw
        window->draw(e.sprite);

        window->display();
    }

    return 0;
}
