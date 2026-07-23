#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <optional>
#include "../include/input.hpp"
#include "../include/ecs.hpp"

#include "../include/ecs.hpp"

size_t Registry::createEntity() {
    const size_t entity = last_id;
    ++last_id;
    return entity;
}

void Registry::addCompontentToEntity(size_t entity, const std::string& component, const Args& args) {
    if (component == "Components::Position") {
        if (positionComponent.size() <= entity) {
            positionComponent.resize(entity + 1);
        }
        positionComponent[entity] = args.position;
    } else if (component == "Components::Velocity") {
        if (velocityComponent.size() <= entity) {
            velocityComponent.resize(entity + 1);
        }
        velocityComponent[entity] = args.velocity;
    } else if (component == "Components::Sprite::Rectangle") {
        if (rectangleComponent.size() <= entity) {
            rectangleComponent.resize(entity + 1);
        }
        rectangleComponent[entity] = args.rectangle;
    }
}