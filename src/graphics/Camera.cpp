//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#include "graphics/Camera.hpp"

Camera::Camera(glm::vec3 position)
    : front(glm::vec3(0.0f, 0.0f, -1.0f)),
    movementSpeed(10.0f),
    mouseSensitivity(0.1f),
    yaw(-90.0f),
    pitch(0.0f),
    worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
    position(position) {
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(Camera_Movement dir, float dt) {
    float velocity = movementSpeed * dt;
    if (dir == Camera_Movement::FORWARD)  position += front * velocity;
    if (dir == Camera_Movement::BACKWARD) position -= front * velocity;
    if (dir == Camera_Movement::LEFT)     position -= right * velocity;
    if (dir == Camera_Movement::RIGHT)    position += right * velocity;
    if (dir == Camera_Movement::UP)    position += worldUp * velocity;
    if (dir == Camera_Movement::DOWN)  position -= worldUp * velocity;

}

void Camera::processMouseMovement(float xoffset, float yoffset) {
    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch -= yoffset;

    if (pitch > 89.0f)  pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(direction);

    right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}



