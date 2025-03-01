#pragma once

#include <tyra>

class Image {

    public:

        Image(Tyra::Engine* t_engine, const char imagePath[], Tyra::Vec2 position, Tyra::Vec2 size);
        ~Image();

        void render();
        void render(Tyra::Color color);

        void setPosition(Tyra::Vec2 position) {
            image.position = position;
        }
  
        void setSize(Tyra::Vec2 size) {
            image.size = size;
        }

        Tyra::Vec2 getPosition() {
            return image.position;
        }

        Tyra::Vec2 getSize() {
            return image.size;
        }

    private:

        Tyra::Engine* engine;
        Tyra::Sprite image;

};