#include "scenes/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine)
  : engine(t_engine),
    player(&t_engine->pad) {}

Gameplay::~Gameplay() {}

void Gameplay::init() {

}

void Gameplay::update() {

    auto& renderer = engine->renderer;

    renderer.beginFrame();

    player.update();

    renderer.endFrame();
}