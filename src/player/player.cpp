#include "player/player.hpp"

Player::Player(Tyra::Engine* t_engine) : hud(t_engine), camera(&t_engine->pad), usp(t_engine, "usp", 30, "assets/gameplay/guns/usp/usp.obj", "assets/gameplay/guns/usp/") {}

Player::~Player() {}

void Player::update() {

    camera.update();
}

void Player::drawHUD() {

    hud.draw(usp.getBulletsInGun(), usp.getBulletsPerCartridge(), usp.getCartridges());
}

void Player::drawGun() {

    usp.draw(Tyra::Vec4(getCameraInfo().position->x - 125.0f, getCameraInfo().position->y - 25.0f, getCameraInfo().position->z - 100.0f, 1));
}