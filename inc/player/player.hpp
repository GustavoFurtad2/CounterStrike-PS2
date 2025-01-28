#pragma once

#include <tyra>

#include "player/item.hpp"
#include "player/camera.hpp"
#include "scenes/gameplay/hud.hpp"

class Player {

    public:

        Player(Tyra::Engine* t_engine);
        ~Player();

        void update();
        void renderHUD();
        void renderGun();

        Tyra::CameraInfo3D getCameraInfo() {
            return camera.getCameraInfo();
        }

    private:

        HUD hud;

        // Gun usp;
        Gun ak47;

        Tyra::Camera camera;

};