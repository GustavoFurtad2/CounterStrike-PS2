#include "scenes/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine)
  : engine(t_engine),
    player(&t_engine->pad),
    map(t_engine, "assets/gameplay/maps/de_dust2/Dust2.obj", "assets/gameplay/maps/de_dust2/", 200.0f),
    usp(t_engine, "assets/gameplay/guns/usp/usp.obj", "assets/gameplay/guns/usp/", 10.0f),
    health(t_engine, "assets/gameplay/hud/textures/640hud7.png", "assets/gameplay/hud/config/hud.txt", Tyra::Vec2(256, 256)) {}

Gameplay::~Gameplay() {}

void Gameplay::init() {

    engine->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    auto& renderer = engine->renderer;

    renderer.beginFrame(player.getCameraInfo());

    player.update();

    map.draw();

    usp.setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 125, player.getCameraInfo().position->y - 25, player.getCameraInfo().position->z - 100, 1));

    usp.draw();

    health.draw();

    renderer.endFrame();
}