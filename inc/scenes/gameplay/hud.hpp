#pragma once

#include <tyra>
#include <string>
#include <chrono>

#include "components/image.hpp"
#include "components/textureAtlas.hpp"

class HUD {

    public:

        HUD(Tyra::Engine* t_engine);
        ~HUD();

        void render(int bulletsGun, int bulletsPerCartridge, int cartridges);

    private:

        void displayNumber(unsigned int number, Tyra::Vec2 position, Tyra::Color color);

        void renderMoney();
        void renderTimer();
        void renderGunIcons();

        int money = 800;
        float health = 100;

        int remainMinutes = 5;
        int remainSeconds = 0;

        std::chrono::high_resolution_clock::time_point startTimer = std::chrono::high_resolution_clock::now();

        Tyra::Engine* engine;

        TextureAtlas hudAtlas;
        TextureAtlas gunIconAtlas1;
        TextureAtlas gunIconAtlas10;

        Tyra::Color gunIconColor = Tyra::Color(252, 140, 0, 48);

        Image radar;
    
};