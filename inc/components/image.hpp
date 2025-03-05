#pragma once

#include <tyra>

class Image {

    public:

        Image();
        ~Image();

        void init(const char imagePath[], Tyra::Vec2 position, Tyra::Vec2 size);
        void render();
        void render(Tyra::Color color);
        void render(Tyra::Vec2 position, Tyra::Vec2 size);
        void render(Tyra::Color color, Tyra::Vec2 position, Tyra::Vec2 size);

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

        Tyra::Sprite image;

};