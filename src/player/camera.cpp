#include "player/camera.hpp"
#include "utils.hpp"
#include "game.hpp"

Camera::Camera()
  : lookAt(0.0f),
    position(-2767.37, 30.0f, -8166.36),
    pad(&Cs::GetEngine()->pad),
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

    // TYRA_LOG("X: " + std::to_string(position.x) + " Y: " + std::to_string(position.y) + " Z: " + std::to_string(position.z));
    // TYRA_LOG("RX: " + std::to_string(lookAt.x) + " RY: " + std::to_string(lookAt.y) + " RZ: " + std::to_string(lookAt.z));

}

void Camera::rotate() {

    if (cameraType != CameraType::FirstPerson) {
        return;
    }

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

    if (cameraType != CameraType::FirstPerson) {
        return;
    }

    const auto& leftJoy = pad->getLeftJoyPad();

    Tyra::Vec4 forward(
        Tyra::Math::cos(Cs::Utils::degreesToRadians(yaw)),
        0.0F,
        Tyra::Math::sin(Cs::Utils::degreesToRadians(yaw))
    );

    Tyra::Vec4 right(
        Tyra::Math::cos(Cs::Utils::degreesToRadians(yaw + 90.0F)),
        0.0F,
        Tyra::Math::sin(Cs::Utils::degreesToRadians(yaw + 90.0F))
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

    if (pad->getPressed().DpadUp) {
        position.y += 10.0f;
    }
    else if (pad->getPressed().DpadDown) {
        position.y -= 10.0f;
    }

    isMoving = leftJoy.v <= 100 || leftJoy.v >= 200 || leftJoy.h <= 100 || leftJoy.h >= 200;
}

void Camera::updateLookAt() {

    lookAt.x = Tyra::Math::cos(Cs::Utils::degreesToRadians(yaw)) * Tyra::Math::cos(Cs::Utils::degreesToRadians(pitch));
    lookAt.y = Tyra::Math::sin(Cs::Utils::degreesToRadians(pitch));
    lookAt.z = Tyra::Math::sin(Cs::Utils::degreesToRadians(yaw)) * Tyra::Math::cos(Cs::Utils::degreesToRadians(pitch));
    
    lookAt += position;
}
