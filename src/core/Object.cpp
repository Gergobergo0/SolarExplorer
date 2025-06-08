//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#include "core/Object.hpp"

Object::Object(const std::string& name,
               float mass,
               glm::vec3 position,
               glm::vec3 direction,
               float speed,
               glm::vec3 size)
    : name(name),
      mass(mass),
      position(position),
      acceleration(0.0f),
      size(size)
{
    if (glm::length(direction) > 1e-5f)
        velocity = glm::normalize(direction) * speed;
    else
        velocity = glm::vec3(0.0f);
}


glm::vec3& Object::getVelocity() {
    return velocity;
}

glm::vec3& Object::getAcceleration() {
    return acceleration;
}
