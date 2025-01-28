#pragma once

#include <tyra>

#include "utils.hpp"

class Camera {

    public:

        Camera(Tyra::Pad* pad);
        ~Camera();

        Tyra::Vec4 lookAt;
        Tyra::Vec4 position;

        Tyra::Vec4 unitCircle;

        Tyra::CameraInfo3D getCameraInfo() {
            return Tyra::CameraInfo3D(&position, &lookAt);
        }

        void update();

    private:

        void rotate();
        void updatePosition();
        void updateLookAt();

        Tyra::Pad* pad;

        float circleRotation, circleLength, pitch, yaw, sensitivity;
};