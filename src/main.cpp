#include <SFML/Graphics.hpp>
#include "../include/input.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "TestEngine");
    sf::Clock clock;
    keyMap keymap;
    float acumulator = 0;
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        acumulator += dt;

        while (const auto event = window.pollEvent()) {
            if (event && event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::W) {
                    keymap.up = true;
                }
                if (keyPressed->code == sf::Keyboard::Key::A) {
                    keymap.left = true;
                }
                if (keyPressed->code == sf::Keyboard::Key::S) {
                    keymap.down = true;
                }
                if (keyPressed->code == sf::Keyboard::Key::D) {
                    keymap.right = true;
                }
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                    keymap.space = true;
                }
            }
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                if (keyReleased->code == sf::Keyboard::Key::W) {
                    keymap.up = false;
                }
                if (keyReleased->code == sf::Keyboard::Key::A) {
                    keymap.left = false;
                }
                if (keyReleased->code == sf::Keyboard::Key::S) {
                    keymap.down = false;
                }
                if (keyReleased->code == sf::Keyboard::Key::D) {
                    keymap.right = false;
                }
                if (keyReleased->code == sf::Keyboard::Key::Space) {
                    keymap.space = false;
                }
            }
        }

        const float TIME_STEP = 0.0333f;
        while (acumulator >= TIME_STEP) {
            acumulator -= TIME_STEP;
        }

        window.clear();
        window.display();
    }

    return 0;
}

