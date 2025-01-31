#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine, SceneManager& sm)
  : engine(t_engine),
    player(t_engine),
    sceneManager(sm),
    map(t_engine, "assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f) {}

Gameplay::~Gameplay() {

    TYRA_LOG("Release: Gameplay Scene");
}

void Gameplay::init() {

    engine->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    player.update();
}

void Gameplay::render() {

    auto& renderer = engine->renderer;

    renderer.beginFrame(player.getCameraInfo());

    map.render();

    player.renderGun();
    player.renderHUD();

    renderer.endFrame(); 
}