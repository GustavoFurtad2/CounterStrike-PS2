#pragma once

#include <tyra>

namespace Game {

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
