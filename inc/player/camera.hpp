#pragma once

#include <tyra>

#include "utils.hpp"

class Camera {

    public:

        Camera(Tyra::Pad* pad);
        ~Camera();

        Tyra::Vec4 lookAt, position, unitCircle;

        float circleRotation, circleLength, pitch, yaw, sensitivity;

        Tyra::CameraInfo3D getCameraInfo() {
            return Tyra::CameraInfo3D(&position, &lookAt);
        }

        void update();

    private:

        float speed = 40.0f;

        void rotate();
        void updatePosition();
        void updateLookAt();

        Tyra::Pad* pad;
};