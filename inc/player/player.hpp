#pragma once

#include <tyra>

#include "utils.hpp"
#include "player/item.hpp"
#include "player/camera.hpp"
#include "scenes/gameplay/hud.hpp"

enum class gunType {
    Usp,
    Ak47,
    TotalGunTypeItems
};

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

        Tyra::Engine* engine;

        HUD hud;

        Gun usp;
        Gun ak47;
        Gun *equippedGun;

        int currentGunIndex = 0;

        bool holdingTriangle = false;

        Camera camera;

};