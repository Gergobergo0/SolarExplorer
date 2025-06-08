//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#include "core/Cube.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <GLFW/glfw3.h>

float Cube::cubeVertices[] = {
    -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  -0.5f, 0.5f,-0.5f,
    -0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,  -0.5f, 0.5f, 0.5f
};
unsigned int Cube::indices[] = {
    0,1,2, 2,3,0,
    4,5,6, 6,7,4,
    0,1,5, 5,4,0,
    2,3,7, 7,6,2,
    0,3,7, 7,4,0,
    1,2,6, 6,5,1
};

Cube::Cube(const std::string& name,
           glm::vec3 position,
           float mass,
           glm::vec3 direction,
           float speed,
           glm::vec3 size,
           glm::vec3 color)
    : Object(name, mass, position, direction, speed, size), color(color) {

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
}

void Cube::update(float deltaTime) {
    //forgatas
    float t = (float)glfwGetTime();
}

void Cube::draw(GLuint shaderProgram) const {
    glUniform3fv(glGetUniformLocation(shaderProgram, "objectColor"), 1, glm::value_ptr(color));


    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
    model = glm::scale(model, size);


    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

