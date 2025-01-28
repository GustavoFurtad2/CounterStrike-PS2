#include "player/player.hpp"

Player::Player(Tyra::Engine* t_engine) 
  : hud(t_engine),
    camera(&t_engine->pad), 
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
    }) {}
    // usp(t_engine, "usp", 30, "assets/gameplay/guns/usp/usp.obj", "assets/gameplay/guns/usp/") {}

Player::~Player() {

    
}

void Player::update() {

    camera.update();
}

void Player::renderHUD() {

    hud.render(ak47.getBulletsInGun(), ak47.getBulletsPerCartridge(), ak47.getCartridges());
}

void Player::renderGun() {

    ak47.render(camera, Tyra::Vec4(getCameraInfo().position->x - 37.0f, getCameraInfo().position->y - 4.0f, getCameraInfo().position->z - 100.0f, 1));
}