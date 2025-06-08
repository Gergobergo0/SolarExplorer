//
// Created by Gergő Gelegonya on 2025. 06. 05..
//

#ifndef TIMESERVICE_HPP
#define TIMESERVICE_HPP

class TimeService {
public:
    void update();
    float getDeltaTime() const;
    void setDeltaTime(float dt);
private:
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
};

#endif // TIMESERVICE_HPP
