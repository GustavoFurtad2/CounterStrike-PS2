#pragma once

#include <tyra>

#include <string>
#include <fstream>
#include <sstream>

class TextureAtlas {

    public:

        TextureAtlas(Tyra::Engine* t_engine, const char texturePath[], const char configPath[], Tyra::Vec2 size);
        ~TextureAtlas();

        Tyra::Sprite* getSprite(size_t index);

        void drawSprite(size_t index, const Tyra::Color& color);

    private:

        Tyra::Engine* engine;

        Tyra::Sprite atlasTexture;

        std::vector<Tyra::Sprite> sprites;

};