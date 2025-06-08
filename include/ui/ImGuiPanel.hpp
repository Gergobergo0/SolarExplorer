//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef IMGUIPANEL_HPP
#define IMGUIPANEL_HPP
#include <GLFW/glfw3.h>
class ImGuiPanel {
public:
    static void setup(GLFWwindow* window);
    static void beginFrame();
    static void endFrame();
};

#endif // IMGUIPANEL_HPP
