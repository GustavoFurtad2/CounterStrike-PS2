#pragma once

#include <tyra>
#include <string>

enum class CameraType {
    FirstPerson,
    Static
};

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

        CameraType getCameraType() {
            return cameraType;
        }

        void setCameraType(CameraType _cameraType) {
            cameraType = _cameraType;
        }

    private:

        CameraType cameraType = CameraType::Static;

        bool isMoving = false;

        void rotate();
        void updatePosition();
        void updateLookAt();

        Tyra::Pad* pad;
};