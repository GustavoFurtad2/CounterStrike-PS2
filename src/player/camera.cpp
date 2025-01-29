#include "player/camera.hpp"

#include <algorithm>

Camera::Camera(Tyra::Pad* t_pad)
  : lookAt(0.0f),
    position(0.0f, 40.0f, 0.0f),
    pad(t_pad),
    circleRotation(0.0f),
    circleLength(30.0f),
    pitch(0.0f),
    yaw(270.0f),
    sensitivity(4.58425f) {}

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

    const auto& leftJoy = pad->getLeftJoyPad();

    Tyra::Vec4 forward(
        Tyra::Math::cos(degreesToRadians(yaw)),
        0.0F,
        Tyra::Math::sin(degreesToRadians(yaw))
    );

    Tyra::Vec4 right(
        Tyra::Math::cos(degreesToRadians(yaw + 90.0F)),
        0.0F,
        Tyra::Math::sin(degreesToRadians(yaw + 90.0F))
    );

    forward.normalize();
    right.normalize();

    if (leftJoy.v <= 100) {
        position += forward * speed;
    }
    else if (leftJoy.v >= 200) {
        position -= forward * speed;
    }

    if (leftJoy.h <= 100) {
        position -= right * speed;
    }
    else if (leftJoy.h >= 200) {
        position += right * speed;
    }

    position.y = 40.0F;
}

void Camera::updateLookAt() {

    lookAt.x = Tyra::Math::cos(degreesToRadians(yaw)) * Tyra::Math::cos(degreesToRadians(pitch));
    lookAt.y = Tyra::Math::sin(degreesToRadians(pitch));
    lookAt.z = Tyra::Math::sin(degreesToRadians(yaw)) * Tyra::Math::cos(degreesToRadians(pitch));
    
    lookAt += position;
}