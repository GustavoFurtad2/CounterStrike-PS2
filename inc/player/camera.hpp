#pragma once

#include <tyra>

class Camera {

    public:

        Camera();
        ~Camera();

        Tyra::Vec4 lookAt, position, unitCircle;

        float circleRotation, circleLength, pitch, yaw, sensitivity;
        const float speed = 40.0f;

        bool getIsMoving() const {
            return isMoving;
        }

        Tyra::CameraInfo3D getCameraInfo() {
            return Tyra::CameraInfo3D(&position, &lookAt);
        }

        void update();

    private:

        bool isMoving = false;

        void rotate();
        void updatePosition();
        void updateLookAt();

        Tyra::Pad* pad;
};