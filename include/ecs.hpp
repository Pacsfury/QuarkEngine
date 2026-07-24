#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>
#include <type_traits>

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

    template <typename T>
    void addCompontentToEntity(size_t entity, const Args& args);
};

template <>
inline void Registry::addCompontentToEntity<Components::Position>(size_t entity, const Registry::Args& args) {
    if (positionComponent.size() <= entity) {
        positionComponent.resize(entity + 1);
    }
    positionComponent[entity] = args.position;
}

template <>
inline void Registry::addCompontentToEntity<Components::Velocity>(size_t entity, const Registry::Args& args) {
    if (velocityComponent.size() <= entity) {
        velocityComponent.resize(entity + 1);
    }
    velocityComponent[entity] = args.velocity;
}

template <>
inline void Registry::addCompontentToEntity<Components::Sprite::Rectangle>(size_t entity, const Registry::Args& args) {
    if (rectangleComponent.size() <= entity) {
        rectangleComponent.resize(entity + 1);
    }
    rectangleComponent[entity] = args.rectangle;
}