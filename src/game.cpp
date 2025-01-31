#include "game.hpp"

namespace Cs {

    using namespace Tyra;

    Game::Game(Engine* t_engine) : engine(t_engine), sceneManager() {

        sceneManager.setScene(std::make_unique<Gameplay>(t_engine, sceneManager));
    }

    Game::~Game() {

        TYRA_LOG("Released: Game");
    }       

    void Game::init() {

    }

    void Game::loop() {

        sceneManager.handleScene();
    }

}