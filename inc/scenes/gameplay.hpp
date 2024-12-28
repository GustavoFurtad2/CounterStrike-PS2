#pragma once

#include <tyra>

#include "utils/model.hpp"
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

        Model map;
        Model usp;

};