#pragma once

#include <tyra>

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

class TextureAtlas {

    public:

        TextureAtlas(Tyra::Engine* t_engine, const char texturePath[], const char configPath[], Tyra::Vec2 size);
        ~TextureAtlas();

        Tyra::Sprite* getSprite(const std::string& name);

        void renderSprite(const std::string& name);
        void renderSprite(const std::string& name, const Tyra::Color& color);

    private:

        Tyra::Engine* engine;

        Tyra::Sprite atlas;

        std::vector<Tyra::Sprite> sprites;
        std::unordered_map<std::string, size_t> spriteNames;

};