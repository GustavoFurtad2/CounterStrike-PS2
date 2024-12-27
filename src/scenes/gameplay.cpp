#include "scenes/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine)
  : engine(t_engine) {}

Gameplay::~Gameplay() {}

void Gameplay::init() {

}

void Gameplay::loop() {

    auto& renderer = engine->renderer;

    renderer.beginFrame();


    renderer.endFrame();
}