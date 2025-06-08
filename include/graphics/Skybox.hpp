//
// Created by Gergő Gelegonya on 2025. 06. 08..
//

#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include <glad/glad.h>
#include <vector>
#include <string>
#include "graphics/Shader.hpp"

class Skybox {
public:
    Skybox(const std::vector<std::string>& faces);
    void draw(const Shader& shader, const glm::mat4& view, const glm::mat4& projection);

private:
    GLuint skyboxVAO, skyboxVBO;
    GLuint cubemapTexture;

    GLuint loadCubemap(const std::vector<std::string>& faces);
};

#endif
