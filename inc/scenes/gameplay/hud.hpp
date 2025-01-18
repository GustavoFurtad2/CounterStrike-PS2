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

        void transitionColor(Tyra::Color& currentColor, const Tyra::Color& targetColor, float speed);
        void renderMoney();
        void renderTimer();

        int money = 800;
        float health = 100;

        int remainMinutes = 5;
        int remainSeconds = 0;

        std::chrono::high_resolution_clock::time_point startTimer = std::chrono::high_resolution_clock::now();

        Tyra::Engine* engine;

        TextureAtlas hudAtlas;
        Image radar;
    
};