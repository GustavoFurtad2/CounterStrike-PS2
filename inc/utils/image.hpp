#pragma once

#include <tyra>

class Image {

    public:

        Image(Tyra::Engine* t_engine, const char path[], Tyra::Vec2 position, Tyra::Vec2 size);
        ~Image();

        void draw();
        void draw(Tyra::Color color);

    private:

        Tyra::Engine* engine;

        Tyra::Sprite image;

};