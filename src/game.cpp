#include "game.hpp"

#include "sceneManager.hpp"

namespace Game {

    using namespace Tyra;

    Game::Game(Engine* t_engine) : engine(t_engine) {}

    Game::~Game() {}

    void Game::init() {

        setScene(engine, SceneManager::Scene::MENU);
    }

    void Game::loop() {

        SceneManager::updateCurrentScene();
    }

}