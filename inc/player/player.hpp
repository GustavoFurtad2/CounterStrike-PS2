#pragma once

#include "player/item.hpp"
#include "player/camera.hpp"
#include "components/image.hpp"
#include "scenes/gameplay/hud.hpp"

enum class gunType {
    Usp,
    Ak47,
    TotalGunTypeItems
};

enum class PlayerState {
    SelectingTeam,
    Playing
};

class Player {

    public:

        Player(std::unique_ptr<HUD> _hud, std::unique_ptr<Gun> _usp, std::unique_ptr<Gun> _ak47);
        ~Player();

        void init();
        void update();
        void render();

        Tyra::CameraInfo3D getCameraInfo() {
            return camera.getCameraInfo();
        }

    private:

        PlayerState playerState = PlayerState::SelectingTeam;

        void renderHUD();
        void renderGun();

        std::unique_ptr<HUD> hud;

        std::unique_ptr<Gun> usp;
        std::unique_ptr<Gun> ak47;

        Image mid;
        Image csLogo;
        Image selectTeam;
        Image roundCornerTopLeft;
        Image roundCornerTopRight;
        Image roundCornerBottomLeft;
        Image roundCornerBottomRight;
        Image optionTerroristForces;

        Gun* equippedGun;

        int currentGunIndex = 1;

        bool holdingTriangle = false;

        Camera camera;

};