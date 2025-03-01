#include "player/player.hpp"
#include "utils.hpp"

Player::Player(Tyra::Engine* t_engine) 
  : hud(t_engine),
    engine(t_engine),
    camera(&t_engine->pad), 
    usp(t_engine, "usp", 30, {
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/left_arm.md2", "assets/gameplay/guns/usp/", 50.0f),        
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/left_finger.md2", "assets/gameplay/guns/usp/", 50.0f),  
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/left_glove.md2", "assets/gameplay/guns/usp/", 50.0f),    
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/right_arm.md2", "assets/gameplay/guns/usp/", 50.0f),      
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/right_finger.md2", "assets/gameplay/guns/usp/", 50.0f),
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/right_glove.md2", "assets/gameplay/guns/usp/", 50.0f),
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/slide.md2", "assets/gameplay/guns/usp/", 50.0f),    
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/handle.md2", "assets/gameplay/guns/usp/", 50.0f),      
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/magazine.md2", "assets/gameplay/guns/usp/", 50.0f),
        new AnimatedModel(t_engine, "assets/gameplay/guns/usp/silencer.md2", "assets/gameplay/guns/usp/", 50.0f),
    }),
    ak47(t_engine, "ak47", 30, {
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/left_arm.md2", "assets/gameplay/guns/ak47/", 50.0f),        
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/left_finger.md2", "assets/gameplay/guns/ak47/", 50.0f),  
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/left_glove.md2", "assets/gameplay/guns/ak47/", 50.0f),    
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/right_arm.md2", "assets/gameplay/guns/ak47/", 50.0f),      
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/right_finger.md2", "assets/gameplay/guns/ak47/", 50.0f),
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/right_glove.md2", "assets/gameplay/guns/ak47/", 50.0f),  
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/wood.md2", "assets/gameplay/guns/ak47/", 50.0f),               
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/lower_body.md2", "assets/gameplay/guns/ak47/", 50.0f),    
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/forearm.md2", "assets/gameplay/guns/ak47/", 50.0f),         
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/barrel.md2", "assets/gameplay/guns/ak47/", 50.0f),           
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/upper_body.md2", "assets/gameplay/guns/ak47/", 50.0f),    
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/reticle.md2", "assets/gameplay/guns/ak47/", 50.0f),         
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/handle.md2", "assets/gameplay/guns/ak47/", 50.0f),           
        new AnimatedModel(t_engine, "assets/gameplay/guns/ak47/magazine.md2", "assets/gameplay/guns/ak47/", 50.0f)
    }) {

    usp.isShootable = false;
    equippedGun = &usp;

}

Player::~Player() {
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

    hud.render(equippedGun->getBulletsInGun(), equippedGun->getBulletsPerCartridge(), equippedGun->getCartridges());
}

void Player::renderGun() {

    equippedGun->update(camera);

    if (currentGunIndex == static_cast<int>(gunType::Usp)) {
        equippedGun = &usp;
    }
    else if (currentGunIndex == static_cast<int>(gunType::Ak47)) {
        equippedGun = &ak47;
    }

    equippedGun->render(camera, Tyra::Vec4(80.0f, 45.0f, 30.0f), Tyra::Vec4(Cs::Utils::degreesToRadians(90), 0.0f, 0.0f));
}