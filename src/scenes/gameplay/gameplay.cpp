#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"
#include "game.hpp"

Gameplay::Gameplay(Cs::SceneManager& _sceneManager, std::unique_ptr<Player> _player, std::unique_ptr<Model> _map)
  : sceneManager(_sceneManager) {

    player = std::move(_player);
    map = std::move(_map);
}

Gameplay::~Gameplay() {

    TYRA_LOG("Release: Gameplay Scene");
}

void Gameplay::init() {

    player->init();
    Cs::GetEngine()->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    player->update();
}

void Gameplay::render() {

    auto& renderer = Cs::GetEngine()->renderer;

    renderer.beginFrame(player->getCameraInfo());

    map->render();

    player->renderGun();
    player->renderHUD();

    renderer.endFrame(); 
}