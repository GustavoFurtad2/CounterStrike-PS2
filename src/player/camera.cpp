#include "player/camera.hpp"

#include <algorithm>

Camera::Camera(Tyra::Pad* t_pad)
  : lookAt(0.0F),
    position(0.0F, 40.0F, 0.0F),
    pad(t_pad),
    circleRotation(0.0F),
    circleLength(30.0F),
    pitch(0.0F),
    yaw(270.0F),
    sensitivity(4.58425F) {}

Camera::~Camera() {}

void Camera::update() {

    rotate();
    updatePosition();
    updateLookAt();
}

void Camera::rotate() {

    const auto& rightJoy = pad->getRightJoyPad();

    if (rightJoy.h <= 100) {
        yaw -= sensitivity;
    } 
    else if (rightJoy.h >= 200) {
        yaw += sensitivity;
    }

    if (rightJoy.v <= 100) {
        pitch += sensitivity;
    } 
    else if (rightJoy.v >= 200) {
        pitch -= sensitivity;
    }

    if (pitch > 89.0F) {
        pitch = 89.0F; 
    }
    else if (pitch < -89.0F) {
        pitch = -89.0F;
    }
}

void Camera::updatePosition() {

    position.y = 40.0F;
}

void Camera::updateLookAt() {

    lookAt.x = Tyra::Math::cos(degreesToRadians(yaw)) * Tyra::Math::cos(degreesToRadians(pitch));
    lookAt.y = Tyra::Math::sin(degreesToRadians(pitch));
    lookAt.z = Tyra::Math::sin(degreesToRadians(yaw)) * Tyra::Math::cos(degreesToRadians(pitch));

    lookAt += position;
}