//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef SHADER_HPP
#define SHADER_HPP
#pragma once
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    GLuint getID() const;

    void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
    GLuint ID;
    GLuint loadShader(const char* path, GLenum type);
    GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath);
};


#endif //SHADER_HPP
