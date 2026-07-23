#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>

namespace Components {
    struct Position {
        float x;
        float y;
        float rotation = 0;
        float scale = 1.0f;
    };

    struct Velocity {
        float dx, dy;
    };

    namespace Sprite {
        struct Rectangle {
            sf::RectangleShape rect;
        };
    }
}

class Registry {
public:
    std::vector<std::optional<Components::Position>> positionComponent;
    std::vector<std::optional<Components::Velocity>> velocityComponent;
    std::vector<std::optional<Components::Sprite::Rectangle>> rectangleComponent;

    struct Args {
        Components::Position position;
        Components::Velocity velocity;
        Components::Sprite::Rectangle rectangle;
    };

    size_t last_id = 0;

    size_t createEntity();

    void addCompontentToEntity(size_t entity, const std::string& component, const Args& args);
};
