#include "game.hpp"
#include <string>

namespace Cs {

    static Tyra::Engine* engine;

    static SceneManager sceneManager;
    static TextureManager* textureManager;
    static float dt = 1.0f / 60.0f;

    CSGame::CSGame(Tyra::Engine* t_engine) {
        engine = t_engine;
        textureManager = new TextureManager();
    }

    CSGame::~CSGame() {

        TYRA_LOG("Released: Game");
    }       

    void CSGame::init() {

        sceneManager.setScene(std::make_unique<Intro>(sceneManager));
    }

    void CSGame::loop() {

        float fps = static_cast<float>(engine->info.getFps());

        if (fps > 0.0f) {
            dt = 1.0f / fps;
        }

        sceneManager.handleScene();

        if (engine->pad.getClicked().Circle) {
            TYRA_LOG("RAM: " + std::to_string(engine->info.getAvailableRAM()));
        }
    }

    Tyra::Engine* GetEngine() {
        return engine;
    }

    TextureManager* GetTextureManager() {
        return textureManager;
    }

    float GetDeltaTime() {
        return dt;
    }

    void changeScene(std::unique_ptr<Scene>&& scene) {

        sceneManager.setScene(std::move(scene));
    }

}