#include <iostream>
#include <memory>
#include <unistd.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Hourly.h>

struct Wiggly : Entity {
    float x, y, d;

    Wiggly() {
        x = 0;
        y = 100;
        d = 0;
    }

    void update(float dt) override {
        this->sprite.setRotation(this->sprite.getRotation() + 0.3f);

        x += 6;
        y += 1;
        this->sprite.setPosition(x, y);

        float z = cosf(tanf(d));
        this->sprite.setScale(z, z);

        d += 0.02;
    }

    void render(sf::RenderWindow& window) override {
        // Wrap
        if(x >= window.getSize().x) x = 0;
        else if(y >= window.getSize().y) y = 0;

        window.draw(this->sprite);
    }
};


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

    Wiggly e;
    textures.addResource("test", t);
    e.setTexture(textures.getResource("test"));

    Wiggly e1;
    e1.setTexture(textures.getResource("test"));
    e1.y = 300;

    // Shitty motion blur
    sf::RectangleShape clear;
    clear.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    clear.setFillColor(sf::Color(255, 128, 10, 40));

    while (window.isOpen()) {
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(clear);

        e.update(0.002);
        e.render(window);

        e1.update(0.002);
        e1.render(window);

        window.display();
    }

    return 0;
}
