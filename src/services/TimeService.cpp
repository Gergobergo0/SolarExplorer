//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "services/TimeService.hpp"

void TimeService::update() {
    float currentFrame = (float)glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

float TimeService::getDeltaTime() const {
    return deltaTime;
}

void TimeService::setDeltaTime(float dt) {
    deltaTime = dt;
}


