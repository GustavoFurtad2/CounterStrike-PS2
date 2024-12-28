#pragma once

#include <tyra>

#include "utils/image.hpp"

namespace Cs {

    class Game : public Tyra::Game {

        public:
    
            Game(Tyra::Engine* engine);
            ~Game();

            void init();
            void loop();

        private:

            Tyra::Engine* engine;

    };

}
