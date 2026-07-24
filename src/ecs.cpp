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
