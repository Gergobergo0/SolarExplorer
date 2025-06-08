//
// Created by Gergő Gelegonya on 2025. 06. 08..
//
#include "services/SceneManager.hpp"

void SceneManager::add(Object* obj) {
    objects.push_back(obj);
}

void SceneManager::update(float dt) {
    for (auto* obj : objects)
        obj->update(dt);
}

void SceneManager::draw(GLuint shaderID) {
    for (auto* obj : objects)
        obj->draw(shaderID);
}
