#pragma once

#include <tyra>

#include "scene.hpp"
#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

namespace Cs {

    class Game : public Tyra::Game {

        public:
    
            Game(Tyra::Engine* engine);
            ~Game();

            void init();
            void loop();

        private:

            Tyra::Engine* engine;

            SceneManager sceneManager;

    };

}
