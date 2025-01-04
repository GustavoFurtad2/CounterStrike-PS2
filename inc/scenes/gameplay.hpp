#pragma once

#include <tyra>

#include "player/player.hpp"
#include "utils/staticModel.hpp"
#include "utils/textureAtlas.hpp"

class Gameplay {

    public:

        Gameplay(Tyra::Engine* t_engine);
        ~Gameplay();

        void init();
        void update();

    private:

        Tyra::Engine* engine;

        Player player;

        TextureAtlas hud7;

        Model map;
        Model usp;

};