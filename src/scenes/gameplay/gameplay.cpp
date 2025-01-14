#include "scenes/gameplay/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine)
  : engine(t_engine),
    player(t_engine),
    map(t_engine, "assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 200.0f) {}
    
Gameplay::~Gameplay() {}

void Gameplay::init() {

    engine->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    auto& renderer = engine->renderer;

    renderer.beginFrame(player.getCameraInfo());

    player.update();

    map.draw();

    player.drawGun();
    player.drawHUD();

    renderer.endFrame();
}