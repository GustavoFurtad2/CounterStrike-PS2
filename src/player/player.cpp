#include "player/player.hpp"
#include "utils.hpp"
#include "game.hpp"

Player::Player(std::unique_ptr<HUD> _hud, std::unique_ptr<Gun> _usp, std::unique_ptr<Gun> _ak47) 
  : hud(std::move(_hud)), 
    usp(std::move(_usp)),
    ak47(std::move(_ak47)) {

    usp->isShootable = false;
    equippedGun = usp.get();

}

Player::~Player() {

    delete equippedGun;
}

void Player::init() {

    hud->init();
    usp->init("usp", 30, std::vector<AnimatedModel*>{
            new AnimatedModel("assets/gameplay/guns/usp/left_arm.md2", "assets/gameplay/guns/usp/", 50.0f),        
            new AnimatedModel("assets/gameplay/guns/usp/left_finger.md2", "assets/gameplay/guns/usp/", 50.0f),  
            new AnimatedModel("assets/gameplay/guns/usp/left_glove.md2", "assets/gameplay/guns/usp/", 50.0f),    
            new AnimatedModel("assets/gameplay/guns/usp/right_arm.md2", "assets/gameplay/guns/usp/", 50.0f),      
            new AnimatedModel("assets/gameplay/guns/usp/right_finger.md2", "assets/gameplay/guns/usp/", 50.0f),
            new AnimatedModel("assets/gameplay/guns/usp/right_glove.md2", "assets/gameplay/guns/usp/", 50.0f),
            new AnimatedModel("assets/gameplay/guns/usp/slide.md2", "assets/gameplay/guns/usp/", 50.0f),    
            new AnimatedModel("assets/gameplay/guns/usp/handle.md2", "assets/gameplay/guns/usp/", 50.0f),      
            new AnimatedModel("assets/gameplay/guns/usp/magazine.md2", "assets/gameplay/guns/usp/", 50.0f),
            new AnimatedModel("assets/gameplay/guns/usp/silencer.md2", "assets/gameplay/guns/usp/", 50.0f),
    });
    ak47->init("ak47", 30, std::vector<AnimatedModel*>{
            new AnimatedModel("assets/gameplay/guns/ak47/left_arm.md2", "assets/gameplay/guns/ak47/", 50.0f),        
            new AnimatedModel("assets/gameplay/guns/ak47/left_finger.md2", "assets/gameplay/guns/ak47/", 50.0f),  
            new AnimatedModel("assets/gameplay/guns/ak47/left_glove.md2", "assets/gameplay/guns/ak47/", 50.0f),    
            new AnimatedModel("assets/gameplay/guns/ak47/right_arm.md2", "assets/gameplay/guns/ak47/", 50.0f),      
            new AnimatedModel("assets/gameplay/guns/ak47/right_finger.md2", "assets/gameplay/guns/ak47/", 50.0f),
            new AnimatedModel("assets/gameplay/guns/ak47/right_glove.md2", "assets/gameplay/guns/ak47/", 50.0f),  
            new AnimatedModel("assets/gameplay/guns/ak47/wood.md2", "assets/gameplay/guns/ak47/", 50.0f),               
            new AnimatedModel("assets/gameplay/guns/ak47/lower_body.md2", "assets/gameplay/guns/ak47/", 50.0f),    
            new AnimatedModel("assets/gameplay/guns/ak47/forearm.md2", "assets/gameplay/guns/ak47/", 50.0f),         
            new AnimatedModel("assets/gameplay/guns/ak47/barrel.md2", "assets/gameplay/guns/ak47/", 50.0f),           
            new AnimatedModel("assets/gameplay/guns/ak47/upper_body.md2", "assets/gameplay/guns/ak47/", 50.0f),    
            new AnimatedModel("assets/gameplay/guns/ak47/reticle.md2", "assets/gameplay/guns/ak47/", 50.0f),         
            new AnimatedModel("assets/gameplay/guns/ak47/handle.md2", "assets/gameplay/guns/ak47/", 50.0f),           
            new AnimatedModel("assets/gameplay/guns/ak47/magazine.md2", "assets/gameplay/guns/ak47/", 50.0f)
    });
}

void Player::update() {

    camera.update();

    if (Cs::GetEngine()->pad.getPressed().Triangle && !equippedGun->getIsShooting() && !holdingTriangle) {

        currentGunIndex += 1;

        if (currentGunIndex > static_cast<int>(gunType::TotalGunTypeItems) - 1) {
            currentGunIndex = 0;
        }

        holdingTriangle = true;
    }
    else if (!Cs::GetEngine()->pad.getPressed().Triangle) {
        
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