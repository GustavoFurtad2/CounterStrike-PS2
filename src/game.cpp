#include "game.hpp"

#include "sceneManager.hpp"

namespace Cs {

    using namespace Tyra;

    Game::Game(Engine* t_engine) : engine(t_engine) {}

    Game::~Game() {}

    void Game::init() {

        setScene(engine, Cs::SceneManager::Scene::MENU);
    }

    void Game::loop() {

        Cs::SceneManager::updateCurrentScene();
    }

}