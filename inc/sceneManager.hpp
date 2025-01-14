#pragma once

#include <tyra>

#include "scenes.hpp"

#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

namespace Cs::SceneManager {

    Scene currentScene;

    std::unique_ptr<Menu> menu;
    std::unique_ptr<Gameplay> gameplay;


    void setScene(Tyra::Engine* engine, Scene newScene) {

        currentScene = newScene;

        switch (currentScene) {

            case Scene::MENU:

                TYRA_LOG("MENUUUUUUUUUU");

                if (!menu) {

                    menu = std::make_unique<Menu>(engine);
                    menu->init();
                    menu->update();
                }
                
                break;
            case Scene::GAMEPLAY:

                TYRA_LOG("GAMPLAYUUUUUUUUUUUUUUU");

                if (!gameplay) {

                    gameplay = std::make_unique<Gameplay>(engine);
                    gameplay->init();
                    gameplay->update();
                }
                
                break;
        };
    }

    void updateCurrentScene() {

        switch (currentScene) {

            case Scene::MENU:

                menu->update();

                break;
            case Scene::GAMEPLAY:

                gameplay->update();

                break;
        };
    }

}