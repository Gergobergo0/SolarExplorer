#ifndef SHADER_LOADER_HPP
#define SHADER_LOADER_HPP

#include <string>
#include <glad/glad.h>

class ShaderLoader {
public:
    static GLuint LoadShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
private:
    static std::string ReadFile(const std::string& filePath);
    static GLuint CompileShader(const std::string& source, GLenum shaderType);
};

#endif
