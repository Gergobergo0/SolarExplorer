//
// Created by Gergő Gelegonya on 2025. 06. 08..
//
#define GLM_ENABLE_EXPERIMENTAL
#include "core/World.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
void World::addObject(std::shared_ptr<Object> obj) {
    objects.push_back(obj);
}
void World::update(float deltaTime) {
    //gravitacios gyorsulas
    for (auto& objA : objects) {
        glm::vec3 totalAccel(0.0f);

        for (auto& objB : objects) {
            if (objA == objB) continue;

            glm::vec3 dir = objB->getPosition() - objA->getPosition();
            float dist = glm::length(dir);
            if (dist < 1e-5f) continue; //kozeli objektumok kerulese

            glm::vec3 normDir = glm::normalize(dir);
            float accelMag = G * objB->getMass() / (dist * dist);
            totalAccel += accelMag * normDir;
        }

        objA->setAcceleration(totalAccel);
    }

    //utkozes
    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
            auto& objA = objects[i];
            auto& objB = objects[j];

            glm::vec3 diff = objB->getPosition() - objA->getPosition();
            float dist = glm::length(diff);
            float minDist = (glm::length(objA->getSize()) + glm::length(objB->getSize())) * 0.5f;

            if (dist < minDist && dist > 1e-5f) {
                glm::vec3 normal = glm::normalize(diff);
                float overlap = minDist - dist;

                glm::vec3 repulsion = normal * overlap * 2.0f;

                objA->setVelocity(objA->getVelocity() - repulsion * 0.5f);
                objB->setVelocity(objB->getVelocity() + repulsion * 0.5f);

                objA->setVelocity(objA->getVelocity() * 0.98f);
                objB->setVelocity(objB->getVelocity() * 0.98f);
            }
        }
    }

    //uj sebesseg es pozicio
    for (auto& obj : objects) {
        obj->setVelocity(obj->getVelocity() + obj->getAcceleration() * deltaTime);
        obj->setPosition(obj->getPosition() + obj->getVelocity() * deltaTime);
    }
}


