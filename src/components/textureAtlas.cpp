#include "components/textureAtlas.hpp"

TextureAtlas::TextureAtlas(Tyra::Engine* t_engine, const char texturePath[], const char configPath[], Tyra::Vec2 size) : engine(t_engine) {

    std::ifstream configFile(configPath);

    if (!configFile) {

        TYRA_ERROR("Failed to load configuration file");
    }

    atlas.mode = Tyra::SpriteMode::MODE_STRETCH;
    atlas.position = Tyra::Vec2(0, 0);
    atlas.size = size;

    auto& textureRepository = engine->renderer.getTextureRepository();

    auto filepath = Tyra::FileUtils::fromCwd(texturePath);
    auto* texture = textureRepository.add(filepath);

    texture->addLink(atlas.id);

    std::string line;

    while (std::getline(configFile, line)) {

        std::string name, filename;

        int offsetX, offsetY, width, height;

        std::stringstream ss(line);

        ss >> name >> filename >> offsetX >> offsetY >> width >> height;

        Tyra::Sprite sprite;

        sprite.id = atlas.id;
        sprite.mode = Tyra::SpriteMode::MODE_REPEAT;
        sprite.size = Tyra::Vec2(width, height);
        sprite.offset = Tyra::Vec2(offsetX, offsetY);
        sprite.position = Tyra::Vec2(0, 0);

        sprites.emplace_back(sprite);
        spriteNames[name] = sprites.size() - 1;
    }
}

Tyra::Sprite* TextureAtlas::getSprite(const std::string& name) {

    if (spriteNames.find(name) != spriteNames.end()) {
        return &sprites[spriteNames[name]];
    }

    return nullptr;
}

void TextureAtlas::renderSprite(const std::string& name) {

    Tyra::Sprite* sprite = getSprite(name);

    if (sprite) {
        engine->renderer.renderer2D.render(*sprite);
    }
}
void TextureAtlas::renderSprite(const std::string& name, const Tyra::Color& color) {

    Tyra::Sprite* sprite = getSprite(name);

    if (sprite) {
        sprite->color = color;
        engine->renderer.renderer2D.render(*sprite);
    }
}

TextureAtlas::~TextureAtlas() {

    for (auto& sprite : sprites) {
        engine->renderer.getTextureRepository().freeBySprite(sprite);
    }

    engine->renderer.getTextureRepository().freeBySprite(atlas);

    TYRA_LOG("Release: Texture Atlas Component");
}
