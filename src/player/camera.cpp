#include "player/camera.hpp"

#include <algorithm>

namespace Tyra {

    Camera::Camera(Tyra::Pad* t_pad)
      : lookAt(0.0F),
        position(-2000.0F, 0.0F, -6000.0F),
        pad(t_pad),
        circleRotation(-5.0F),
        circleLength(30.0F),
        speed(20.0F),
        lookAtHeight(-4.0F) {}

    Camera::~Camera() {}

    void Camera::update() {

        updatePosition();
        updateLookAt();
    }

    void Camera::updatePosition() {

        const auto& leftJoy = pad->getLeftJoyPad();

        Vec4 direction;

        if (unitCircle.length() > 0.0F) {
            direction = Vec4(unitCircle).getNormalized() * speed;
        }
        else {
            direction = Tyra::Vec4(0.0F);
        }

        if (leftJoy.v <= 100) {

            position.x += direction.x;
            position.z += direction.z;
        }
        else if (leftJoy.v >= 200) {
            position.x += -direction.x;
            position.z += -direction.z;
        }

        if (leftJoy.h <= 100) {
            position.x += direction.z;
            position.z += -direction.x;
        }
        else if (leftJoy.h >= 200) {
            position.x += -direction.z;
            position.z += direction.x;
        }

        position.y = 700.0F;
    }

    void Camera::updateLookAt() {

        const float rotationOffset = 0.045F;
        const float heightOffset = 2.0F;
        const auto& rightJoy = pad->getRightJoyPad();

        if (rightJoy.h <= 100) {
            circleRotation -= rotationOffset * (200 - rightJoy.h) / 100.0F;
        } 
        else if (rightJoy.h >= 200) {
            circleRotation += rotationOffset * (rightJoy.h - 200) / 100.0F;
        }

        if (rightJoy.v <= 100) {
            lookAtHeight -= heightOffset * (200 - rightJoy.v) / 100.0F;
        }
        else if (rightJoy.v >= 200) {
            lookAtHeight += heightOffset * (rightJoy.v - 200) / 100.0F;
        }

        lookAtHeight = std::clamp(lookAtHeight, -50.0F, 50.0F);

        unitCircle.x = Math::sin(circleRotation) * circleLength;
        unitCircle.y = lookAtHeight;
        unitCircle.z = Math::cos(circleRotation) * circleLength;

        lookAt = unitCircle + position;
    }
}