//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <vector>
#include "core/Object.hpp"

class SceneManager {
public:
    void add(Object* obj);
    void update(float dt);
    void draw(GLuint shaderID);

private:
    std::vector<Object*> objects;
};

#endif // SCENEMANAGER_HPP
