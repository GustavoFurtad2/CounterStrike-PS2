#pragma once

#include <tyra>

class Gameplay {

    public:

        Gameplay(Tyra::Engine* t_engine);
        ~Gameplay();

        void init();
        void loop();

    private:

        Tyra::Engine* engine;

};