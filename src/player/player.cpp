#include "player/player.hpp"
#include "utils.hpp"

Player::Player(Tyra::Engine* t_engine, std::unique_ptr<HUD> _hud, std::unique_ptr<Gun> _usp, std::unique_ptr<Gun> _ak47) 
  : engine(t_engine),
    camera(&t_engine->pad),
    hud(std::move(_hud)), 
    usp(std::move(_usp)),
    ak47(std::move(_ak47)) {

    usp->isShootable = false;
    equippedGun = usp.get();

}

Player::~Player() {

    delete equippedGun;
}

void Player::update() {

    camera.update();

    if (engine->pad.getPressed().Triangle && !equippedGun->getIsShooting() && !holdingTriangle) {

        currentGunIndex += 1;

        if (currentGunIndex > static_cast<int>(gunType::TotalGunTypeItems) - 1) {
            currentGunIndex = 0;
        }

        holdingTriangle = true;
    }
    else if (!engine->pad.getPressed().Triangle) {
        
        holdingTriangle = false;
    }

}

void Player::renderHUD() {

    hud->render(equippedGun->getBulletsInGun(), equippedGun->getBulletsPerCartridge(), equippedGun->getCartridges());
}

void Player::renderGun() {

    equippedGun->update(camera);

    if (currentGunIndex == static_cast<int>(gunType::Usp)) {
        equippedGun = usp.get();
    }
    else if (currentGunIndex == static_cast<int>(gunType::Ak47)) {
        equippedGun = ak47.get();
    }

    equippedGun->render(camera, Tyra::Vec4(80.0f, 45.0f, 30.0f), Tyra::Vec4(Cs::Utils::degreesToRadians(90), 0.0f, 0.0f));
}