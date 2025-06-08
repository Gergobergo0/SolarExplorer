//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef INPUTCONTROLLER_HPP
#define INPUTCONTROLLER_HPP
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include "graphics/Camera.hpp"

class InputController {
public:
    static void setup(GLFWwindow* window, Camera& cam);
    static void processKeyboard(GLFWwindow* window, float deltaTime, Camera& cam);
    static GLFWwindow* initWindow(const char* title, int width, int height);
    static bool mouseLocked;
private:
    static inline float lastX = 400.0f;
    static inline float lastY = 300.0f;
    static inline bool firstMouse = true;
    static inline Camera* camera = nullptr;
    static bool cursorVisible;
    static void toggleCursor(GLFWwindow* window);

    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};

#endif // INPUTCONTROLLER_HPP
