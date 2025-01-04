#include "utils/textureAtlas.hpp"

TextureAtlas::TextureAtlas(Tyra::Engine* t_engine, const char texturePath[], const char configPath[], Tyra::Vec2 size) : engine(t_engine) {

    std::ifstream configFile(configPath);

    if (!configFile) {

        TYRA_ERROR("Failed to load configuration file");
    }

    atlasTexture.mode = Tyra::SpriteMode::MODE_STRETCH;
    atlasTexture.position = Tyra::Vec2(0, 0);
    atlasTexture.size = size;

    auto& textureRepository = engine->renderer.getTextureRepository();

    auto filepath = Tyra::FileUtils::fromCwd(texturePath);

    auto* texture = textureRepository.add(filepath);

    texture->addLink(atlasTexture.id);

    std::string line;

    int i = 0;

    while (std::getline(configFile, line)) {

        i++;

        std::string name, filename;

        int offsetX, offsetY, width, height;

        std::stringstream ss(line);

        ss >> name >> filename >> offsetX >> offsetY >> width >> height;

        Tyra::Sprite sprite;

        sprite.id = atlasTexture.id;
        sprite.mode = Tyra::SpriteMode::MODE_REPEAT;
        sprite.size = Tyra::Vec2(width, height);
        sprite.offset = Tyra::Vec2(offsetX, offsetY);
        sprite.position = Tyra::Vec2(0, 0);

        sprites.emplace_back(sprite);

        TYRA_LOG("FN: ", filename, " OX: ", offsetX, " OY: ", offsetY, " W: ", width, " H: ", height);
    }
}

TextureAtlas::~TextureAtlas() {

    engine->renderer.getTextureRepository().freeBySprite(atlasTexture);
}

void TextureAtlas::draw() {

    for (const auto& sprite : sprites) {
        engine->renderer.renderer2D.render(sprite);
    }
}