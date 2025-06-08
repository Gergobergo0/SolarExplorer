//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum class Camera_Movement {FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN};

class Camera {
public:
    Camera(glm::vec3 position);
    glm::mat4 getViewMatrix() const;
    void processKeyboard(Camera_Movement direction, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset);

    glm::vec3 getPosition() const {return position;}
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;
    float movementSpeed;
    float mouseSensitivity;

    void updateCameraVectors();
};
#endif //CAMERA_HPP
