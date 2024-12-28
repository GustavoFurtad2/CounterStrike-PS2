#pragma once

#include <tyra>

#include "player/camera.hpp"

class Player {

    public:

        Player(Tyra::Pad* t_pad);
        ~Player();

        void update();

    private:

        Tyra::Camera camera;

};