#include "controllers/InputController.hpp"
#include "graphics/Shader.hpp"
#include "services/SceneManager.hpp"
#include "services/TimeService.hpp"
#include "graphics/Camera.hpp"
#include "core/Cube.hpp"
#include "core/World.hpp"
#include "graphics/Skybox.hpp"
#include <glm/gtc/random.hpp>
#include "ui/HUD.hpp"
#include "ui/ImGuiPanel.hpp"


Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));

void addObjects(World& world) {
    const float G = world.getG();
    const float sunMass = 1000.0f;
    const glm::vec3 sunPos(0.0f);

    //nap
    world.addObject(std::make_shared<Cube>(
        "Sun",
        sunPos,
        sunMass,
        glm::vec3(0.0f),
        0.0f,
        glm::vec3(4.0f),
        glm::vec3(1.0f, 0.9f, 0.2f)
    ));

    struct PlanetConfig {
        float radius;
        float mass;
        float scale;
        glm::vec3 color;
    };

    std::vector<PlanetConfig> planets = {
        {8.0f, 2.0f, 1.0f, {0.8f, 0.3f, 0.3f}},
        {12.0f, 3.0f, 1.2f, {0.3f, 0.8f, 0.3f}},
        {17.0f, 5.0f, 1.5f, {0.3f, 0.3f, 0.9f}},
    };

    for (int i = 0; i < planets.size(); ++i) {
        float angle = glm::radians(45.0f * i); //kulonbozo iranyok
        float radius = planets[i].radius;
        glm::vec3 pos = sunPos + glm::vec3(
            radius * cos(angle),
            radius * sin(angle),
            0.0f
        );

        glm::vec3 dir = glm::normalize(pos - sunPos);
        glm::vec3 tangent = glm::normalize(glm::vec3(-dir.y, dir.x, 0.0f));

        float speed = std::sqrt(G * sunMass / radius);
        glm::vec3 velocity = tangent * speed;

        world.addObject(std::make_shared<Cube>(
            "Planet_" + std::to_string(i),
            pos,
            planets[i].mass,
            velocity,
            speed,
            glm::vec3(planets[i].scale),
            planets[i].color
        ));
    }

}






int main() {
    GLFWwindow* window = InputController::initWindow("Solar Explorer", 1600, 1200);
    InputController::setup(window, camera);

    Shader shader("shaders/shader.vert", "shaders/shader.frag");
    World world;
    TimeService time;
    HUD hud(time, world.getG(), camera);

    Shader skyboxShader("shaders/skybox.vert", "shaders/skybox.frag");
    std::vector<std::string> faces = {
        "assets/textures/skybox/right.png",
        "assets/textures/skybox/left.png",
        "assets/textures/skybox/top.png",
        "assets/textures/skybox/bottom.png",
        "assets/textures/skybox/front.png",
        "assets/textures/skybox/back.png"
    };
    Skybox skybox(faces);
/*
    const float G = 1.0f;
    float M = 200.0f;
    float r = 5.0f;
    float v = std::sqrt(G * M / r); // ≈ 6.32

    world.addObject(std::make_shared<Cube>(
        "Planet", glm::vec3(0, 0, 0), M, glm::vec3(0, 0, 0), 0.0f,
        glm::vec3(2.0f), glm::vec3(0.2f, 0.2f, 1.0f)
    ));

    world.addObject(std::make_shared<Cube>(
        "Satellite", glm::vec3(r, 0, 0), 1.0f, glm::vec3(0, 1, 0), v,
        glm::vec3(0.5f), glm::vec3(1.0f, 0.2f, 0.2f)
    ));*/
    addObjects(world);
    ImGuiPanel::setup(window);

    while (!glfwWindowShouldClose(window)) {
        time.update();
        InputController::processKeyboard(window, time.getDeltaTime(), camera);

        glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 500.0f);

        shader.use();
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        world.update(time.getDeltaTime() );
        for (const auto& obj : world.getObjects()) {
            obj->draw(shader.getID());
        }
        skybox.draw(skyboxShader, view, projection);
        ImGuiPanel::beginFrame();
        hud.render();
        ImGuiPanel::endFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
