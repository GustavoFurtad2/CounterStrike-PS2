#include "game.hpp"

namespace Game {

    using namespace Tyra;

    Game::Game(Engine* t_engine) {
        engine = t_engine;
    }

    Game::~Game() {}

    void Game::init() {
        TYRA_LOG("Hello world!");
    }

    void Game::loop() {
        TYRA_LOG("Testing!");
    }

}