#include "game.hpp"
#include <string>

namespace Cs {

    static Tyra::Engine* engine;

    static SceneManager sceneManager;

    CSGame::CSGame(Tyra::Engine* t_engine) {
        engine = t_engine;
    }

    CSGame::~CSGame() {

        TYRA_LOG("Released: Game");
    }       

    void CSGame::init() {

        sceneManager.setScene(std::make_unique<Intro>(sceneManager));
    }

    void CSGame::loop() {

        sceneManager.handleScene();

        if (engine->pad.getClicked().Circle) {
            TYRA_LOG("RAM: " + std::to_string(engine->info.getAvailableRAM()));
        }
    }

    Tyra::Engine* GetEngine() {
        return engine;
    }

    void changeScene(std::unique_ptr<Scene>&& scene) {

        sceneManager.setScene(std::move(scene));
    }

}