#pragma once

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

        Player(Tyra::Engine* t_engine, std::unique_ptr<HUD> _hud, std::unique_ptr<Gun> _usp, std::unique_ptr<Gun> _ak47);
        ~Player();

        void update();
        void renderHUD();
        void renderGun();

        Tyra::CameraInfo3D getCameraInfo() {
            return camera.getCameraInfo();
        }

    private:

        Tyra::Engine* engine;

        std::unique_ptr<HUD> hud;

        std::unique_ptr<Gun> usp;
        std::unique_ptr<Gun> ak47;
       
        Gun* equippedGun;

        int currentGunIndex = 1;

        bool holdingTriangle = false;

        Camera camera;

};