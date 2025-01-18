#pragma once

#include <memory>
#include "scene.hpp"

class SceneManager {

    public:

        SceneManager() {}

        void setScene(std::unique_ptr<Scene> scene) {
            currentScene = std::move(scene);

            currentScene->init();
        }

        void handleScene() {

            if (currentScene) {
                
                currentScene->update();
                currentScene->render();
            }
        }

    private:

        std::unique_ptr<Scene> currentScene;

};