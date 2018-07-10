#include <iostream>
#include <memory>
#include <unistd.h>
#include <cassert>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Hourly.h>

struct Wiggly : Entity {
    float x, y, d, z, z1;

    Wiggly() {
        x = 0;
        y = 100;
        d = 0;
        z = (rand() % 500) - 250.f;
        z1 = (rand() % 500) - 250.f;

    }

    void update(float dt) override {
        this->sprite.setRotation(this->sprite.getRotation() + (z / 32.f));
        this->sprite.setColor(sf::Color(255, 255, 255, 30));

        x += z * dt;
        y += z1 * dt;
        this->sprite.setPosition(x, y);

        float z = (cosf(x / 128));
        this->sprite.setScale(z, z);

        d += dt;
    }

    void render(sf::RenderWindow& window) override {
        // Wrap
        if(x >= window.getSize().x) x = 0;
        else if(x < 0) x = window.getSize().x;

        if(y >= window.getSize().y) y = 0;
        else if(y < 0) y = window.getSize().y;


        window.draw(this->sprite);
    }
};


int main() {
    Renderer renderer;
    renderer.setupDefaultWindow(1000, 500);

    sf::RenderWindow& window = renderer.window;
    TextureContext& textures = renderer.textures;

    sf::Texture t;
    t.setSmooth(true);
    std::string path = Filesystem::Path::join({Filesystem::getCwd(), "/../data"}) + "test.png";
    if(!t.loadFromFile(path)) {
        throw Filesystem::FileNotFound(path);
    }
    textures.addResource("test", t);

    std::vector<std::unique_ptr<Entity>> entities;
    for(int i = 0; i < 15; i++) {
        Wiggly e;
        e.setTexture(textures.getResource("test"));
        entities.push_back(std::make_unique<Wiggly>(e));
    }

    // Shitty motion blur
    sf::RectangleShape clear;
    clear.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    clear.setFillColor(sf::Color(255, 128, 10, 40));

    float dt = 0.2f;

    while (window.isOpen()) {
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(clear);

        clear.setFillColor(sf::Color(dt, dt * 4, cos(dt) * 200, 30));

        for(auto &e : entities) {
            e->update(1.f / 60.f);
            e->render(window);
        }

        window.display();

        dt += 0.5f;
    }

    return 0;
}
