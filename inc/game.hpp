#pragma once

#include <tyra>

#include "scene.hpp"
#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/intro/intro.hpp"
#include "scenes/gameplay/gameplay.hpp"

namespace Cs {

    class CSGame : public Tyra::Game {

        public:
    
            CSGame(Tyra::Engine* engine);
            ~CSGame();

            void init();
            void loop();

    };
    
    Tyra::Engine* GetEngine();

    void changeScene(std::unique_ptr<Scene> scene);

}
