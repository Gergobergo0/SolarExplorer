#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>
#include <string>
#include <glad/glad.h>

class Object {
public:

    Object(const std::string& name,
        float mass,
        glm::vec3 position,
        glm::vec3 direction,
        float speed,
        glm::vec3 size);
    virtual ~Object() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(GLuint shaderProgram) const = 0;
    glm::vec3 getSize() const { return size; }

    glm::vec3& getVelocity();
    glm::vec3& getAcceleration();
    const std::string& getName() const { return name; }
    float getMass() const { return mass; }
    glm::vec3 getPosition() const { return position; }


    void setAcceleration(const glm::vec3& acc) { acceleration = acc; }
    void setVelocity(const glm::vec3& vel) { velocity = vel; }
    void setPosition(const glm::vec3& pos) { position = pos; }

protected:
    std::string name;
    float mass;
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 size;
};

#endif
