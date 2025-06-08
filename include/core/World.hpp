//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#ifndef WORLD_HPP
#define WORLD_HPP

#include "Object.hpp"
#include <vector>
#include <memory>

class World {

public:
    void addObject(std::shared_ptr<Object> obj);
    void update(float deltaTime);
    const std::vector<std::shared_ptr<Object>>& getObjects() const {
        return objects;
    }

    float getG() { return G; }

private:
    std::vector<std::shared_ptr<Object>> objects;
    //const float G = 6.67430e-11f; // vagy egyszerűsítve: 1.0f a szimulációhoz
    float G =1.0f;
};

#endif

