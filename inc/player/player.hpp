#pragma once

#include <tyra>

#include "player/camera.hpp"

class Player {

    public:

        Player(Tyra::Pad* t_pad);
        ~Player();

        void update();

        Tyra::CameraInfo3D getCameraInfo() {
            return camera.getCameraInfo();
        }

    private:

        Tyra::Camera camera;

};