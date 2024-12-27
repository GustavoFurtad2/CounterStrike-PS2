#include "image.hpp"

Image::Image(Tyra::Engine* t_engine, const char path[], Tyra::Vec2 position, Tyra::Vec2 size) : engine(t_engine) {

    image.mode = Tyra::SpriteMode::MODE_STRETCH;

    image.position = position;
    image.size = size;

    auto& textureRepository = engine->renderer.getTextureRepository();

    auto filepath = Tyra::FileUtils::fromCwd(path);

    auto* texture = textureRepository.add(filepath);

    texture->addLink(image.id);

}

Image::~Image() {

    engine->renderer.getTextureRepository().freeBySprite(image);
}

void Image::draw() {

    engine->renderer.renderer2D.render(image);
}