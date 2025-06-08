//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#ifndef CUBE_HPP
#define CUBE_HPP

#include "Object.hpp"
#include <glad/glad.h>

class Cube : public Object {
public:
    Cube(const std::string& name,
         glm::vec3 startPosition,
         float mass,
         glm::vec3 direction,
         float speed,
         glm::vec3 size,
         glm::vec3 color);
    void update(float deltaTime) override;
    void draw(GLuint shaderProgram) const override;

private:
    GLuint vao, vbo, ebo;
    static float cubeVertices[72];
    static unsigned int indices[36];
    glm::vec3 color;
    float scale;

};

#endif
