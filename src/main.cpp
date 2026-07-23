#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/input.hpp"
#include "../include/ecs.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "TestEngine");
    sf::Clock clock;
    keyMap keymap = {};
    Registry Ecs;
    float acumulator = 0;
    window.setFramerateLimit(60);
    size_t player = Ecs.createEntity();

    Registry::Args args;
    args.position = {400.5f, 300.5f, 0.0f, 1.0f};
    
    args.rectangle.rect.setSize(sf::Vector2f(50.0f, 50.0f));
    args.rectangle.rect.setFillColor(sf::Color::Green);
    args.rectangle.rect.setOrigin(sf::Vector2f(25.0f, 25.0f));
    args.rectangle.rect.setPosition(sf::Vector2f(args.position.x, args.position.y));

    Ecs.addCompontentToEntity(player, "Components::Position", args);
    Ecs.addCompontentToEntity(player, "Components::Sprite::Rectangle", args);

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        acumulator += dt;

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
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

        window.clear(sf::Color::Black);

        for (size_t i = 0; i <= Ecs.last_id; i++) {
            if (i < Ecs.rectangleComponent.size() && Ecs.rectangleComponent[i].has_value()) {
                if (i < Ecs.positionComponent.size() && Ecs.positionComponent[i].has_value()) {
                    Ecs.rectangleComponent[i]->rect.setPosition(
                        sf::Vector2f(
                            Ecs.positionComponent[i]->x,
                            Ecs.positionComponent[i]->y
                        )
                    );
                }

                window.draw(Ecs.rectangleComponent[i]->rect);
            }
        }

        window.display();
    }

    return 0;
}