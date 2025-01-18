#pragma once

#include <tyra>

class Image {

    public:

        Image(Tyra::Engine* t_engine, const char imagePath[], Tyra::Vec2 position, Tyra::Vec2 size);
        ~Image();

        void render();
        void render(Tyra::Color color);

    private:

        Tyra::Engine* engine;
        Tyra::Sprite image;

};