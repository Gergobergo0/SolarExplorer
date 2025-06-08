//
// Created by Gergő Gelegonya on 2025. 06. 08..
//
#include "ui/HUD.hpp"
#include <imgui.h>

HUD::HUD(TimeService& timeService, float gravity, Camera& cam)
    : timeServiceRef(timeService), gravityRef(gravity) {camera = &cam;}

void HUD::render() {
    ImGui::Begin("Simulation Settings");

    float dt = timeServiceRef.getDeltaTime();
    if (ImGui::SliderFloat("Delta Time", &dt, 0.0001f, 0.05f, "%.5f")) {
        timeServiceRef.setDeltaTime(dt);
    }

    ImGui::SliderFloat("Gravity (G)", &gravityRef, 0.001f, 0.1f, "%.5f");
    if (camera) {
        glm::vec3 pos = camera->getPosition();
        ImGui::Separator();
        ImGui::Text("Camera Position:");
        ImGui::Text("X: %.2f", pos.x);
        ImGui::Text("Y: %.2f", pos.y);
        ImGui::Text("Z: %.2f", pos.z);
    }

    ImGui::End();
}
