#pragma once

#include <tyra>

#include "utils/staticModel.hpp"

class Gun {

    public:

        Gun(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[]);
        ~Gun();

        void draw(Tyra::Vec4 cameraPosition);

        int getBulletsInGun() {
            return bulletsGun;
        }

        int getBulletsPerCartridge() {
            return bulletsPerCartridge;
        }

        int getCartridges() {
            return cartridges;
        }

    private:

        Model gunModel;
    
        int bulletsGun = 12;
        int bulletsPerCartridge = 12;
        int cartridges = 2;

        Tyra::Engine* engine;


};