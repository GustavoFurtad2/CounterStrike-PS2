#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine, Cs::SceneManager& _sceneManager, std::unique_ptr<Player> _player, std::unique_ptr<Model> _map)
  : engine(t_engine),
    player(std::move(_player)),
    sceneManager(_sceneManager),
    map(std::move(_map)) {}

Gameplay::~Gameplay() {

    TYRA_LOG("Release: Gameplay Scene");
}

void Gameplay::init() {

    engine->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    player->update();
}

void Gameplay::render() {

    auto& renderer = engine->renderer;

    renderer.beginFrame(player->getCameraInfo());

    map->render();

    player->renderGun();
    player->renderHUD();

    renderer.endFrame(); 
}