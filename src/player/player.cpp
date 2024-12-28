#include "player/player.hpp"

Player::Player(Tyra::Pad* t_pad) : camera(t_pad) {}

Player::~Player() {}

void Player::update() {

    camera.update();
}