#pragma once

#include <tyra>

#include "scenes.hpp"

#include "scenes/menu.hpp"
#include "scenes/gameplay.hpp"

namespace SceneManager {

    Scene currentScene;

    std::unique_ptr<Menu> menu;
    std::unique_ptr<Gameplay> gameplay;


    void setScene(Tyra::Engine* engine, Scene newScene) {

        currentScene = newScene;

        switch (currentScene) {

            case Scene::MENU:

                if (!menu) {

                    menu = std::make_unique<Menu>(engine);
                    menu->init();
                    menu->loop();
                }
                
                break;
            case Scene::GAMEPLAY:

                if (!gameplay) {

                    gameplay = std::make_unique<Gameplay>(engine);
                    gameplay->init();
                    gameplay->loop();
                }
                
                break;
        };
    }

    void updateCurrentScene() {

        switch (currentScene) {

            case Scene::MENU:

                menu->loop();

                break;
            case Scene::GAMEPLAY:

                gameplay->loop();

                break;
        };
    }

}