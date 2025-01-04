#pragma once

#include <tyra>

#include <string>
#include <fstream>
#include <sstream>

class TextureAtlas {

    public:

        TextureAtlas(Tyra::Engine* t_engine, const char texturePath[], const char configPath[], Tyra::Vec2 size);
        ~TextureAtlas();

        void draw();

    private:

        Tyra::Engine* engine;

        Tyra::Sprite atlasTexture;

        std::vector<Tyra::Sprite> sprites;

};