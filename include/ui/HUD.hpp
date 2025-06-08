//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef HUD_HPP
#define HUD_HPP

#include "services/TimeService.hpp"
#include "graphics/Camera.hpp"


class HUD {
public:
    HUD(TimeService& timeService, float gravity, Camera& cam);
    void render();  //imgui elemek

private:
    TimeService& timeServiceRef;
    float gravityRef;
    Camera* camera;

};

#endif // HUD_HPP
