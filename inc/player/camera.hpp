#pragma once

#include <tyra>

namespace Tyra {

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

            float getLookAtHeight() {

                return lookAtHeight;
            }

            void update();

        private:

            void updatePosition();
            void updateLookAt();

            Tyra::Pad* pad;
            float circleRotation, circleLength, speed, lookAtHeight;

    };
} 

