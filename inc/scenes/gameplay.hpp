#pragma once

#include <tyra>

#include "player/player.hpp"

class Gameplay {

    public:

        Gameplay(Tyra::Engine* t_engine);
        ~Gameplay();

        void init();
        void update();

    private:

        Tyra::Engine* engine;

        Player player;

};